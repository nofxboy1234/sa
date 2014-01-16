#pragma once
#include "stdafx.h"
#include "SA_Screen.h"

class SA_TitleScreen : public SA_Screen {
public:
  SA_TitleScreen(const String& imgPath, const String& musicPath);
  virtual void Start(float bgMusicVol=1.0f);


  // virtual void Stop();
  // virtual void Update(float dt);
  // virtual void Render();

  // void removeUiElements();

// protected:
  // std::vector<Renderable*> _objects;
  // std::vector<AngelUIHandle> _elements;

private:
  AngelUIHandle _startButton;
  AngelUIHandle _exitButton;

  String _imgPath;

};
