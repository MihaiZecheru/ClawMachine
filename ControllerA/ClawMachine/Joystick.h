#ifndef JOYSTICK_H
#define JOYSTICK_H

#define JOYSTICK_LEFT 4
#define JOYSTICK_RIGHT 5
#define JOYSTICK_FORWARD 6
#define JOYSTICK_BACK 7

void init_joystick()
{
  pinMode(JOYSTICK_LEFT, INPUT_PULLUP);
  pinMode(JOYSTICK_RIGHT, INPUT_PULLUP);
  pinMode(JOYSTICK_FORWARD, INPUT_PULLUP);
  pinMode(JOYSTICK_BACK, INPUT_PULLUP);
}

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

/**
 * @returns The direction/position the joystick is in
 */
Direction get_joystick_direction()
{
  // Inverted because INPUT_PULLUP was used
  bool left = !digitalRead(JOYSTICK_LEFT);
  bool right = !digitalRead(JOYSTICK_RIGHT);
  bool forward = !digitalRead(JOYSTICK_FORWARD);
  bool back = !digitalRead(JOYSTICK_BACK);

  // Check the dual directions first
  if (forward  && left) return FORWARD_LEFT;
  else if (forward && right) return FORWARD_RIGHT;
  else if (back && left) return BACK_LEFT;
  else if (back && right) return BACK_RIGHT;
  // Single directions
  else if (left) return LEFT;
  else if (right) return RIGHT;
  else if (forward) return FORWARD;
  else if (back) return BACK;
  else return IDLE;
}

#endif