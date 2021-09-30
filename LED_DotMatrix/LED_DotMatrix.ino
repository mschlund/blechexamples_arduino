#include <Arduino.h>

extern "C" {
  #include "env.h"
  #include "LED_DotMatrix.h"
}

#define CLOCK_PIN 12
#define CS_PIN 11
#define DATA_PIN 10

byte zero[8] = {0x18, 0x24, 0x42, 0x42, 0x42, 0x42, 0x24, 0x18}; // 0
byte one[8]  = {0x18, 0x28, 0x48, 0x8, 0x8, 0x8, 0x8, 0x3e}; // 1
byte two[8]  = {0x1c, 0x24, 0x44, 0x8, 0x10, 0x20, 0x7c, 0x0}; // 2

void setup() {
  Serial.begin(9600);
 
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(CS_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);

  //blc_blech_LED_DotMatrix_init();
  
  //wake up (optional)
  writeDataToReg(0x0C,0x01);

  // no decode mode
  writeDataToReg(0x09,0x00);

  // display all "digits"(=rows)
  writeDataToReg(0x0B,0x07);

  clearDisplay();

  // lowest intensity
  setIntensity(0x00);
}

void loop() {
  //blc_blech_LED_DotMatrix_tick();
  delay(MILLIS_PER_TICK);
  writeMsg();
  delay(1000);
  clearDisplay();
  delay(1000);
}

// TODO: snake-case

void writeMsg() {
  for (byte row=1; row<9; row++) {
    writeRow(row, two[row-1]);
  }
}

void writeRow(byte row, byte state) {
  if(0 < row && row < 9) {
    writeDataToReg(row, state);
  }
}

void clearDisplay() {
  // register for first row is "1"
  for(int row=1; row<9; row++) {
    writeDataToReg(row, 0x00);
  }
}

void setIntensity(byte intensity) {
  writeDataToReg(0x0A, intensity);
}

void writeDataToReg(byte reg, byte data) {
  // make sure clock is 0
  digitalWrite(CLOCK_PIN, LOW);

  // wake-up peripheral,
  // see https://learn.sparkfun.com/tutorials/serial-peripheral-interface-spi, CS is "active low"
  digitalWrite(CS_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, reg);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data);
  digitalWrite(CS_PIN, HIGH);
}