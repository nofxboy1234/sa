#include "stdafx.h"
#include "FloatingPlatform.h"

#include "ShapeGameManager.h"

FloatingPlatform::FloatingPlatform(Vector2 startingPosition) {
  int zoom = ((ShapeGameManager*)theWorld.GetGameManager())->WorldZoom * 2;
  SetSize(zoom * 1.5, zoom * 0.5);

  SetPosition(startingPosition);

  SetSprite("Resources/Images/sa_floating_platform.png");
  // SetUVs(Vector2(0.0f, 0.0f), Vector2(7.0f, 5.0f));

  SetDensity(0.0f);
  SetFriction(0.5f);
  SetRestitution(0.0f);
  SetShapeType(PhysicsActor::SHAPETYPE_BOX);
  SetColor(1.0f, 1.0f, 1.0f, 1.0f);

  InitPhysics();

  Tag("ground");
}
