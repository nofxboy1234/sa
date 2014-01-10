#pragma once
#include "stdafx.h"

#include "Shape.h"
// #include "PowerUp.h"
#include "SA_Screen.h"
#include "SA_TitleScreen.h"

#define XINPUT_GAMEPAD_DPAD_UP          0x00000001
#define XINPUT_GAMEPAD_DPAD_DOWN        0x00000002
#define XINPUT_GAMEPAD_DPAD_LEFT        0x00000004
#define XINPUT_GAMEPAD_DPAD_RIGHT       0x00000008
#define XINPUT_GAMEPAD_START            0x00000010
#define XINPUT_GAMEPAD_BACK             0x00000020
#define XINPUT_GAMEPAD_LEFT_THUMB       0x00000040
#define XINPUT_GAMEPAD_RIGHT_THUMB      0x00000080
#define XINPUT_GAMEPAD_LEFT_SHOULDER    0x0100
#define XINPUT_GAMEPAD_RIGHT_SHOULDER   0x0200
#define XINPUT_GAMEPAD_A                0x1000
#define XINPUT_GAMEPAD_B                0x2000
#define XINPUT_GAMEPAD_X                0x4000
#define XINPUT_GAMEPAD_Y                0x8000


class ShapeGameManager : public GameManager, b2Draw {
public:
  ShapeGameManager();

  static const int WorldZoom;

  virtual void Update(float dt);
  virtual void Render();
  virtual void ReceiveMessage(Message* message);
  void Setup();

  // void ShowMenu();
  void start_SA();
  void exit_SA();
  SA_Screen* getCurrentScreen();
  // static SA_Screen* _startScreen;
  // static bool _gameStarted;
  // static PowerUp* pwrUp;

  // virtual void SoundEnded(AngelSoundHandle sound);

  // b2Draw interface
  virtual void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
  virtual void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
  virtual void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
  virtual void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
  virtual void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
  virtual void DrawTransform(const b2Transform& xf);

private:
  bool _debugDraw;
  // AngelSampleHandle _backgroundMusic;
  std::vector<SA_Screen*> _screens;
  int _current;

  // Shape* _blocky;
  // float _cameraLockMin;
  // float _cameraLockMax;
  // float _cameraZoom;
  // float _cameraY;


};
