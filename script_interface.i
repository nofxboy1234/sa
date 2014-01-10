// This file is where you can declare your classes to be exposed to the
//  scripting layer. See the example in IntroGame for usage.

%module angel
%{
#include "../../../ClientGame/Collectible.h"
%}

class Collectible : public PhysicsActor {
public:
  Collectible();

  virtual void Update(float dt);

};
