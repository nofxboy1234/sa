#include "stdafx.h"
#include "Snail.h"

// #include "ShapeGameManager.h"

// #include "FloatingBlock.h"
// #include "Inventory.h"


Snail::Snail(Vector2 startingPosition) {
  SetName("Snail");
  Tag("ground");

  SetPosition(startingPosition);

  _facingRight = true;

  // int zoom = ((ShapeGameManager*)theWorld.GetGameManager())->WorldZoom;
  // SetSize((float)(zoom) * 0.5f, (float)(zoom) * 0.5f);
  SetSize(10.0f, (10.0f * (31.0f / 54.0f) ) );

  // SetShapeType(PhysicsActor::SHAPETYPE_BOX);
  // SetDrawShape(ADS_Square);

  // SetColor(0.0f, 0.0f, 1.0f, 1.0f);
  SetColor(1.0f, 1.0f, 1.0f, 1.0f);

  // SetSprite("Resources/Images/snailWalk_01.png");
  LoadSpriteFrames("Resources/Images/snailWalk_001.png", GL_CLAMP, GL_NEAREST);
  // LoadSpriteFrames("Resources/Images/player_1/p1_01.png", GL_CLAMP, GL_NEAREST);
  // LoadSpriteFrames("Resources/Images/patch_01.png", GL_CLAMP, GL_NEAREST);
  // SetSpriteFrame(0);


  // SetSprite("Resources/Images/red_texture.png");

  SetDensity(2.0f);
  SetFriction(0.5f);
  SetRestitution(0.0f);
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

  sensorShape.SetAsBox(0.5f, ( (3.0f * (31.0f / 54.0f) - 0.5f) ), b2Vec2((GetSize().X * 0.5f), 0.0f), 0.0f);
  _rightSensor = GetBody()->CreateFixture(&sensorFixtureDef);
  _rightSensor->SetUserData(this);

  sensorShape.SetAsBox(0.5f, ( (3.0f * (31.0f / 54.0f) - 0.5f) ), b2Vec2(-(GetSize().X * 0.5f), 0.0f), 0.0f);
  _leftSensor = GetBody()->CreateFixture(&sensorFixtureDef);
  _leftSensor->SetUserData(this);


}

// void Snail::SetUp() {
  // theSwitchboard.SubscribeTo(this, "CollisionStartWith" + GetName());
  // theSwitchboard.SubscribeTo(this, "CollisionEndWith" + GetName());
  // theSwitchboard.SubscribeTo(this, "Jump");
  // theSwitchboard.SubscribeTo(this, "PowerUpDone");
// }

// void Snail::ReceiveMessage(Message* message) {
//   String messageName = message->GetMessageName();
//   // sysLog.Log("Snail::ReceiveMessage: " + messageName);

//   if ((messageName == "CollisionStartWith" + GetName()) || (messageName == "CollisionEndWith" + GetName())) {
//     TypedMessage<b2Contact*>* contactMessage = (TypedMessage<b2Contact*>*)message;
//     b2Contact* contact = contactMessage->GetValue();
//     PhysicsActor* other = NULL;
//     b2Fixture* fixture = NULL;
//     if (contact->GetFixtureA()->GetUserData() == this) {
//       // I hit something else
//       other = (PhysicsActor*)contact->GetFixtureB()->GetBody()->GetUserData();
//       fixture = contact->GetFixtureA();
//     }
//     else {
//       // Something else hit me
//       other = (PhysicsActor*)contact->GetFixtureA()->GetBody()->GetUserData();
//       fixture = contact->GetFixtureB();
//     }

//     if (other == NULL) {
//       return;
//     }

//     if (fixture == _footSensor) {
//       if (messageName == "CollisionStartWith" + GetName()) {
//         ProcessStompOn(other);
//       }
//       else {
//         ProcessUnStompFrom(other);
//       }
//     }

//     if (fixture == _headSensor) {
//       if (messageName == "CollisionStartWith" + GetName()) {
//         if (other->IsTagged("block")) {
//           if (theSound.IsPlaying(_jumpPlaying)) {
//             theSound.StopSound(_jumpPlaying);
//           }
//           ((FloatingBlock*)other)->Bonk();
//         }
//       }
//     }

//     if ( (messageName == "CollisionStartWith" + GetName()) && (other->IsTagged("powerup")) ) {
//       PowerMeUp();
//       other->Destroy();
//     }

//     // Add orb to inventory
//     if ( (messageName == "CollisionStartWith" + GetName()) && (other->IsTagged("orb")) ) {
//       collectOrb(other);
//       other->Destroy();
//     }
//   }
//   else if (messageName == "Jump") {
//     if (CanJump()) {
//       Jump();
//     }
//   }
//   else if (messageName == "PowerUpDone") {
//     // LoadSpriteFrames("Resources/Images/dudette_01.png", GL_CLAMP, GL_NEAREST);
//     // LoadSpriteFrames("Resources/Images/patch_powerup_01.png", GL_CLAMP, GL_NEAREST);
//     float poweredJumpHeight = theTuning.GetFloat("BlockyPoweredJumpHeight");
//     theTuning.SetFloat("BlockyJumpHeight", poweredJumpHeight);
//     // theWorld.SetBackgroundColor(Color::FromInts(0, 191, 255));
//     // SetColor(0.0f, 1.0f, 0.0f, 1.0f);
//     // theWorld.ResumePhysics();
//     _poweringUp = false;
//   }
// }


void Snail::Update(float dt) {

  PlaySpriteAnimation(0.1f, SAT_Loop, 0, 1);

  // int curFrame = GetSpriteFrame();
  // String s = "dt: " + FloatToString(dt) + " Snail curFrame: " + IntToString(curFrame);
  // sysLog.Log(s);

  bool playing = IsSpriteAnimPlaying();
  String p = "sprite anim playing: " + BoolToString(playing);
  sysLog.Log(p);

  // PhysicsActor::Update(dt);
  // after snail_test tag
  // snail_test2 tag
  // after snail_test2
}

void Snail::Render() {
  PhysicsActor::Render();
}

// void Snail::ProcessStompOn(PhysicsActor* other) {
//   // sysLog.Log("Snail::ProcessStompOn");
//   if (other->IsTagged("ground")) {
//     _onGround = true;
//   }
// }

// void Snail::ProcessUnStompFrom(PhysicsActor* other) {
//   // sysLog.Log("Snail::ProcessUnStompFrom");
//   if (other->IsTagged("ground")) {
//     _onGround = false;
//   }
// }

// void Snail::FlipLeft() {
//   SetUVs(Vector2(1.0f, 0.0f), Vector2(0.0f, 1.0f));
//   _facingRight = false;
// }

// void Snail::FlipRight() {
//   SetUVs(Vector2(0.0f, 0.0f), Vector2(1.0f, 1.0f));
//   _facingRight = true;
// }