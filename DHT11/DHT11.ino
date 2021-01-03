extern "C" {
  #include "env.h"
  #include "DHT11.h"
}

#define SENSOR_PIN 2

blc_nat32 get_duration_of_high(void) {
  return pulseIn(SENSOR_PIN, HIGH);
}

void activate_input(void) {
  pinMode(SENSOR_PIN, OUTPUT);
  digitalWrite(SENSOR_PIN, HIGH);
  pinMode(SENSOR_PIN, INPUT_PULLUP);
}

void write_to_pin(blc_bool level) {
  pinMode(SENSOR_PIN, OUTPUT);
  if(level)
    digitalWrite(SENSOR_PIN, HIGH);
  else
    digitalWrite(SENSOR_PIN, LOW);  
}

void interrupts_off(void) {
  noInterrupts();
}

void interrupts_on(void) {
  interrupts();
}

void print_conditions(blc_bits32 temperature, blc_bits32 humidity) {
  if(temperature == -1 || humidity == -1)
    Serial.println("Checksum error!");
  else {
    Serial.print("T=");
    Serial.print(temperature, DEC);
    Serial.print("°C, H=");
    Serial.print(humidity, DEC);
    Serial.print("%\n");
  }
}

void print_byte(unsigned long b) {
  for (int i=0; i<8; i++) {
    int x = b & (1 << i);
    Serial.print(x>>i, DEC);
    Serial.print(" ");
  }
}

void print_conditions_raw(blc_bits32 temperature, blc_bits32 humidity) {
    Serial.print("T=");
    print_byte(temperature);
    Serial.print(" °C, H=");
    print_byte(humidity);
    Serial.print("%\n");
}

void setup() {
  Serial.begin(9600);
  blc_blech_DHT11_init();
}

void loop() {
  blc_blech_DHT11_tick();
  delay(MILLIS_PER_TICK);
}