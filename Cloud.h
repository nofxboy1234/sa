#pragma once
#include "stdafx.h"

class Cloud : public Actor {
public:
  Cloud(bool bigCloud, Vector2 startX);

  virtual void ReceiveMessage(Message* m);

private:
  bool _isBig;
  Vector2 _startCam;
  Vector2 _start;
  float _parallax;
};
