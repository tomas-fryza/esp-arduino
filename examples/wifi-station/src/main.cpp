/*
 * Connect ESP32 to a Wi--Fi network
 * 
 * In VS Code with PlatformIO, add the folowing line to `platformio.ini`
 * monitor_speed = 115200
 *
 * https://deepbluembedded.com/esp32-wifi-library-examples-tutorial-arduino/
 */

#include <WiFi.h>
#include <stdint.h>

// The SSID (name) and password of the Wi-Fi network you want to connect to
const char* ssid="Add your SSID here";
const char* password = "Add your Wi-Fi Password here";

void setup() 
{
    Serial.begin(115200);
    delay(200);

    // Initialize the Wi-Fi interface in Station mode
    WiFi.mode(WIFI_STA);
    // Connect to Wi-Fi network
    WiFi.begin(ssid, password);

    // Wait until the connection is established
    Serial.print("Connecting to ");
    Serial.print(ssid);
    while(WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(100);
    }
    Serial.println(" Done");

    Serial.println("Wi-Fi Configuration:");
    Serial.print("IP address: \t");
    Serial.println(WiFi.localIP());
    Serial.print("Subnet mask:\t");
    Serial.println(WiFi.subnetMask());
    Serial.print("Gateway: \t");
    Serial.println(WiFi.gatewayIP());

    Serial.print("Signal strength (RSSI): ");
    Serial.println(WiFi.RSSI());

    byte mac[6];
    WiFi.macAddress(mac);
    Serial.print("MAC address: ");
    Serial.print(mac[5], HEX);
    Serial.print(":");
    Serial.print(mac[4], HEX);
    Serial.print(":");
    Serial.print(mac[3], HEX);
    Serial.print(":");
    Serial.print(mac[2], HEX);
    Serial.print(":");
    Serial.print(mac[1], HEX);
    Serial.print(":");
    Serial.println(mac[0], HEX);

    WiFi.disconnect();
}

void loop() 
{
    // Empty forever loop
}
