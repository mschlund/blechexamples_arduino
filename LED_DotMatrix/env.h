#ifndef ENV_H
#define ENV_H

#include "blech.h"
#include "LED_DotMatrix.h"

#define MILLIS_PER_TICK 10

#define CLOCK_PIN 12
#define CS_PIN 11
#define DATA_PIN 10


void write_msg_to_display(unsigned char msg[8]);
void clear_display();


#endif
