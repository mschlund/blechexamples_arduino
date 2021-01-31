#include <Arduino.h>

#include "Utils.h"
#include "env.h"

blc_nat32 get_duration_of_high() { return pulseIn(SENSOR_PIN, HIGH); }

void activate_input(void) {
  pinMode(SENSOR_PIN, OUTPUT);
  digitalWrite(SENSOR_PIN, HIGH);
  pinMode(SENSOR_PIN, INPUT_PULLUP);
}

void write_to_pin(blc_bool level) {
  pinMode(SENSOR_PIN, OUTPUT);
  if (level) {
    digitalWrite(SENSOR_PIN, HIGH);
  } else {
    digitalWrite(SENSOR_PIN, LOW);
  }
}

void setup() {
  Serial.begin(9600);
  setup_wifi_and_mqtt();
  blc_blech_DHT11_MQTT_init();
}

void loop() {
  blc_blech_DHT11_MQTT_tick();
  delay(MILLIS_PER_TICK);
}