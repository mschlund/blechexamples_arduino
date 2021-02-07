#ifndef ENV_H
#define ENV_H

#include <Arduino.h>

#include "DHT11_MQTT.hpp"
#include "blech.hpp"

#define MILLIS_PER_TICK 10
#define SENSOR_PIN D2
#define LED_ONBOARD D4

blc_nat32 get_duration_of_high(void);
void activate_input(void);
void write_to_pin(blc_bool level);
void setup_wifi(void);

#endif
