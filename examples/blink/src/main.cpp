/*
 * Blink
 *
 * Turns on and off an LED and send a message to VS Code repeatedly.
 */

#include <Arduino.h>

// Set pin number of your LED
#define PIN_LED 2
#define PIN_LED_2 23
#define PIN_LED_3 22

// Put your setup code here, to run once
void setup()
{
    // Initialize LED digital pin as an output
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_LED_2, OUTPUT);
    pinMode(PIN_LED_3, OUTPUT);
    // Tur off the LED
    digitalWrite(PIN_LED, LOW);
    digitalWrite(PIN_LED_2, LOW);
    digitalWrite(PIN_LED_3, LOW);

    // Set the communication symbol rate
    Serial.begin(115200);
}

// Put your main code here, to run repeatedly
void loop()
{
    Serial.println("LED is on");  // Transmit string
    digitalWrite(PIN_LED, HIGH);  // Turn on the LED
    delay(250);                   // Wait for 250 ms
    digitalWrite(PIN_LED, LOW);   // Turn off the LED

    Serial.println("2nd LED is on");
    digitalWrite(PIN_LED_2, HIGH);
    delay(250);
    digitalWrite(PIN_LED_2, LOW);

    Serial.println("3rd LED is on");
    digitalWrite(PIN_LED_3, HIGH);
    delay(250);
    digitalWrite(PIN_LED_3, LOW);
}
