/*
 * Read temperature and humidity and send data to ThingSpeak.
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
 *     mathworks/ThingSpeak@^2.0.0
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
 * https://registry.platformio.org/libraries/mathworks/ThingSpeak
 */

#include <DHT12.h>
#include <WiFi.h>
#include <ThingSpeak.h>


// Network settings
const char* WIFI_SSID = "<YOUR WIFI SSID>";
const char* WIFI_PSWD = "<YOUR WIFI PASSWORD>";
const char* API_KEY = "<THINGSPEAK WRITE API KEY>";
unsigned long CHANNEL_ID = <THINGSPEAK CHANNEL ID>;

DHT12 dht12;
WiFiClient client;


void connect_wifi(const char* ssid, const char* password)
{
    WiFi.mode(WIFI_STA);

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
    }
    else {
        Serial.println("Already connected");
    }
}


void disconnect_wifi(void)
{
    WiFi.disconnect();

    while(WiFi.status() == WL_CONNECTED) {
        delay(100);
    }

    WiFi.mode(WIFI_STA);
    Serial.println("Wi-Fi off");
}


void setup() 
{
    Serial.begin(115200);
    while (!Serial);

    dht12.begin();

    ThingSpeak.begin(client);  // Initialize ThingSpeak
}


void loop() 
{
    float temp = dht12.readTemperature();
    float humidity = dht12.readHumidity();
    Serial.println((String)"Temperature: "+temp+"°C, Humidity: "+humidity+"%");
    connect_wifi(WIFI_SSID, WIFI_PSWD);

    // Write to ThingSpeak. There are up to 8 fields in a channel
    ThingSpeak.setField(1, temp);
    ThingSpeak.setField(2, humidity);
    int status = ThingSpeak.writeFields(CHANNEL_ID, API_KEY);
    if (status == 200)
        Serial.println("Data updated");

    disconnect_wifi();
    delay(60000);
}
