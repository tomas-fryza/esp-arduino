#include <Arduino.h>
#include <Wire.h>

void setup()
{
    Wire.begin();
    Serial.begin(115200);
    while (!Serial);

    Serial.println("Scanning I2C... ");

    for (uint8_t sla = 8; sla < 120; sla++) {
        // I2c scanner uses the return value of `Write.endTransmisstion()`
        // to see if a device did acknowledge to the address
        Wire.beginTransmission(sla);
        if (Wire.endTransmission() == 0) {  // ACK from Slave
            Serial.println(sla, HEX);
        }
    }
}

void loop()
{
    // Empty forever loop
}
