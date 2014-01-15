#include "stdafx.h"
#include "Shape.h"

#include "ShapeGameManager.h"

// #include "FloatingBlock.h"
// #include "Inventory.h"


Shape::Shape(Vector2 startingPosition) {
  SetName("Blocky");

  SetPosition(startingPosition);

  _jumpTimeout = -1.0f;
  _onGround = true;
  _facingRight = true;
  _poweringUp = false;

  int zoom = ((ShapeGameManager*)theWorld.GetGameManager())->WorldZoom;
  // SetSize((float)(zoom) * 0.5f, (float)(zoom) * 0.5f);
  SetSize(3.0f, ((3.0f * 1.1f) * (106.0f / 60.0f)) );
  // SetColor(0.0f, 0.0f, 1.0f, 1.0f);
  SetColor(1.0f, 1.0f, 1.0f, 1.0f);

  // LoadSpriteFrames("Resources/Images/player_1/p1_01.png", GL_CLAMP, GL_NEAREST);
  // LoadSpriteFrames("Resources/Images/shapey/Shapey_01.png", GL_CLAMP, GL_NEAREST);
  LoadSpriteFrames("Resources/Images/Sprite_shapeyV01/Untitled-3_frame_0.png", GL_CLAMP, GL_NEAREST);
  // LoadSpriteFrames("Resources/Images/patch_01.png", GL_CLAMP, GL_NEAREST);
  SetSpriteFrame(0);

  // SetSprite("Resources/Images/red_texture.png");

  SetDensity(2.0f);
  SetFriction(0.0f);
  SetRestitution(0.0f);
  // SetShapeType(PhysicsActor::SHAPETYPE_BOX);
  SetFixedRotation(true);
  InitPhysics();

  b2PolygonShape sensorShape;
  b2FixtureDef sensorFixtureDef;
  sensorFixtureDef.isSensor = true;
  sensorFixtureDef.shape = &sensorShape;

  sensorShape.SetAsBox((3.0f / 2), 0.5f, b2Vec2(0.0f, -(GetSize().Y * 0.5f)), 0.0f);
  _footSensor = GetBody()->CreateFixture(&sensorFixtureDef);
  _footSensor->SetUserData(this);

  sensorShape.SetAsBox((3.0f / 2), 0.5f, b2Vec2(0.0f, (GetSize().Y * 0.5f)), 0.0f);
  _headSensor = GetBody()->CreateFixture(&sensorFixtureDef);
  _headSensor->SetUserData(this);

  sensorShape.SetAsBox(0.5f, ((3.0f * 1.39f / 2) - 0.5f), b2Vec2((GetSize().X * 0.5f), 0.0f), 0.0f);
  _rightSensor = GetBody()->CreateFixture(&sensorFixtureDef);
  _rightSensor->SetUserData(this);

  sensorShape.SetAsBox(0.5f, ((3.0f * 1.39f / 2) - 0.5f), b2Vec2(-(GetSize().X * 0.5f), 0.0f), 0.0f);
  _leftSensor = GetBody()->CreateFixture(&sensorFixtureDef);
  _leftSensor->SetUserData(this);

  // SetDrawSize((float)zoom * 0.5f, (float)zoom * 0.5f);

  _jumpSound = theSound.LoadSample("Resources/Sounds/Jump.wav", false);
  _powerUpSound = theSound.LoadSample("Resources/Sounds/PowerUp.wav", false);
  _orbSound = theSound.LoadSample("Resources/Sounds/Picked_Coin_Echo.wav", false);
  // _bonkSound = theSound.LoadSample("Resources/Sounds/Bonk.wav", false);

  // Initialize inventory
  _inventory = new Inventory();

}

void Shape::SetUp() {
  theSwitchboard.SubscribeTo(this, "CollisionStartWith" + GetName());
  theSwitchboard.SubscribeTo(this, "CollisionEndWith" + GetName());
  theSwitchboard.SubscribeTo(this, "Jump");
  theSwitchboard.SubscribeTo(this, "PowerUpDone");
}

