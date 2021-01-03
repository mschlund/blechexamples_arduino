extern "C" {
  #include "env.h"
  #include "Ultrasonic_Sensor.h"
}

#define TRIGGER_PIN 4
#define ECHO_PIN 5
#define LED_PIN 10

void setup()
{
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
  blc_blech_Ultrasonic_Sensor_init();
}

void activateLED(void) {
  digitalWrite(LED_PIN, HIGH);
}

void deactivateLED(void) {
  digitalWrite(LED_PIN, LOW);
}

void writeDist(blc_nat32 dist) {
  Serial.print(dist);
  Serial.print(" cm\n");
}

blc_nat32 getEchoDuration(void) {
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, LOW);
    return pulseIn(ECHO_PIN, HIGH);
}

void loop() 
{
  blc_blech_Ultrasonic_Sensor_tick();
  delay(MILLIS_PER_TICK);
}
