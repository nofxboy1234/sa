#include "stdafx.h"
#include "FloatingBlock.h"

#include "ShapeGameManager.h"
#include "PowerUp.h"

FloatingBlock::FloatingBlock() {
  int zoom = ((ShapeGameManager*)theWorld.GetGameManager())->WorldZoom * 0.75f;
  SetSize(zoom);

  LoadSpriteFrames("Resources/Images/block_01.png", GL_CLAMP, GL_NEAREST);
  PlaySpriteAnimation(0.25f, SAT_Loop, 0, 1);

  SetDensity(0.0f);
  SetFriction(0.5f);
  SetRestitution(0.0f);
  SetShapeType(PhysicsActor::SHAPETYPE_BOX);
  SetColor(1.0f, 1.0f, 1.0f, 1.0f);

  _bonked = false;

  _bonkSound = theSound.LoadSample("Resources/Sounds/Bonk.wav", false);

  Tag("ground");
  Tag("block");
}

void FloatingBlock::Bonk() {
  if (!_bonked) {
    sysLog.Log("BONK!");
    _bonked = true;
    SetSpriteFrame(2);
    _spriteAnimType = SAT_None;

    theSound.PlaySound(_bonkSound);

    // PowerUp* pu = new PowerUp();
    // pu->SetPosition(GetPosition().X, GetPosition().Y + GetSize().Y);
    // pu->InitPhysics();
    // theWorld.Add(pu);
  }

}


