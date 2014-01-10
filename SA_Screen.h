#pragma once
#include "stdafx.h"

class SA_Screen : public Renderable {
public:
  SA_Screen();
  virtual void Start(float bgMusicVol=1.0f);
  virtual void Stop();
  virtual void Update(float dt);
  virtual void Render();

  void removeUiElements();
  void stopMusic();

  String* _imgPath;
  String* _bgMusicPath;
  AngelSampleHandle _backgroundMusicSample;
  AngelSoundHandle _backgroundMusicSound;

protected:
  std::vector<Renderable*> _objects;
  std::vector<AngelUIHandle> _elements;

private:
};
