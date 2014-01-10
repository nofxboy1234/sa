#include "stdafx.h"
#include "FinishLine.h"

#include "ShapeGameManager.h"

FinishLine::FinishLine(Vector2 startingPosition) {
  int zoom = ((ShapeGameManager*)theWorld.GetGameManager())->WorldZoom;
  SetSize(zoom * 1.75, zoom * 2);

  SetPosition(startingPosition);

  SetSprite("Resources/Images/sa_finish_line.png");
  // SetUVs(Vector2(0.0f, 0.0f), Vector2(7.0f, 5.0f));

  SetDensity(0.0f);
  SetFriction(0.5f);
  SetRestitution(0.0f);
  SetShapeType(PhysicsActor::SHAPETYPE_BOX);
  SetColor(1.0f, 1.0f, 1.0f, 1.0f);

  // InitPhysics();

  Tag("ground");
}
