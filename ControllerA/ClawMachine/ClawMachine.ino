// Controller A

#include "Stepper.h"
#include "Joystick.h"
#include "COM.h"
#include "CncShield.h"

void setup()
{
  Serial.begin(9600);
  init_28byj_stepper();
  init_joystick();
  init_cnc_shield_pin();
  enable_cnc_shield();
  // TODO: disable cnc shield on start. only turn it on when a coin is detected and the game starts.
}

void loop()
{
  Direction dir = get_joystick_direction();
  if (dir != IDLE)
  {
    SendDirection(dir);
  }
}
