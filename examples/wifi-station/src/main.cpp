/*
 * Connect ESP32 to a Wi-Fi network
 * 
 * In VS Code with PlatformIO, add the folowing line to `platformio.ini`
 * monitor_speed = 115200
 *
 * https://randomnerdtutorials.com/esp32-useful-wi-fi-functions-arduino/
 */

#include <WiFi.h>

// Network settings
const char* WIFI_SSID = "<YOUR WIFI SSID>";
const char* WIFI_PSWD = "<YOUR WIFI PASSWORD>";


void connect_wifi(const char* ssid, const char* password)
{
    if (WiFi.status() != WL_CONNECTED) {
        // Connect to Wi-Fi network
        WiFi.begin(ssid, password);

        // Wait until the connection is established
        Serial.print("Connecting to " + String(ssid));
        // Serial.print(ssid);
        while(WiFi.status() != WL_CONNECTED) {
            Serial.print(".");
            delay(100);
        }

        Serial.println(" Done");
    } else {
        Serial.println("Already connected");
    }
}


void disconnect_wifi(void)
{
    WiFi.disconnect();

    while(WiFi.status() == WL_CONNECTED) {
        delay(100);
    }

    Serial.println("Disconnected");
}


void get_network_info(void)
{
    if (WiFi.status() == WL_CONNECTED) {
        Serial.print("[*] Network information for ");
        Serial.println(WiFi.SSID());

        Serial.print("[+] ESP32 IP:    ");
        Serial.println(WiFi.localIP());
        Serial.print("[+] Subnet Mask: ");
        Serial.println(WiFi.subnetMask());
        Serial.print("[+] Gateway IP:  ");
        Serial.println(WiFi.gatewayIP());
        Serial.println((String)"[+] RSSI: \t " + WiFi.RSSI());
        byte mac[6];
        WiFi.macAddress(mac);
        Serial.print("[+] MAC address: ");
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
    }
}


void setup() 
{
    Serial.begin(115200);
    while (!Serial);

    // Initialize the Wi-Fi interface in Station mode
    WiFi.mode(WIFI_STA);
    connect_wifi(WIFI_SSID, WIFI_PSWD);

    get_network_info();

    disconnect_wifi();
}


void loop() 
{
    // Empty forever loop
}
