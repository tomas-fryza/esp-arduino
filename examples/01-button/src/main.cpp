#include <Arduino.h>

#define PIN_LED 2
#define PIN_BTN 23


void setup() {
    // Put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_BTN, INPUT_PULLUP);
}


void loop() {
    if (digitalRead(PIN_BTN) == 0) {
        // Put your main code here, to run repeatedly:
        digitalWrite(PIN_LED, HIGH);
        Serial.println("LED is on");
        delay(1000);
        digitalWrite(PIN_LED, LOW);
        Serial.println("LED is off");
        delay(1000);
    }
}
