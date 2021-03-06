#pragma once
#include "stdafx.h"

class Snail : public PhysicsActor {

public:
  Snail(Vector2 startingPosition);

  // void SetUp();

  // virtual void Update(float dt);
  // virtual void Render();
  virtual void ReceiveMessage(Message* message);
  void SetUp();

private:
  // void ProcessStompOn(PhysicsActor* other);
  // void ProcessUnStompFrom(PhysicsActor* other);

  void FlipLeft();
  void FlipRight();

  void movement_01();
  bool _moveNow;

  bool _facingRight;
  b2Fixture* _footSensor;
  b2Fixture* _rightSensor;
  b2Fixture* _leftSensor;
  b2Fixture* _headSensor;

};
