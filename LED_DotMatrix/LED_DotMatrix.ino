#include <Arduino.h>

extern "C" {
  #include "env.h"
  #include "MAX_72XX.h"
  #include "LED_DotMatrix.h"
  #include "input.h"
  #include "button.h"
}

void setup() {
  Serial.begin(9600);
 
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(CS_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);

  blc_blech_01LED_DotMatrix01_init();
  
  //wake up (optional?)
  write_data_to_reg(0x0C,0x01);

  // Normal operation (turn off display-test)
  write_data_to_reg(0x0F,0x00);

  // no decode mode
  write_data_to_reg(0x09,0x00);

  // display all "digits"(=rows)
  write_data_to_reg(0x0B,0x07);
}

void loop() {
  button_pressed = (digitalRead(BUTTON_PIN) == LOW);

  blc_blech_01LED_DotMatrix01_tick();
  delay(MILLIS_PER_TICK);
}

void write_data_to_reg(byte reg, byte data) {
  // make sure clock is 0
  digitalWrite(CLOCK_PIN, LOW);
  // wake-up peripheral,
  // see https://learn.sparkfun.com/tutorials/serial-peripheral-interface-spi, CS is "active low"
  digitalWrite(CS_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, reg);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data);
  digitalWrite(CS_PIN, HIGH);
}

void DEBUG(long x, int code) {
  Serial.println("code " + String(code) + ": " + String(x));
}