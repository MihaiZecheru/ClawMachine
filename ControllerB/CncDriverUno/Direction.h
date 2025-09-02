#ifndef DIRECTION_H
#define DIRECTION_H

enum Direction
{
  LEFT = 1,          // Left on the joystick
  RIGHT = 2,         // Right on the joystick
  FORWARD = 3,       // Forward on the joystick (joystick facing away from you)
  BACK = 4,          // Down on the joystick (joystick facing towards to)

  FORWARD_LEFT = 5,  // Up and left on the joystick at the same time
  FORWARD_RIGHT = 6, // Up and right on the joystick at the same time
  BACK_LEFT = 7,     // Down and left on the joystick at the same time
  BACK_RIGHT = 8,    // Down and right on the joystick at the same time
  IDLE = 9           // The joystick is currently in the neutral position
};

const char* directions[9] = {"Left", "Right", "Forward", "Back", "ForwardLeft", "ForwardRight", "BackLeft", "BackRight", "Idle"};

#endif