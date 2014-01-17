#include "stdafx.h"
#include "SA_Screen.h"

// AngelUIHandle StartScreen::_choiceBox = NULL;

// void ChoiceMade(int choice) {
//   std::ostringstream ss;
//   ss << choice;
//   std::string s = "choice: " + ss.str();
//   sysLog.Log(s);

//   String out = "";
//   // After putting an ImagePanel with an image in it into the WindowControl,
//   // the button index starts at 1 for some reason...

//   if (choice == 0) {
//     theWorld.ResumeSimulation();
//   }
//   else if (choice == 1) {
//     theWorld.StopGame();
//   }
// }

// void ButtonPress() {

//   theSwitchboard.Broadcast(new Message("start_SA"));
//   // theWorld.ResumeSimulation();
//   // StringList labels;
//   // labels.push_back("Start Game");
//   // labels.push_back("Exit");

//   // StringList labels;
//   // labels.push_back("Option 1");
//   // labels.push_back("Option 2");
//   // labels.push_back("A longer option with more text");

//   // StartScreen::_choiceBox = theUI.ShowChoiceBox("Welcome to Shape Adventure", labels, ChoiceMade);
// }

SA_Screen::SA_Screen(const String& musicPath) {
  _bgMusicPath = musicPath;
}

void SA_Screen::Start(float bgMusicVol) {

  _backgroundMusicSample = theSound.LoadSample(_bgMusicPath, true);
  _backgroundMusicSound = theSound.PlaySound(_backgroundMusicSample, bgMusicVol, true);
}

void SA_Screen::Stop() {
  std::vector<Renderable*>::iterator it = _objects.begin();
  while (_objects.end() != it) {
    PhysicsActor* pa = dynamic_cast<PhysicsActor*> (*it);
    if (pa != NULL) {
      if (pa->GetBody() != NULL) {
        pa->GetBody()->SetUserData(NULL);
        theWorld.GetPhysicsWorld().DestroyBody(pa->GetBody());
        pa->ResetBody();
      }
    }
    (*it)->Destroy();
    it++;
  }
  _objects.clear();
}

void SA_Screen::Update(float dt) {
  Renderable::Update(dt);
}

void SA_Screen::Render() {
  Renderable::Render();
}

void SA_Screen::removeUiElements() {
  std::vector<AngelUIHandle>::iterator it = _elements.begin();
  while (_elements.end() != it) {
    theUI.RemoveUIElement(*it);
    it++;
  }
  _elements.clear();
}

void SA_Screen::stopMusic() {
  theSound.StopSound(_backgroundMusicSound);
}
