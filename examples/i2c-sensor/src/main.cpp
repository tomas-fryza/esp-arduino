/*
 * Communication with I2C sensor MPU-6050
 * 
 * In VS Code with PlatformIO, add the folowing lines to `platformio.ini`
 * lib_deps =
 *     adafruit/Adafruit MPU6050 @ ^2.2.6
 * 
 * monitor_speed = 115200
 * # Enable ANSI color codes in serial monitor
 * monitor_raw = yes
 *
 * https://registry.platformio.org/libraries/adafruit/Adafruit%20MPU6050/examples/basic_readings/basic_readings.ino
 */

#include <Adafruit_MPU6050.h>
#include <Wire.h>

// Create sensor object `mpu`
Adafruit_MPU6050 mpu;

void setup()
{
    Serial.begin(115200);
    delay(200);
    // Serial.setDebugOutput(true);

    // Initialize MPU-6050 sensor
    if (!mpu.begin()) {
        Serial.println("\x1b[1;31m[ERROR]\x1b[0m Failed to find MPU-6050 chip");
        while (1) {
            delay(100);
        }
    }

    // Set accelerometer measurement range
    mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
    // MPU6050_RANGE_2_G ... +-2G
    // MPU6050_RANGE_4_G ... +-4G
    // MPU6050_RANGE_8_G ... +-8G
    // MPU6050_RANGE_16_G... +-16G

    // Set gyroscope measurement range
    mpu.setGyroRange(MPU6050_RANGE_250_DEG);
    // MPU6050_RANGE_250_DEG ... +-250 deg/s
    // MPU6050_RANGE_500_DEG ... +-500 deg/s
    // MPU6050_RANGE_1000_DEG... +-1000 deg/s
    // MPU6050_RANGE_2000_DEG... +-2000 deg/s

    // Set filter bandwidth
    mpu.setFilterBandwidth(MPU6050_BAND_10_HZ);
    // MPU6050_BAND_260_HZ
    // MPU6050_BAND_184_HZ
    // MPU6050_BAND_94_HZ
    // MPU6050_BAND_44_HZ
    // MPU6050_BAND_21_HZ
    // MPU6050_BAND_10_HZ
    // MPU6050_BAND_5_HZ
}

void loop()
{
    sensors_event_t a, g, temp;

    // Get new sensor events with current readings
    mpu.getEvent(&a, &g, &temp);

    // Print accelerations on x, y, z axis
    Serial.print("Accel. [m/s^2]: ");
    Serial.print(a.acceleration.x);
    Serial.print(" ");
    Serial.print(a.acceleration.y);
    Serial.print(" ");
    Serial.print(a.acceleration.z);

    // Print angular velocity on axis
    Serial.print("\tRotation [rad/s]: ");
    Serial.print(g.gyro.x);
    Serial.print(" ");
    Serial.print(g.gyro.y);
    Serial.print(" ");
    Serial.print(g.gyro.z);

    // Print temperature in Celsius degrees
    Serial.print("\tTemp. [C]: ");
    Serial.println(temp.temperature);

    delay(1000);
}
