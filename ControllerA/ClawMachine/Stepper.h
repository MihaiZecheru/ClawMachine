#ifndef STEPPER_H
#define STEPPER_H

#include <Stepper.h>

#define STEPS_PER_REV 2048
#define IN1 10
#define IN2 11
#define IN3 12
#define IN4 13
#define MAX_SPEED 20
#define REVS_TO_OPEN_OR_CLOSE 10

Stepper myStepper(STEPS_PER_REV, IN1, IN3, IN2, IN4);

void init_28byj_stepper()
{
  myStepper.setSpeed(MAX_SPEED);
}

void open_claw()
{
  for (int i = 0; i < REVS_TO_OPEN_OR_CLOSE; i++)
  myStepper.step(STEPS_PER_REV);
}

void close_claw()
{
  for (int i = 0; i < REVS_TO_OPEN_OR_CLOSE; i++)
  myStepper.step(-STEPS_PER_REV);
}

#endif