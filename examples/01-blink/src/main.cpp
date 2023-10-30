#include <Arduino.h>

#define PIN_LED 2
#define PIN_LED_2 23
#define PIN_LED_3 22


void setup() {
    // Put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_LED_2, OUTPUT);
    pinMode(PIN_LED_3, OUTPUT);

    digitalWrite(PIN_LED, LOW);
    digitalWrite(PIN_LED_2, LOW);
    digitalWrite(PIN_LED_3, LOW);
}


void loop() {
    // Put your main code here, to run repeatedly:
    Serial.println("1st LED is on");
    digitalWrite(PIN_LED, HIGH);
    delay(500);
    digitalWrite(PIN_LED, LOW);

    Serial.println("2nd LED is on");
    digitalWrite(PIN_LED_2, HIGH);
    delay(500);
    digitalWrite(PIN_LED_2, LOW);

    Serial.println("3rd LED is on");
    digitalWrite(PIN_LED_3, HIGH);
    delay(500);
    digitalWrite(PIN_LED_3, LOW);
}
