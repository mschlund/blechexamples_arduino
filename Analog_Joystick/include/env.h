#ifndef ENV_H
#define ENV_H

#include "blech.h"

#define MILLIS_PER_TICK 1

#define CLOCK_PIN 12
#define CS_PIN 11
#define DATA_PIN 10

// Arduino pin numbers
#define SWITCH_PIN 2 // digital pin connected to switch output
#define X_PIN 1 // analog pin connected to X output
#define Y_PIN 0 // analog pin connected to Y output


void write_data_to_reg(unsigned char reg, unsigned char data);
void DEBUG(long x, int code);

int read_X();
int read_Y();

#endif
