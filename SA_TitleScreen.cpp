#include "stdafx.h"
#include "SA_TitleScreen.h"

SA_TitleScreen::SA_TitleScreen(const String& imgPath, const String& musicPath) {
  _imgPath = imgPath;

  FullScreenActor* fsa = new FullScreenActor();
  fsa->SetSprite(_imgPath);
  theWorld.Add(fsa);
  _objects.push_back(fsa);

  _bgMusicPath = musicPath;
}

// AngelUIHandle StartScreen::_choiceBox = NULL;

// void ChoiceMade(int choice) {
//   // std::ostringstream ss;
//   // ss << choice;
//   // std::string s = "choice: " + ss.str();
//   // sysLog.Log(s);

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

void startButtonPressed() {

  theSwitchboard.Broadcast(new Message("start_SA"));
}

void exitButtonPressed() {

  theSwitchboard.Broadcast(new Message("exit_SA"));
}


void SA_TitleScreen::Start(float bgMusicVol) {

  _startButton = theUI.AddButton("Start", Vec2i(1280 / 2, 500), startButtonPressed, true);
  _elements.push_back(_startButton);

  _exitButton = theUI.AddButton("Exit", Vec2i(1280 / 2, 550), exitButtonPressed, true);
  _elements.push_back(_exitButton);

  SA_Screen::Start(bgMusicVol);
}


// void SA_TitleScreen::Stop() {
//   std::vector<Renderable*>::iterator it = _objects.begin();
//   while (_objects.end() != it) {
//     PhysicsActor* pa = dynamic_cast<PhysicsActor*> (*it);
//     if (pa != NULL) {
//       if (pa->GetBody() != NULL) {
//         pa->GetBody()->SetUserData(NULL);
//         theWorld.GetPhysicsWorld().DestroyBody(pa->GetBody());
//         pa->ResetBody();
//       }
//     }
//     (*it)->Destroy();
//     it++;
//   }
//   _objects.clear();
// }

// void SA_TitleScreen::Update(float dt) {}

// void SA_TitleScreen::Render() {}

// void SA_TitleScreen::removeUiElements() {
//   std::vector<AngelUIHandle>::iterator it = _elements.begin();
//   while (_elements.end() != it) {
//     theUI.RemoveUIElement(*it);
//     it++;
//   }
//   _elements.clear();
// }