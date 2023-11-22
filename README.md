# Arduino framework in ESP32/ESP8266 microcontrollers

The repository contains instructions and examples for ESP32/ESP8266 microcontrollers using C/C++ Arduino framework in PlatformIO and Visual Studio Code IDE.

## Installation

*[PlatformIO](https://platformio.org/) is a cross-platform build system that can be used to develop software platforms for Arduino, ESP32, PIC32, and AVR. PlatformIO can be used with VS Code to provide a powerful set of tools to assist you in development [[1]](https://maker.pro/arduino/tutorial/how-to-use-platformio-in-visual-studio-code-to-program-arduino), [[2]](https://dronebotworkshop.com/platformio/).*

1. Download and install [Visual Studio Code](https://code.visualstudio.com/) source code editor.

2. Run Visual Studio Code, open up the extensions viewer in menu **View > Extensions Ctrl+shift+X**, and then typing `PlatformIO` into the search bar. Press **Install** button on the result `PlatformIO IDE`.

   ![Install PlatformIO IDE](images/platformio_install.png)

   It may take a few minutes depending on your connection speed. Do not close any window and do not open other folders until the installing process is completed. After that, restart the Visual Studio Code.

## Usage

1. *Create a new project:* Click on the PlatformIO icon in the left-hand margin, then in menu **PIO Home > Open > New Project**. Type `blink` as project name, select your ESP board, such as `Espressif ESP32 Dev Module`, keep `Arduino` framework, and select location to your working folder. Click on the **Finish** button.

2. *Code the application:* Copy/paste the following code to your `BLINK > src > main.cpp` source file.

    ```c
    /*
     * Blink
     *
     * Turns on and off an LED and send a message to VS Code repeatedly.
     */

    #include <Arduino.h>

    // Set pin number of your LED
    #define PIN_LED 2

    // Put your setup code here, to run once
    void setup()
    {
        // Initialize LED digital pin as an output
        pinMode(PIN_LED, OUTPUT);
        // Tur off the LED
        digitalWrite(PIN_LED, LOW);

        // Set the communication symbol rate
        Serial.begin(115200);
    }

    // Put your main code here, to run repeatedly
    void loop()
    {
        Serial.println("LED is on");  // Transmit string
        digitalWrite(PIN_LED, HIGH);  // Turn on the LED
        delay(250);                   // Wait for 250 ms
        Serial.println("LED is off");
        digitalWrite(PIN_LED, LOW);   // Turn off the LED
        delay(750);                   // Wait for 750 ms
    }
    ```

   The code combine both output LED control and UART communication from ESP microcontroller and VS Code. To ensure the correct receiption, add the following line to the `BLINK > platformio.ini` configuration file:

   ```shell
   monitor_speed = 115200
   ```

3. *Compile and upload the code:* The handy shortcuts for building and uploading the code is available on the footer taskbar. Hover over the icon to get its functionality. First, compile (build) the project, then upload it to ESP board, and open the Serial monitor to receive messages from the board. You can clean up generated files as well.

   ![Control icons](images/platformio_footer2.png)

   *Command Palette:* All available commands in VS Code are also accessible by `Ctrl+Shift+P` shortcut and followed by a command. Most useful commands in this course are:

      * `PlatformIO: Build`
      * `PlatformIO: Upload`
      * `PlatformIO: Clean`
      * `PlatformIO: Upload and Monitor`

## VS Code shortcuts

Other common [shortcuts in VS Code](https://code.visualstudio.com/shortcuts/keyboard-shortcuts-windows.pdf) are:

| **Shortcut** | **Usage**
| :-- | :--
| `Ctrl+Shift+P` | Command Palette. Access to all of the VS Code functionality
| `Ctrl+K+O` | Open folder
| `Ctrl+K F` | Close folder
| `Ctrl+Tab` | Switch between open files
| `Ctrl+O` | Open a file
| `Ctrl+Shift+S` | Save all open files
| `Ctrl+Shift+V` | Open Markdown preview
| `Ctrl+K V` | Open Markdown preview to the side
| `Ctrl+B` | Toggle Sidebar visibility

## Examples

1. [Basic C template, blink a LED](examples/blink/)
2. [Button](examples/button/)
3. [Timers](examples/timer/)
4. [I2C scanner](examples/i2c-scan/)
5. [I2C sensor MPU-6050](examples/i2c-sensor/)
6. I2C OLED display
7. [Wi-Fi scanner](examples/wifi-scan/)
8. [Wi-Fi Station mode](examples/wifi-station/)
9. ThingSpeak online platform
