#ifndef NEMA17_H
#define NEMA17_H

#include <Arduino.h>

// Note: positive is the clockwise direction. Negative is counter-clockwise
#define STEP_X_PIN 2
#define DIR_X_PIN 5
#define STEP_Y_PIN 3
#define DIR_Y_PIN 6
#define STEP_Z_PIN 4
#define DIR_Z_PIN 7
#define STEPS_IN_FULL_ROTATION 200 // Not used
#define STEPS_DELAY_US 500

void initialize_nema_motors()
{
  pinMode(STEP_X_PIN, OUTPUT);
  pinMode(DIR_X_PIN, OUTPUT);
  pinMode(STEP_Y_PIN, OUTPUT);
  pinMode(DIR_Y_PIN, OUTPUT);
  pinMode(STEP_Z_PIN, OUTPUT);
  pinMode(DIR_Z_PIN, OUTPUT);
}
/**
 * Move 1 step in the +x dir
 */
void MoveXpositive()
{
  digitalWrite(DIR_X_PIN, HIGH);
  digitalWrite(STEP_X_PIN, HIGH);
  delayMicroseconds(STEPS_DELAY_US);
  digitalWrite(STEP_X_PIN, LOW);
  delayMicroseconds(STEPS_DELAY_US);
}

/**
 * Move 1 step in the -x dir
 */
void MoveXnegative()
{
  digitalWrite(DIR_X_PIN, LOW);
  digitalWrite(STEP_X_PIN, HIGH);
  delayMicroseconds(STEPS_DELAY_US);
  digitalWrite(STEP_X_PIN, LOW);
  delayMicroseconds(STEPS_DELAY_US);
}

void MoveY_to_top()
{
  digitalWrite(DIR_Y_PIN, LOW);

  int steps_to_top = 1000;
  for (int x = 0; x < steps_to_top; x++)
  {
    digitalWrite(STEP_Y_PIN, HIGH);
    delayMicroseconds(STEPS_DELAY_US);
    digitalWrite(STEP_Y_PIN, LOW);
    delayMicroseconds(STEPS_DELAY_US);
  }
}

/**
 * Move the Y all the way to the bottom to initiate a grab
 */
void MoveY_to_bottom()
{
  digitalWrite(DIR_Y_PIN, HIGH);

  int steps_to_bottom = 1000;
  for (int x = 0; x < steps_to_bottom; x++)
  {
    digitalWrite(STEP_Y_PIN, HIGH);
    delayMicroseconds(STEPS_DELAY_US);
    digitalWrite(STEP_Y_PIN, LOW);
    delayMicroseconds(STEPS_DELAY_US);
  }
}

/**
 * Move 1 step in the +z dir
 */
void MoveZpositive()
{
  digitalWrite(DIR_Z_PIN, HIGH);
  digitalWrite(STEP_Z_PIN, HIGH);
  delayMicroseconds(STEPS_DELAY_US);
  digitalWrite(STEP_Z_PIN, LOW);
  delayMicroseconds(STEPS_DELAY_US);
}

/**
 * Move 1 step in the -z dir
 */
void MoveZnegative()
{
  digitalWrite(DIR_Z_PIN, LOW);
  digitalWrite(STEP_Z_PIN, HIGH);
  delayMicroseconds(STEPS_DELAY_US);
  digitalWrite(STEP_Z_PIN, LOW);
  delayMicroseconds(STEPS_DELAY_US);
}

#endif