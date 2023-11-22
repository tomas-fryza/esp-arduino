/*
 * Communication with I2C sensor MPU-6050
 * 
 * https://randomnerdtutorials.com/esp32-mpu-6050-accelerometer-gyroscope-arduino/
 */

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

void setup()
{
    Serial.begin(115200);
    delay(200);
    // Serial.setDebugOutput(true);

    if (!mpu.begin()) {
        Serial.println("\x1b[1;31m[ERROR]\x1b[0m Failed to find MPU-6050 chip");
        while (1) {
            delay(100);
        }
    }

    mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
    mpu.setGyroRange(MPU6050_RANGE_250_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_10_HZ);
}

void loop()
{
    sensors_event_t a, g, temp;

    // Get new sensor events with the readings
    mpu.getEvent(&a, &g, &temp);

    // Print out the values
    Serial.print("Accel. [m/s^2]: ");
    Serial.print(a.acceleration.x);
    Serial.print(" ");
    Serial.print(a.acceleration.y);
    Serial.print(" ");
    Serial.print(a.acceleration.z);

    Serial.print("\tRotat. [rad/s]: ");
    Serial.print(g.gyro.x);
    Serial.print(" ");
    Serial.print(g.gyro.y);
    Serial.print(" ");
    Serial.print(g.gyro.z);

    Serial.print("\tTemp. [C]: ");
    Serial.println(temp.temperature);

    delay(1000);
}
