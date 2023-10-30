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

#include <WiFi.h>


void setup()
{
    Serial.begin(115200);

    // Set WiFi to station mode and disconnect from an AP
    // if it was previously connected:
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
}


void loop()
{
    Serial.print("Scanning Wi-Fi... ");

    // WiFi.scanNetworks will return the number of networks found:
    int n = WiFi.scanNetworks();
    Serial.print(n);
    Serial.println(" device(s) found");
    
    if (n != 0) {
        Serial.println("SSID\t\t\tRSSI [dBm]");
        
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found:
            Serial.print(WiFi.SSID(i));
            Serial.print("\t\t");
            Serial.print(WiFi.RSSI(i));
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
        }
    }
    Serial.println("");
    
    delay(5000); // Wait 5 seconds before scanning again.
}
