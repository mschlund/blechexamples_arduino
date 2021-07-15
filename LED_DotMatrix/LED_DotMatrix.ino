#include <Arduino.h>

extern "C" {
  #include "env.h"
  #include "LED_DotMatrix.h"
}

void setup() {
  Serial.begin(9600);
  blc_blech_LED_DotMatrix_init();
}

void loop() {
  blc_blech_LED_DotMatrix_tick();
  delay(MILLIS_PER_TICK);
}