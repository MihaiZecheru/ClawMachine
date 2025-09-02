#include "Direction.h"
#include "COM.h"
#include "Nema17.h"

void setup()
{
  Serial.begin(9600);
  initialize_nema_motors();
}

// Note: positive is the clockwise direction. Negative is counter-clockwise
void loop()
{
  Direction dir = GetDirectionFromSerial();
  if (dir == IDLE) return;
  Serial.println(dir);

  if (dir == RIGHT)
  {
    MoveXpositive();
  }
  else if (dir == LEFT)
  {
    MoveXnegative();
  }
  else if (dir == FORWARD)
  {
    MoveZpositive();
  }
  else if (dir == BACK)
  {
    MoveZnegative();
  }
  else if (dir == FORWARD_LEFT)
  {
    MoveZpositive();
    MoveXnegative();
  }
  else if (dir == FORWARD_RIGHT)
  {
    MoveZpositive();
    MoveXpositive();
  }
  else if (dir == BACK_LEFT)
  {
    MoveZnegative();
    MoveXnegative();
  }
  else if (dir == BACK_RIGHT)
  {
    MoveZnegative();
    MoveXpositive();
  }
}
