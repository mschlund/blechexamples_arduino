#ifndef ENV_H
#define ENV_H

#include "blech.h"
#include "DHT11.h"

#define MILLIS_PER_TICK 10

void interrupts_off(void);
void interrupts_on(void);
blc_nat32 get_duration_of_high(void);
void activate_input(void);
void write_to_pin(blc_bool level);
void print_conditions_raw(blc_bits32 temperature, blc_bits32 humidity);
void print_conditions(blc_bits32 temperature, blc_bits32 humidity);

#endif
