#ifndef COM_H
#define COM_H

/**
 * Send joystick-direction data from Arduino A to Arduino B (the CNC Arduino)
 */
void SendDirection(Direction dir)
{
  Serial.write((uint8_t)dir);
}

#endif