#include "stdafx.h"
#include "Cliff_Small.h"

#include "ShapeGameManager.h"

Cliff_Small::Cliff_Small(Vector2 startingPosition) {
  int zoom = ((ShapeGameManager*)theWorld.GetGameManager())->WorldZoom * 2;
  SetSize(zoom);

  SetPosition(startingPosition);

  // SetSprite("Resources/Images/sa_cliff_small.png");

  SetDensity(0.0f);
  SetFriction(0.5f);
  SetRestitution(0.0f);
  SetShapeType(PhysicsActor::SHAPETYPE_BOX);
  SetColor(1.0f, 1.0f, 0.5f, 1.0f);

  InitPhysics();

  Tag("ground");
}
