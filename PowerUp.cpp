#include "stdafx.h"
#include "PowerUp.h"

#include "ShapeGameManager.h"

PowerUp::PowerUp() {
  int zoom = ((ShapeGameManager*)theWorld.GetGameManager())->WorldZoom * 0.75f;
  SetSize(1.0f);

  // LoadSpriteFrames("Resources/Images/bone_powerup_01.png", GL_CLAMP, GL_NEAREST);
  // PlaySpriteAnimation(0.15f, SAT_Loop, 0, 1);
  SetColor(0.0f, 0.0f, 1.0f, 1.0f);

  SetDensity(0.0f);
  SetFriction(0.0f);
  SetRestitution(0.0f);
  SetFixedRotation(true);
  SetShapeType(PhysicsActor::SHAPETYPE_CIRCLE);
  SetDrawShape(ADS_Circle);

  Tag("powerup");
}

void PowerUp::Update(float dt) {
  // float vel = theTuning.GetFloat("BlockyMaxSpeed") * theTuning.GetFloat("PowerUpMovementMultiplier");

  // float velocityChange = vel - GetBody()->GetLinearVelocity().x;
  // float impulse = GetBody()->GetMass() * velocityChange;
  // ApplyLinearImpulse(Vector2(impulse, 0), Vector2());

  PhysicsActor::Update(dt);
}
