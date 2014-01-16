#pragma once
#include "stdafx.h"

class SA_Screen : public Renderable {
public:
  SA_Screen() {};
  SA_Screen(const String& musicPath);
  virtual void Start(float bgMusicVol=1.0f);
  virtual void Stop();
  virtual void Update(float dt);
  virtual void Render();

  void removeUiElements();
  void stopMusic();

  // String* _imgPath;
  AngelSampleHandle _backgroundMusicSample;
  AngelSoundHandle _backgroundMusicSound;

protected:
  std::vector<Renderable*> _objects;
  std::vector<AngelUIHandle> _elements;
  String _bgMusicPath;

private:
};
