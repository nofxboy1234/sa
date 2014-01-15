#include "stdafx.h"
#include "ShapeGameManager.h"

// #include "FloatingBlock.h"
// #include "Cloud.h"
// #include "Cliff_Small.h"
// #include "Cliff_Large.h"
// #include "FloatingPlatform.h"
// #include "FinishLine.h"

// #include "PowerUp.h"
// #include "HUD.h"
// #include "Smoke.h"
// #include "Collectible.h"

#include "Level_01.h"
// #include "Inventory.h"

// #define NUM_CLOUDS 6

const int ShapeGameManager::WorldZoom = 4;
// AngelUIHandle ShapeGameManager::_choiceBox = NULL;
// AngelUIHandle ShapeGameManager::_startButton = NULL;
// StartScreen* ShapeGameManager::_startScreen = NULL;
// bool ShapeGameManager::_gameStarted = false;

// PowerUp* ShapeGameManager::pwrUp = NULL;

ShapeGameManager::ShapeGameManager() {
  // _gameStarted = false;

  theSwitchboard.SubscribeTo(this, "start_SA");
  theSwitchboard.SubscribeTo(this, "exit_SA");
  // theSwitchboard.SubscribeTo(this, "snail_StartMoving");

  SA_TitleScreen* titleScreen = new SA_TitleScreen();
  titleScreen->_imgPath = new String("Resources/Images/SA-01_720.png");
  titleScreen->_bgMusicPath = new String("Resources/Sounds/Circlerun_ZEQ2_Select_Your_Game_Mode.mp3");
  _screens.push_back(titleScreen);

  Level_01* level01 = new Level_01();
  level01->_bgMusicPath = new String("Resources/Sounds/TownTheme.mp3");
  _screens.push_back(level01);

  unsigned int startingIndex = 0;
  if (_screens.size() > startingIndex) {
    _screens[startingIndex]->Start();
    theWorld.Add(_screens[startingIndex]);
    _current = startingIndex;
  }
  else {
    _current = -1;
  }

  _debugDraw = false;
  theWorld.SetupPhysics(Vector2(0, -100.0f));
  theWorld.GetPhysicsWorld().SetDebugDraw(this);
  this->SetFlags(b2Draw::e_shapeBit);

  // _backgroundMusic = theSound.LoadSample("Resources/Sounds/8bitmelody.wav", true);
  // theSound.PlaySound(_backgroundMusic, 0.1f, true);
}

SA_Screen* ShapeGameManager::getCurrentScreen() {
  return _screens[_current];
}

void ShapeGameManager::Setup() {

}

void ShapeGameManager::ReceiveMessage(Message* message) {
  if (message->GetMessageName() == "start_SA") {
    sysLog.Log("ShapeGameManager::ReceiveMessage StartGame");
    start_SA();
  }
  else if (message->GetMessageName() == "exit_SA") {
    sysLog.Log("ShapeGameManager::ReceiveMessage ExitGame");
    exit_SA();
  }

  // if (message->GetMessageName() == "snail_StartMoving") {
  //   sysLog.Log("ShapeGameManager::ReceiveMessage snail_StartMoving");
  // }
}

void ShapeGameManager::start_SA() {
  _screens[_current]->Stop();
  _screens[_current]->stopMusic();
  _screens[_current]->removeUiElements();
  theWorld.Remove(_screens[_current]);
  _current = 1;
  _screens[_current]->Start(0.75f);
  theWorld.Add(_screens[_current]);
}

void ShapeGameManager::exit_SA() {
  theWorld.StopGame();
}

// void ShapeGameManager::ShowMenu() {
//   // theWorld.PauseSimulation();
//   _startScreen = new StartScreen();
//   theWorld.Add(_startScreen, 10);

// }

void ShapeGameManager::Update(float dt) {
  if (theInput.IsKeyDown(ANGEL_KEY_D)) {
    _debugDraw = true;
  }
  else {
    _debugDraw = false;
  }

  // float blockyX = _blocky->GetPosition().X;
  // if ( (blockyX > _cameraLockMin) && (blockyX < _cameraLockMax) ) {
  //   if (theCamera.GetLockedActor() != _blocky) {
  //     theCamera.LockTo(_blocky, true, false);
  //   }
  // }
  // else {
  //   if (theCamera.GetLockedActor() == _blocky) {
  //     theCamera.LockTo(NULL);

  //     float camWidth = _cameraLockMax - _cameraLockMin;
  //     float midX = _cameraLockMin + (camWidth * 0.5f);

  //     if (_blocky->GetPosition().X < midX) {

  //       theCamera.SetPosition(_cameraLockMin, _cameraY, _cameraZoom);
  //     }
  //     else {
  //       theCamera.SetPosition(_cameraLockMax, _cameraY, _cameraZoom);
  //     }
  //   }
  // }
}

void ShapeGameManager::Render() {
  if (_debugDraw) {
    theWorld.GetPhysicsWorld().DrawDebugData();
  }
}

// *********************************************************************************

void ShapeGameManager::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
  glColor4f(color.r, color.g, color.b,1);
  glVertexPointer(2, GL_FLOAT, 0, vertices);
  glDrawArrays(GL_LINE_LOOP, 0, vertexCount);
}

void ShapeGameManager::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
  glVertexPointer(2, GL_FLOAT, 0, vertices);

  glColor4f(color.r, color.g, color.b,0.5f);
  glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);

  glColor4f(color.r, color.g, color.b,1);
  glDrawArrays(GL_LINE_LOOP, 0, vertexCount);
}

void ShapeGameManager::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
{
  const float32 k_segments = 16.0f;
  const int vertexCount=16;
  const float32 k_increment = 2.0f * b2_pi / k_segments;
  float32 theta = 0.0f;

  GLfloat       glVertices[vertexCount*2];
  for (int32 i = 0; i < k_segments; ++i)
  {
    b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
    glVertices[i*2]=v.x;
    glVertices[i*2+1]=v.y;
    theta += k_increment;
  }

  glColor4f(color.r, color.g, color.b,1);
  glVertexPointer(2, GL_FLOAT, 0, glVertices);

  glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);
}

void ShapeGameManager::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
{
  const float32 k_segments = 16.0f;
  const int vertexCount=16;
  const float32 k_increment = 2.0f * b2_pi / k_segments;
  float32 theta = 0.0f;

  GLfloat       glVertices[vertexCount*2];
  for (int32 i = 0; i < k_segments; ++i)
  {
    b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
    glVertices[i*2]=v.x;
    glVertices[i*2+1]=v.y;
    theta += k_increment;
  }

  glColor4f(color.r, color.g, color.b,0.5f);
  glVertexPointer(2, GL_FLOAT, 0, glVertices);
  glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);
  glColor4f(color.r, color.g, color.b,1);
  glDrawArrays(GL_LINE_LOOP, 0, vertexCount);

  // Draw the axis line
  DrawSegment(center,center+radius*axis,color);
}

void ShapeGameManager::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
  glColor4f(color.r, color.g, color.b,1);
  GLfloat       glVertices[] = {
    p1.x,p1.y,p2.x,p2.y
  };
  glVertexPointer(2, GL_FLOAT, 0, glVertices);
  glDrawArrays(GL_LINES, 0, 2);
}

void ShapeGameManager::DrawTransform(const b2Transform& xf)
{

}

// void ShapeGameManager::SoundEnded(AngelSoundHandle sound) {

// }
