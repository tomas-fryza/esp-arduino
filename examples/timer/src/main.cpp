/*
 * Timer ISR example
 *
 * See also:
 *   https://www.upesy.com/blogs/tutorials/timer-esp32-with-arduino-code
 *   https://iotespresso.com/timer-interrupts-with-esp32/
 *   https://espressif-docs.readthedocs-hosted.com/projects/arduino-esp32/en/latest/api/timer.html
 */

// Include the necessary libraries
#include <Arduino.h>

// Define the LED pin. Replace with the actual pin number where
// your LED is connected
#define PIN_LED 2

// Set the timer interval in milliseconds
const int timerInterval = 1000;  // 1000 milliseconds = 1 second

// Create an object for the timer
hw_timer_t *timer = NULL;

// Timer ISR (Interrupt Service Routine)
void IRAM_ATTR timer_isr()
{
    // Toggle the state of the LED
    digitalWrite(PIN_LED, !digitalRead(PIN_LED));
}

void setup()
{
    // Initialize the LED pin as an output
    pinMode(PIN_LED, OUTPUT);

    // Set communication speed between ESP and Serial monitor
    Serial.begin(115200);

    // Create a timer object: Timer 0, divider 80 (prescaler), count up mode
    timer = timerBegin(0, 80, true);
    // Attach the ISR
    timerAttachInterrupt(timer, &timer_isr, true);
    // Set the timer interval in microseconds
    timerAlarmWrite(timer, timerInterval * 1000, true);
    // Enable the timer
    timerAlarmEnable(timer);
}

void loop()
{
    // Your main code can run here without blocking the timer
    // ...
}
