extern "C" {
  #include "env.h"
  #include "Digital_Inputs_2.h"
}

#define LED_PIN 9
#define BUTTON_PIN 5

blc_bool buttonPressed = false;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  blc_blech_Digital_Inputs_2_init();
}

void activateLED(void) {
  digitalWrite(LED_PIN, HIGH);
}

void deactivateLED(void) {
  digitalWrite(LED_PIN, LOW);
}

void loop() 
{
  buttonPressed = (digitalRead(BUTTON_PIN) == LOW);
  blc_blech_Digital_Inputs_2_tick();
  delay(MILLIS_PER_TICK);
}
