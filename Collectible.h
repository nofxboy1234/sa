#pragma once
#include "stdafx.h"

class Collectible : public PhysicsActor {
public:
  Collectible();

  virtual void Update(float dt);

};
