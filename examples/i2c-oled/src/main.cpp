/*
 *  Example for ESP32 and monochrome OLEDs based on SH1106 driver.
 *
 * See:
 *   https://registry.platformio.org/libraries/aki237/Adafruit_ESP32_SH1106/examples
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>


// Declaration for an SH1106 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SH1106 oled(OLED_RESET);


void setup()
{
    // Initialize OLED display with I2C address 0x3C
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    oled.begin(SH1106_SWITCHCAPVCC, 0x3C);
    delay(1000);          // Wait for initializing
    oled.clearDisplay();  // Clear the buffer

    oled.setTextColor(WHITE);
    oled.setTextSize(2);  // 1 is default 6x8, 2 is 12x16, 3 is 18x24, etc
    oled.setCursor(5, 10);
    oled.println("OLED");
    oled.setTextSize(1);
    oled.setCursor(60, 16);
    oled.println("SH1106");
    oled.drawLine(0, 30, oled.width()-1, 30, WHITE);

    // Show the display buffer on the screen. You MUST call display()
    // after drawing commands to make them visible on screen!
    oled.display();
}


void loop()
{
    // Empty loop
}
