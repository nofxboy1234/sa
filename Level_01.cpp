#include "stdafx.h"
#include "Level_01.h"

#include "PowerUp.h"
#include "HUD.h"
#include "Smoke.h"
// #include "Collectible.h"

Level_01::Level_01() {
}

void Level_01::Start(float bgMusicVol) {
  // theWorld.SetBackgroundColor(Color::FromInts(0, 191, 255));
  Actor* background = new Actor();
  background->SetSize(307, 100);
  background->SetSprite("Resources/Images/SA_bg.png");
  // background->LoadSpriteFrames("Resources/Images/SA_bg/SA_bg_0001.png");
  // background->PlaySpriteAnimation( (1.0f / 12), SAT_PingPong, 1, 12);
  theWorld.Add(background, -1);

  _cameraLockMin = theTuning.GetFloat("CameraLockMin");
  _cameraLockMax = theTuning.GetFloat("CameraLockMax");
  _cameraZoom = 30.0f;
  _cameraY = 15.0f;

  theCamera.SetPosition(0.0f, _cameraY, _cameraZoom);

  theWorld.LoadLevel("my_level");

  Vector2 botLeft = theCamera.GetWorldMinVertex();
  Vector2 topRight = theCamera.GetWorldMaxVertex();
  float halfWidth = (topRight.X - botLeft.X) * 0.5f;

  PhysicsActor* leftBlocker = new PhysicsActor();
  leftBlocker->SetAlpha(0.0f);
  leftBlocker->SetSize(2.0f, 200.0f);
  leftBlocker->SetPosition((_cameraLockMin - halfWidth) - (leftBlocker->GetSize().X * 0.5f), 0.0f);
  leftBlocker->SetDensity(0.0f);
  leftBlocker->SetFriction(0.1f);
  leftBlocker->SetRestitution(0.0f);
  leftBlocker->InitPhysics();
  leftBlocker->SetName("LeftBlocker");
  theWorld.Add(leftBlocker);

  PhysicsActor* rightBlocker = new PhysicsActor();
  rightBlocker->SetAlpha(0.0f);
  rightBlocker->SetSize(2.0f, 200.0f);
  rightBlocker->SetPosition((_cameraLockMax + halfWidth) + (rightBlocker->GetSize().X * 0.5f), 0.0f);
  rightBlocker->SetDensity(0.0f);
  rightBlocker->SetFriction(0.1f);
  rightBlocker->SetRestitution(0.0f);
  rightBlocker->InitPhysics();
  rightBlocker->SetName("RightBlocker");
  theWorld.Add(rightBlocker);

  _blocky = new Shape(Vector2(-86.0f, -8.0f));
  theWorld.Add(_blocky, 2);
  _blocky->SetUp();

  // _snail = new Snail( Vector2(-130.0f, -8.0f) );
  // theWorld.Add(_snail, 2);

  PowerUp* pwrUp = new PowerUp();
  pwrUp->SetPosition(-5.0f, 1.5f);
  pwrUp->InitPhysics();
  theWorld.Add(pwrUp, 2);

  HUD* hud = new HUD();
  theWorld.Add(hud, 2);

  // Add fire and smoke
  Smoke* smoke_02 = new Smoke();
  smoke_02->SetPosition(-97.0f, 15.0f);
  smoke_02->SetColor(0.6f, 0.6f, 0.6f, 0.5f);
  smoke_02->SetEndColor(Color(0.6f, 0.6f, 0.6f, 0.0f));
  smoke_02->SetMaxParticles(350);
  smoke_02->SetParticleLifetime(2.5f);
  smoke_02->SetParticlesPerSecond(10.0f);
  theWorld.Add(smoke_02, -1);

  // Smoke* fire_01 = new Smoke();
  // theWorld.Add(fire_01, 2);

  // Smoke* fire_02 = new Smoke();
  // fire_02->SetColor(1.0f, 0.0f, 0.0f, 0.5f);
  // fire_02->SetEndColor(Color(1.0f, 0.0f, 0.0f, 0.0f));
  // fire_02->SetPosition(4.5f, 0.0f);
  // // fire_02->SetMaxParticles(250);
  // fire_02->SetSize(0.5f);
  // theWorld.Add(fire_02, 2);

  // // Add fire and smoke
  // Smoke* smoke_03 = new Smoke();
  // smoke_03->SetColor(0.3f, 0.3f, 0.3f, 0.5f);
  // smoke_03->SetEndColor(Color(0.3f, 0.3f, 0.3f, 0.0f));
  // smoke_03->SetPosition(6.0f, -2.0f);
  // smoke_03->SetMaxParticles(700);
  // smoke_03->SetParticleLifetime(2.5f);
  // smoke_03->MoveTo(Vector2(-1.0f, -2.0f), 0.0f);
  // smoke_03->SetRotation(270.0f);
  // smoke_03->SetParticlesPerSecond(100.0f);
  // theWorld.Add(smoke_03, 2);

  // Smoke* fire_03 = new Smoke();
  // fire_03->MoveTo(Vector2(-1.0f, -2.0f), 0.0f);
  // fire_03->SetRotation(270.0f);
  // fire_03->SetParticlesPerSecond(100.0f);
  // theWorld.Add(fire_03, 2);

  // Smoke* fire_04 = new Smoke();
  // fire_04->SetColor(1.0f, 0.0f, 0.0f, 0.5f);
  // fire_04->SetEndColor(Color(1.0f, 0.0f, 0.0f, 0.0f));
  // fire_04->SetPosition(4.5f, 0.0f);
  // // fire_04->SetMaxParticles(250);
  // fire_04->SetSize(0.5f);
  // fire_04->MoveTo(Vector2(-1.0f, -2.0f), 0.0f);
  // fire_04->SetRotation(270.0f);
  // fire_04->SetParticlesPerSecond(100.0f);
  // theWorld.Add(fire_04, 2);

  // // Add fire and smoke
  // Smoke* smoke_04 = new Smoke();
  // smoke_04->SetColor(0.3f, 0.3f, 0.3f, 0.5f);
  // smoke_04->SetEndColor(Color(0.3f, 0.3f, 0.3f, 0.0f));
  // smoke_04->SetPosition(6.0f, -2.0f);
  // smoke_04->SetMaxParticles(700);
  // smoke_04->SetParticleLifetime(2.5f);
  // smoke_04->MoveTo(Vector2(-2.0f, 3.0f), 0.0f);
  // smoke_04->SetRotation(180.0f);
  // smoke_04->SetParticlesPerSecond(100.0f);
  // theWorld.Add(smoke_04, 4);

  // Smoke* fire_05 = new Smoke();
  // fire_05->MoveTo(Vector2(-2.0f, 3.0f), 0.0f);
  // fire_05->SetRotation(180.0f);
  // fire_05->SetParticlesPerSecond(100.0f);
  // theWorld.Add(fire_05, 4);

  // Smoke* fire_06 = new Smoke();
  // fire_06->SetColor(1.0f, 0.0f, 0.0f, 0.5f);
  // fire_06->SetEndColor(Color(1.0f, 0.0f, 0.0f, 0.0f));
  // fire_06->SetPosition(4.5f, 0.0f);
  // // fire_06->SetMaxParticles(250);
  // fire_06->SetSize(0.5f);
  // fire_06->MoveTo(Vector2(-2.0f, 3.0f), 0.0f);
  // fire_06->SetRotation(180.0f);
  // fire_06->SetParticlesPerSecond(100.0f);
  // theWorld.Add(fire_06, 4);

  // Add ground
  PhysicsActor* ground = new PhysicsActor();
  ground->SetPosition(0.0f, -24.0f);
  ground->SetSize(600.0f, 30.0f);
  ground->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
  ground->SetDensity(0.0f);
  ground->SetFriction(0.1f);
  ground->SetRestitution(0.0f);
  ground->InitPhysics();
  ground->Tag("ground");
  ground->SetName("Ground");
  theWorld.Add(ground, 2);

  SA_Screen::Start(bgMusicVol);

}

void Level_01::Update(float dt) {
  float blockyX = _blocky->GetPosition().X;
  if ( (blockyX > _cameraLockMin) && (blockyX < _cameraLockMax) ) {
    if (theCamera.GetLockedActor() != _blocky) {
      theCamera.LockTo(_blocky, true, false);
    }
  }
  else {
    if (theCamera.GetLockedActor() == _blocky) {
      theCamera.LockTo(NULL);

      float camWidth = _cameraLockMax - _cameraLockMin;
      float midX = _cameraLockMin + (camWidth * 0.5f);

      if (_blocky->GetPosition().X < midX) {

        theCamera.SetPosition(_cameraLockMin, _cameraY, _cameraZoom);
      }
      else {
        theCamera.SetPosition(_cameraLockMax, _cameraY, _cameraZoom);
      }
    }
  }
}

void Level_01::Render() {}