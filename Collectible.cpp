#include "stdafx.h"
#include "Collectible.h"

// #include "ShapeGameManager.h"

Collectible::Collectible() {
  // int zoom = ((ShapeGameManager*)theWorld.GetGameManager())->WorldZoom * 0.75f;
  SetSize(1.0f);

  // LoadSpriteFrames("Resources/Images/bone_powerup_01.png", GL_CLAMP, GL_NEAREST);
  // PlaySpriteAnimation(0.15f, SAT_Loop, 0, 1);
  SetColor(1.0f, 0.0f, 1.0f, 1.0f);

  SetDensity(0.0f);
  SetFriction(0.0f);
  SetRestitution(0.0f);
  SetFixedRotation(true);
  SetShapeType(PhysicsActor::SHAPETYPE_CIRCLE);
  SetDrawShape(ADS_Circle);

  Tag("collectible");
}

void Collectible::Update(float dt) {
  PhysicsActor::Update(dt);
}
