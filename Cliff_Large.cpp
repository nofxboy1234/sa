#include "stdafx.h"
#include "Cliff_Large.h"

#include "ShapeGameManager.h"

Cliff_Large::Cliff_Large(Vector2 startingPosition) {
  int zoom = ((ShapeGameManager*)theWorld.GetGameManager())->WorldZoom * 3;
  SetSize(zoom * 2, zoom);

  SetPosition(startingPosition);

  // SetSprite("Resources/Images/sa_cliff_large.png");

  SetDensity(0.0f);
  SetFriction(0.5f);
  SetRestitution(0.0f);
  SetShapeType(PhysicsActor::SHAPETYPE_BOX);
  SetColor(1.0f, 1.0f, 0.5f, 1.0f);

  InitPhysics();

  Tag("ground");
}
