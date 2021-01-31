#ifndef ENV_H
#define ENV_H

#include "DHT11_MQTT.h"
#include "blech.h"

#define MILLIS_PER_TICK 10
#define SENSOR_PIN D2

blc_nat32 get_duration_of_high(void);
void activate_input(void);
void write_to_pin(blc_bool level);
void setup_wifi(void);

#endif
