#ifndef ENV_H
#define ENV_H

#include "blech.h"

#define MILLIS_PER_TICK 1

void activateLED(void);
void deactivateLED(void);
void writeDist(blc_nat32 dist);
blc_nat32 getEchoDuration(void);

#endif