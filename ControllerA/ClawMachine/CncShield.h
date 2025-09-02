#ifndef CNC_SHIELD_H
#define CNC_ShIELD_H

#define CNC_SHIELD_PIN 3

void init_cnc_shield_pin()
{
  pinMode(CNC_SHIELD_PIN, OUTPUT);
}

void enable_cnc_shield()
{
  // The EN pin is active-low
  digitalWrite(CNC_SHIELD_PIN, LOW);
}

void disable_cnc_shield()
{
  // The EN pin is active-low
  digitalWrite(CNC_SHIELD_PIN, HIGH);
}

#endif