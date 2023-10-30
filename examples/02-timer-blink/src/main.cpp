// https://www.upesy.com/blogs/tutorials/timer-esp32-with-arduino-code
// https://iotespresso.com/timer-interrupts-with-esp32/
// https://espressif-docs.readthedocs-hosted.com/projects/arduino-esp32/en/latest/api/timer.html

#include <Arduino.h>

#define PIN_LED 2

hw_timer_t * timer = NULL;
volatile uint8_t led_state = 0;


void IRAM_ATTR timer_isr() {
    led_state = ! led_state;
    digitalWrite(PIN_LED, led_state);
}


void setup() {
    uint8_t timer_id = 0;
    uint16_t prescaler = 80;
    int threashold = 1000000;

    Serial.begin(115200);
    pinMode(PIN_LED, OUTPUT);

    timer = timerBegin(timer_id, prescaler, true);
    timerAttachInterrupt(timer, &timer_isr, true);
    timerAlarmWrite(timer, threashold, true);
    timerAlarmEnable(timer);
}


void loop() {
    // put your main code here to run repeatedly
}
