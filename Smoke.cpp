#include "stdafx.h"
#include "Smoke.h"

Smoke::Smoke() {
  SetPosition(5.0f, 0.0f);
  SetMaxParticles(500); //The maximum number of particles this system will ever handle.
  SetColor(1.0f, 0.5f, 0.0f, 1.0f);  //Sets the initial color of the particles.
  SetEndColor(Color(1.0f, 0.5f, 0.0f, 0.0f)); //Our particles disappear over time
  //                  // Since the image file we'll be using already
  //                  // has a color, we set this to pure white.

  // SetSprite("Resources/Images/Test.png"); //The image file we want to use (otherwise
  //                       // it'll just be colored squares).
  SetParticlesPerSecond(200.0f); //Emission Rate
  SetParticleLifetime(2.0f); //How long each particles lasts before disappearing
  SetSpread(MathUtil::Pi); //The angle in radians at which particles will be emitted.
  SetSpread(MathUtil::ToRadians(85.0f)); //The angle in radians at which particles will be emitted.
  // SetEndScale(2.0f); //If you want the particles to change size over their lifetimes
  SetSpeedRange(3.0f, 4.0f); //The minimum and maximum range of speeds (so you can have
  //                  // some variation).
  SetGravity(Vector2(3.0f, 5.0f)); //You can pull the particles in a particular direction (default is
                   // downwards, so zero it out if you need to).
  SetSize(1.0f);

}
