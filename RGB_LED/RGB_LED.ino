
extern "C" {
    #include "env.h"
    #include "RGB_LED.h"
}

// Define Pins
#define BLUE 5
#define GREEN 4
#define RED 3

void setLight(const blc_nat8 blc_ledVal[3])
{
    analogWrite(RED, blc_ledVal[0]);
    analogWrite(GREEN, blc_ledVal[1]);
    analogWrite(BLUE, blc_ledVal[2]);
}

void setup()
{
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    Serial.begin(9600);
    blc_blech_RGB_LED_init();
}

// main loop
void loop()
{
    blc_blech_RGB_LED_tick();
    delay(MILLIS_PER_TICK);
}
