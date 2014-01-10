
#include "stdafx.h"
#include "ShapeGameManager.h"


int main(int argc, char* argv[])
{
	// get things going
	//  optional parameters:
	//		int windowWidth			default: 1024
	//		int windowHeight		default: 768
	//		std::string windowName	default: "Angel Engine"
	//		bool antiAliasing		default: false
	//		bool fullScreen			default: false
	//		bool resizable			default: false

	// theWorld.Initialize(1024, 768, "Shape Adventure", false);
  theWorld.Initialize(1280, 720, "Shape Adventure", false);

  GridActor* bgGrid = new GridActor();
  bgGrid->SetMinCoord(Vector2(-150.0f, -150.0f));
  bgGrid->SetMaxCoord(Vector2(150.0f, 150.0f));

	// theWorld.Add(bgGrid, -1);

  // theWorld.SetBackgroundColor(Color::FromInts(0, 191, 255));
  // theWorld.SetBackgroundColor(Color::FromInts(0, 0, 0));

	//YOUR GAME SETUP CODE HERE
  theWorld.SetGameManager(new ShapeGameManager());

	// do all your setup first, because this function won't return until you're exiting
	theWorld.StartGame();

	// any cleanup can go here
	theWorld.Destroy();

	return 0;

}