void Shape::ReceiveMessage(Message* message) {
  String messageName = message->GetMessageName();
  // sysLog.Log("Shape::ReceiveMessage: " + messageName);

  if ((messageName == "CollisionStartWith" + GetName()) || (messageName == "CollisionEndWith" + GetName())) {
    TypedMessage<b2Contact*>* contactMessage = (TypedMessage<b2Contact*>*)message;
    b2Contact* contact = contactMessage->GetValue();
    PhysicsActor* other = NULL;
    b2Fixture* fixture = NULL;
    if (contact->GetFixtureA()->GetUserData() == this) {
      // I hit something else
      other = (PhysicsActor*)contact->GetFixtureB()->GetBody()->GetUserData();
      fixture = contact->GetFixtureA();
    }
    else {
      // Something else hit me
      other = (PhysicsActor*)contact->GetFixtureA()->GetBody()->GetUserData();
      fixture = contact->GetFixtureB();
    }

    if (other == NULL) {
      return;
    }

    if (fixture == _footSensor) {
      if (messageName == "CollisionStartWith" + GetName()) {
        ProcessStompOn(other);
      }
      else {
        ProcessUnStompFrom(other);
      }
    }

    if (fixture == _headSensor) {
      if (messageName == "CollisionStartWith" + GetName()) {
        if (other->IsTagged("block")) {
          // if (theSound.IsPlaying(_jumpPlaying)) {
          //   theSound.StopSound(_jumpPlaying);
          // }
          // ((FloatingBlock*)other)->Bonk();
          // theSound.PlaySound(_bonkSound);

        }
      }
    }

    if ( (messageName == "CollisionStartWith" + GetName()) && (other->IsTagged("powerup")) ) {
      PowerMeUp();
      other->Destroy();
    }

    // Add orb to inventory
    if ( (messageName == "CollisionStartWith" + GetName()) && (other->IsTagged("orb")) ) {
      collectOrb(other);
      other->Destroy();
    }
  }
  else if (messageName == "Jump") {
    if (CanJump()) {
      Jump();
    }
  }
  else if (messageName == "PowerUpDone") {
    // LoadSpriteFrames("Resources/Images/dudette_01.png", GL_CLAMP, GL_NEAREST);
    // LoadSpriteFrames("Resources/Images/patch_powerup_01.png", GL_CLAMP, GL_NEAREST);
    float poweredJumpHeight = theTuning.GetFloat("BlockyPoweredJumpHeight");
    theTuning.SetFloat("BlockyJumpHeight", poweredJumpHeight);
    // theWorld.SetBackgroundColor(Color::FromInts(0, 191, 255));
    // SetColor(0.0f, 1.0f, 0.0f, 1.0f);
    // theWorld.ResumePhysics();
    _poweringUp = false;
  }
}


