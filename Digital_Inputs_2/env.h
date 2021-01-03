#ifndef ENV_H
#define ENV_H

#include "blech.h"

#define MILLIS_PER_TICK 10

extern blc_bool buttonPressed;

void activateLED(void);
void deactivateLED(void);

#endif