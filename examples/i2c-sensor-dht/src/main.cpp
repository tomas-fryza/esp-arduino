/*
 * Read temperature and humidity via I2C bus.
 *
 * Use hardware I2C bus and read temperature and humidity
 * values from DHT12 sensor with SLA = 0x5c (92).
 * 
 * In VS Code with PlatformIO, add the folowing lines to `platformio.ini`:
 * monitor_speed = 115200
 * # Enable ANSI color codes in serial monitor
 * monitor_raw = yes
 *
 * lib_deps =
 *     xreef/DHT12 sensor library@^1.0.2
 *
 * NOTES:
 *   * Connect DHT12 sensor to on-board pins:
 *       DHT12 | ESP32 | ESP8266 | ESP32-CAM | ESP32C3
 *      -------+-------+---------+-----------+---------
 *       SCL   |    22 |       5 |        15 |       8
 *       SDA   |    21 |       4 |        13 |      10
 *       +     |  3.3V |    3.3V |      3.3V |    3.3V
 *       -     |   GND |     GND |       GND |     GND
 * 
 * https://registry.platformio.org/libraries/xreef/DHT12%20sensor%20library/examples/esp8266I2CDHT12/esp8266I2CDHT12.ino
 */

#include <Arduino.h>
#include <DHT12.h>

// Set dht12 i2c comunication on default Wire pins
DHT12 dht12;

int timeSinceLastRead = 0;

void setup()
{
    Serial.begin(115200);
    while (!Serial);

    dht12.begin();
    Serial.println("Reading DHT12 sensor... ");
}

void loop()
{
    // Report every 2 seconds.
    if(timeSinceLastRead > 2000) {
        // Read temperature as Celsius (the default)
        float t12 = dht12.readTemperature();
        // Read temperature as Fahrenheit (isFahrenheit = true)
        float f12 = dht12.readTemperature(true);
        // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
        float h12 = dht12.readHumidity();

        bool dht12Read = true;
        // Check if any reads failed and exit early (to try again).

        if (isnan(h12) || isnan(t12) || isnan(f12)) {
            Serial.println("Failed to read from DHT12 sensor!");
            dht12Read = false;
        }

        if (dht12Read) {
            // // Compute heat index in Fahrenheit (the default)
            // float hif12 = dht12.computeHeatIndex(f12, h12);
            // // Compute heat index in Celsius (isFahreheit = false)
            // float hic12 = dht12.computeHeatIndex(t12, h12, false);
            // // Compute dew point in Fahrenheit (the default)
            // float dpf12 = dht12.dewPoint(f12, h12);
            // // Compute dew point in Celsius (isFahreheit = false)
            // float dpc12 = dht12.dewPoint(t12, h12, false);


            Serial.print("DHT12=> Humidity: ");
            Serial.print(h12);
            Serial.print(" %\t");
            Serial.print("Temperature: ");
            Serial.print(t12);
            Serial.println(" *C ");
            // Serial.print(f12);
            // Serial.print(" *F\t");
            // Serial.print("  Heat index: ");
            // Serial.print(hic12);
            // Serial.print(" *C ");
            // Serial.print(hif12);
            // Serial.print(" *F");
            // Serial.print("  Dew point: ");
            // Serial.print(dpc12);
            // Serial.print(" *C ");
            // Serial.print(dpf12);
            // Serial.println(" *F");
        }
        timeSinceLastRead = 0;

    }
    delay(100);
    timeSinceLastRead += 100;

}
