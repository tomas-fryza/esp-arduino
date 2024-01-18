/*
 * Diagnostic test for the displayed colour order
 *
 * Written by Bodmer 17/2/19 for the TFT_eSPI library:
 *   https://github.com/Bodmer/TFT_eSPI
 * 
 * See other examples:
 *   https://registry.platformio.org/libraries/bodmer/TFT_eSPI/examples
 * 
 * 
 * !!! LILYGO T-Display board MUST be setup !!!
 * 
 * 1. Add to `platfomio.ini`
 * 
 * lib_deps = 
 *     bodmer/TFT_eSPI@^2.5.33
 * 
 * 2. Build the app with internet connection to download the library.
 * 
 * 3. Change the following settings in `.pio > libdeps/ttgo-t1 > TTF_eSPI > User-Setup.h`
 * 
 * // #define ILI9341_DRIVER       // line 45
 * #define ST7789_DRIVER           // line 55
 * 
 * #define TFT_WIDTH  135          // 84
 * #define TFT_HEIGHT 240          // 91
 * 
 * // #define TFT_MISO  PIN_D6     // 170
 * // #define TFT_MOSI  PIN_D7     // 171
 * // #define TFT_SCLK  PIN_D5     // 172
 *
 * // #define TFT_CS    PIN_D8     // 174
 * // #define TFT_DC    PIN_D3     // 175
 * // #define TFT_RST   PIN_D4     // 176
 * 
 * #define TFT_MOSI 19             // 223
 * #define TFT_SCLK 18             // 224
 * #define TFT_CS    5             // 225, Chip select control pin
 * #define TFT_DC   16             // 226, Data Command control pin
 * #define TFT_RST  23             // 227, Reset pin (could connect to RST pin)
 * #define TFT_BL    4             // 228, LED back-light
 * 
 * 4. Clean project and build it again
 */

#include <SPI.h>
#include <TFT_eSPI.h>       // Hardware-specific library

TFT_eSPI tft = TFT_eSPI();  // Invoke custom library


void setup(void)
{
    tft.init();
    tft.fillScreen(TFT_BLACK);

    tft.drawRect(0, 0, tft.width(), tft.height(), TFT_GREEN);

    // Set "cursor" at top left corner of display (0,5) and select font 2
    tft.setCursor(0, 5, 2);

    // Set the font colour to be white with a black background
    tft.setTextColor(TFT_WHITE);

    // We can now plot text on screen using the "print" class
    tft.println(" Initialised default\n");
    tft.println(" White text");

    tft.setTextColor(TFT_RED);
    tft.println(" Red text");

    tft.setTextColor(TFT_GREEN);
    tft.println(" Green text");

    tft.setTextColor(TFT_BLUE);
    tft.println(" Blue text");
}


void loop()
{
    // Binary inversion of colours
    tft.invertDisplay(true); // Where i is true or false
    delay(5000);

    tft.invertDisplay(false);
    delay(5000);
}
