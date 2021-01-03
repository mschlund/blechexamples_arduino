
extern "C" {
  #include "env.h"
  #include "passive_buzzer.h"
}

#define TONE_PIN 8
#define SWITCH_PIN 5

blc_bool switchActivated = false;

void tone(unsigned int frequency, unsigned long duration) {
  tone(TONE_PIN, frequency, duration);
}

void setup()
{
  pinMode(TONE_PIN, OUTPUT);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  digitalWrite(SWITCH_PIN, HIGH);
  Serial.begin(9600);

  blc_blech_passive_buzzer_init();
}

void loop() 
{
  switchActivated = (digitalRead(SWITCH_PIN) == LOW);
  blc_blech_passive_buzzer_tick();
  delay(MILLIS_PER_TICK);
}
