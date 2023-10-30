/**
 * ESP-32 Wi-Fi Scan
 * 
 * This open source code was designed on 18 April 2022 by Karens_e-Shop.
 * Please visit my website for other project ideas and to purchase from
 * my range of products: https://www.karenseshop.co.uk
 * 
 * THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL KAREN'S E-SHOP BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include <Arduino.h>
#include <WiFi.h>

// The SSID (name) and password of the Wi-Fi network you want to connect to
const char* ssid="Add your SSID here";
const char* password = "Add your Wi-Fi Password here";

#define PIN_LED 2


void setup() 
{
    pinMode(PIN_LED, OUTPUT);
    digitalWrite(PIN_LED, HIGH);

    Serial.begin(115200);
    Serial.println();
    Serial.print("Wi-Fi connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid,password);

    Serial.println();
    Serial.print("Connecting");

    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");        
    }

    digitalWrite(PIN_LED, LOW);
    Serial.println();

    Serial.println("Wi-Fi Connected Successfully!");
    Serial.print("ESP-32 IP Address: ");
    Serial.println(WiFi.localIP());
}

void loop() 
{
    ;
}
