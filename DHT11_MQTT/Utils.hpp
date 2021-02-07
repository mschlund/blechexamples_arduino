#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "env.hpp"
#include "blech.hpp"

void interrupts_off(void);
void interrupts_on(void);
void print_byte(unsigned long b);
void print_conditions(blc_bits32 temperature, blc_bits32 humidity);
void print_conditions_raw(blc_bits32 temperature, blc_bits32 humidity);
void publish_conditions(blc_bits32 temperature, blc_bits32 humidity);
void reconnect(void);
void setup_wifi_and_mqtt(void);
void client_loop(void);
blc_bool is_client_connected(void);
blc_bool connect(void);
void LED_on(void);
void LED_off(void);

#endif