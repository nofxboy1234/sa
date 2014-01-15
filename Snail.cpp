#include "stdafx.h"
#include "Snail.h"

// #include "ShapeGameManager.h"

// #include "FloatingBlock.h"
// #include "Inventory.h"


Snail::Snail(Vector2 startingPosition) {
  SetName("Snail");
  Tag("ground");
  moveNow = false;

  SetPosition(startingPosition);

  // int zoom = ((ShapeGameManager*)theWorld.GetGameManager())->WorldZoom;
  // SetSize((float)(zoom) * 0.5f, (float)(zoom) * 0.5f);
  SetSize(3.0f, (3.0f * (31.0f / 54.0f) ) );

  // SetShapeType(PhysicsActor::SHAPETYPE_BOX);
  // SetDrawShape(ADS_Square);

  // SetColor(0.0f, 0.0f, 1.0f, 1.0f);
  SetColor(1.0f, 1.0f, 1.0f, 1.0f);

  // SetSprite("Resources/Images/snailWalk_01.png");
  LoadSpriteFrames("Resources/Images/snailWalk_01.png", GL_CLAMP, GL_NEAREST);
  // LoadSpriteFrames("Resources/Images/player_1/p1_01.png", GL_CLAMP, GL_NEAREST);
  // LoadSpriteFrames("Resources/Images/patch_01.png", GL_CLAMP, GL_NEAREST);
  // SetSpriteFrame(0);

  PlaySpriteAnimation(1.0f, SAT_Loop, 0, 1);
  // SetSprite("Resources/Images/red_texture.png");

  // SetDensity(2.0f);
  // SetFriction(0.5f);
  // SetRestitution(0.0f);
  // SetFixedRotation(true);
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


  _facingRight = false;

  // movement_01();
  theSwitchboard.SubscribeTo(this, "snail_StartMoving");
  theSwitchboard.SubscribeTo(this, "Snail_MovementFinished");

  // theSwitchboard.Broadcast(new Message("snail_StartMoving"));
}

void Snail::movement_01() {
  sysLog.Log("Snail::movement_01()");
  // MoveTo(Vector2( (GetPosition().X - 15.0f), GetPosition().Y) , 3.0f, "Snail_MovementFinished");
  MoveTo(Vector2(0.0f, 0.0f) , 2.0f, "Snail_MovementFinished");
  ChangeSizeTo(10.0f, 10.0f);
}

void Snail::FlipLeft() {
  SetUVs(Vector2(0.0f, 0.0f), Vector2(1.0f, 1.0f));
  _facingRight = true;
}

void Snail::FlipRight() {
  SetUVs(Vector2(1.0f, 0.0f), Vector2(0.0f, 1.0f));
  _facingRight = false;
}

// void Snail::SetUp() {
  // theSwitchboard.SubscribeTo(this, "CollisionStartWith" + GetName());
  // theSwitchboard.SubscribeTo(this, "CollisionEndWith" + GetName());
  // theSwitchboard.SubscribeTo(this, "Jump");
  // theSwitchboard.SubscribeTo(this, "PowerUpDone");
// }

void Snail::ReceiveMessage(Message* message) {
  sysLog.Log("Snail::ReceiveMessage");
  if (message->GetMessageName() == "snail_StartMoving") {
    sysLog.Log("Snail::ReceiveMessage snail_StartMoving");
    // MoveTo(Vector2(5.0f, 0.0f) , 2.0f, "Snail_MovementFinished");
    moveNow = true;
  }
}


void Snail::Update(float dt) {

  // movement_01();
  if (moveNow) {
    float curPosX = GetPosition().X;
    float curPosY = GetPosition().Y;
    SetPosition(curPosX += 1, curPosY);
  }

  PhysicsActor::Update(dt);
}

// void Snail::Render() {
//   PhysicsActor::Render();
// }

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