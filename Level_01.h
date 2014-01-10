#pragma once
#include "stdafx.h"
#include "SA_Screen.h"

#include "Shape.h"
#include "Snail.h"

class Level_01 : public SA_Screen {
public:
  Level_01();

  virtual void Start(float bgMusicVol=1.0f);
  virtual void Update(float dt);
  virtual void Render();

private:
  Shape* _blocky;
  float _cameraLockMin;
  float _cameraLockMax;
  float _cameraZoom;
  float _cameraY;

  // AngelSampleHandle _backgroundMusic;

  Snail* _snail;
  // git test test
  // git test line test line
  // git tag test
};
