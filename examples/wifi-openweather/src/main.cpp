/*
 * Read weather data from OpenWeatherMap.
 *
 * https://randomnerdtutorials.com/esp32-http-get-open-weather-map-thingspeak-arduino/
 */

#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>

// Network settings
const char* WIFI_SSID = "<YOUR WIFI SSID>";
const char* WIFI_PSWD = "<YOUR WIFI PASSWORD>";
String WEATHER_API_KEY = "<OpenWeatherMap API KEY>";
String CITY = "Brno,CZ";

String jsonBuffer;


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


String httpGETRequest(const char* serverName)
{
    WiFiClient client;
    HTTPClient http;

    // Your Domain name with URL path or IP address with path
    http.begin(client, serverName);

    // Send HTTP POST request
    int httpResponseCode = http.GET();

    String payload = "{}"; 

    if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        payload = http.getString();
    }
    else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();

return payload;
}


void setup() 
{
    Serial.begin(115200);
    while (!Serial);
}


void loop() 
{
    connect_wifi(WIFI_SSID, WIFI_PSWD);
    Serial.println("Get weather for " + CITY);

    String serverPath = "http://api.openweathermap.org/data/2.5/";
    serverPath += "weather?appid="+WEATHER_API_KEY+"&q="+CITY+"&units=metric";

    jsonBuffer = httpGETRequest(serverPath.c_str());
    Serial.println(jsonBuffer);
    JSONVar myObject = JSON.parse(jsonBuffer);

    // JSON.typeof(jsonVar) can be used to get the type of the var
    if (JSON.typeof(myObject) == "undefined") {
        Serial.println("Parsing input failed!");
        return;
    }

    Serial.print("JSON object = ");
    Serial.println(myObject);
    Serial.print("Temperature: ");
    Serial.println(myObject["main"]["temp"]);
    Serial.print("Pressure: ");
    Serial.println(myObject["main"]["pressure"]);
    Serial.print("Humidity: ");
    Serial.println(myObject["main"]["humidity"]);
    Serial.print("Wind Speed: ");
    Serial.println(myObject["wind"]["speed"]);

    disconnect_wifi();
    delay(60000);
}
