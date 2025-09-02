#ifndef COM_H
#define COM_H

#include "Direction.h"

Direction GetDirectionFromSerial()
{
  if (!Serial.available())
  {
    return IDLE;
  }

  // Get one byte
  return (Direction)Serial.read();
}

#endif