void Shape::Update(float dt) {
  if (_jumpTimeout > 0.0f) {
    _jumpTimeout -= dt;
  }

  b2Vec2 currentVelocity = GetBody()->GetLinearVelocity();

// #################
  if (! _onGround) {
    // SetSpriteFrame(12);
    SetSpriteFrame(39);
    _spriteFrameDelay = 0.0f;
  }
  else if (MathUtil::FuzzyEquals(currentVelocity.x, 0.0f)) {
    SetSpriteFrame(10);
    _spriteFrameDelay = 0.0f;
  }
  else {
    if (!IsSpriteAnimPlaying()) {
      // PlaySpriteAnimation(0.1f, SAT_Loop, 1, 11);
      PlaySpriteAnimation(0.02f, SAT_Loop, 10, 30);
    }
  }

  if ((currentVelocity.x < 0.0f) && _facingRight) {
    FlipLeft();
  }
  else if ((currentVelocity.x > 0.0f) && !_facingRight) {
    FlipRight();
  }
// #################

  if (_poweringUp) {
    return;
  }

  float maxVel = theTuning.GetFloat("BlockyMaxSpeed");

  float xVector = 0.0f;
  if (theController.IsConnected()) {
    bool dpad_left_down;
    bool dpad_right_down;
    dpad_left_down = theController.IsButtonDown(XINPUT_GAMEPAD_DPAD_LEFT);
    dpad_right_down = theController.IsButtonDown(XINPUT_GAMEPAD_DPAD_RIGHT);

    if (dpad_left_down) {
      xVector = -1.0f;
    }
    else if (dpad_right_down) {
      xVector = 1.0f;
    }
    else if (dpad_left_down && dpad_right_down) {
      xVector = 0.0f;
    }
    else {
      xVector = theController.GetLeftThumbVec2().X;
    }
  }

  if (theInput.IsKeyDown(ANGEL_KEY_RIGHTARROW)) {
    xVector = 1.0f;
  }
  if (theInput.IsKeyDown(ANGEL_KEY_LEFTARROW)) {
    xVector = -1.0f;
  }
  if (theInput.IsKeyDown(ANGEL_KEY_RIGHTARROW) && theInput.IsKeyDown(ANGEL_KEY_LEFTARROW)) {
    xVector = 0.0f;
  }

  float desiredVelocity = xVector * maxVel;
  float velocityChange = desiredVelocity - currentVelocity.x;
  float impulse = GetBody()->GetMass() * velocityChange;
  ApplyLinearImpulse(Vector2(impulse, 0), Vector2());

  PhysicsActor::Update(dt);
}

void Shape::Render() {
  PhysicsActor::Render();
}

bool Shape::CanJump() {
  if (_jumpTimeout > 0.0f) {
    return false;
  }
  if (!_onGround) {
    return false;
  }

  return true;
}

void Shape::Jump() {
  _jumpTimeout = theTuning.GetFloat("BlockyJumpTimeout");
  _onGround = false;
  GetBody()->SetLinearVelocity(b2Vec2(0.0f, theTuning.GetFloat("BlockyJumpHeight")));
  _jumpPlaying = theSound.PlaySound(_jumpSound, 1.0f);
}

void Shape::PowerMeUp() {
  sysLog.Log("Power UP!");

  // theWorld.PausePhysics();
  // theWorld.SetBackgroundColor(Color::FromInts(239, 255, 57));

  // theSwitchboard.DeferredBroadcast(new Message("PowerUpDone"), 2.0f);
  theSwitchboard.Broadcast(new Message("PowerUpDone"));
  _poweringUp = true;

  theSound.PlaySound(_powerUpSound, 1.0f);
}

void Shape::ProcessStompOn(PhysicsActor* other) {
  // sysLog.Log("Shape::ProcessStompOn");
  if (other->IsTagged("ground")) {
    _onGround = true;
  }
}

void Shape::ProcessUnStompFrom(PhysicsActor* other) {
  // sysLog.Log("Shape::ProcessUnStompFrom");
  if (other->IsTagged("ground")) {
    _onGround = false;
  }
}

void Shape::collectOrb(PhysicsActor* orb) {
  String orb_name = orb->GetName();
  sysLog.Log("Collected Orb: " + orb_name);
  _inventory->add_orb();

  int num_orbs = _inventory->total_orbs();

  String s = "Total orbs: " + IntToString(num_orbs);
  sysLog.Log(s);

  theSound.PlaySound(_orbSound, 1.0f);

  if (num_orbs == 6) {
    TextActor* t = new TextActor("Console", "You beat the game!", TXT_Center);
    Vector2 blocky_pos = GetPosition();
    t->SetPosition(blocky_pos.X, blocky_pos.Y + 5.0f);
    theWorld.Add(t, 2);
  }
}

void Shape::FlipLeft() {
  SetUVs(Vector2(1.0f, 0.0f), Vector2(0.0f, 1.0f));
  _facingRight = false;
}

void Shape::FlipRight() {
  SetUVs(Vector2(0.0f, 0.0f), Vector2(1.0f, 1.0f));
  _facingRight = true;
}