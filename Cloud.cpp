#include "stdafx.h"
#include "Cloud.h"

#include "ShapeGameManager.h"

#define NUM_BIG_CLOUD_IMAGES 3
#define NUM_LITTLE_CLOUD_IMAGES 2

Cloud::Cloud(bool bigCloud, Vector2 start) {
  _start = start;
  _startCam = theCamera.GetPosition();
  if (bigCloud) {
    _parallax = 0.3f;
  }
  else {
    _parallax = 0.7f;
  }

  int zoom = ((ShapeGameManager*)theWorld.GetGameManager())->WorldZoom;
  if (!bigCloud) {
    zoom /= 2;
  }
  SetSize(zoom, zoom / 2);

  if (bigCloud) {
    LoadSpriteFrames("Resources/Images/cloud16x8_01.png", GL_CLAMP, GL_NEAREST);
  }
  else {
    LoadSpriteFrames("Resources/Images/cloud8x4_01.png", GL_CLAMP, GL_NEAREST);
  }

  SetSpriteFrame(MathUtil::RandomInt(this->_spriteNumFrames));

  Tag("cloud");
  SetName("Cloud");

  theSwitchboard.SubscribeTo(this, "CameraChange");
}

void Cloud::ReceiveMessage(Message* m) {
  if (m->GetMessageName() == "CameraChange") {
    Vector2 camDiff = theCamera.GetPosition() - _startCam;
    SetPosition(_start + (camDiff * _parallax));
  }
}
