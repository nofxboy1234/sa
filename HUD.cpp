#include "stdafx.h"
#include "HUD.h"

HUD::HUD() {
  SetSize(200.0f, 50.0f);
  SetPosition( (0.0f + (200.0f / 2) + 5), (0.0f + (50.0f / 2) + 5) );
  SetColor(0.5, 0.5, 0.5, 0.5);

}

void HUD::Render() {
  // TextActor *t = new TextActor("Console", "0", TXT_Center);
  // Vector2 hud_text_pos = theTuning.GetVector("HUD_Text_Pos");
  // t->SetPosition(hud_text_pos);
  // theWorld.Add(t, 2);

  HUDActor::Render();
}
