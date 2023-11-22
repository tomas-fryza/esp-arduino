/*
 * ESP-32 Wi-Fi Scan
 *
 * In VS Code with PlatformIO, add the folowing line to `platformio.ini`
 * monitor_speed = 115200
 *
 * https://github.com/espressif/arduino-esp32/tree/master/libraries/WiFi/examples/WiFiScan
 */

#include <WiFi.h>

void setup()
{
    Serial.begin(115200);

    // Set WiFi to station mode and disconnect from an AP
    // if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    Serial.print("Scanning Wi-Fi... ");

    // Scans for available WiFi networks and returns the discovered number
    int n = WiFi.scanNetworks();
    Serial.print(n);
    Serial.println(" network(s)");
    
    if (n != 0) {
        Serial.println("RSSI Channel \tSSID");
        
        for (int i = 0; i < n; ++i) {
            Serial.print(WiFi.RSSI(i));
            Serial.print("  (");
            Serial.print(WiFi.channel(i));
            Serial.print(") \t");
            Serial.print(WiFi.SSID(i));
            Serial.println("");
            delay(10);
        }
    }
}

void loop()
{
    // Empty forever loop
}
