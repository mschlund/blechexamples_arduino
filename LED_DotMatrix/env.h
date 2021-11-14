#ifndef ENV_H
#define ENV_H

#include "blech.h"

#define MILLIS_PER_TICK 10

#define CLOCK_PIN 12
#define CS_PIN 11
#define DATA_PIN 10

void write_data_to_reg(unsigned char reg, unsigned char data);
void DEBUG(int x);

#endif
