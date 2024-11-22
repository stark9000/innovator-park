/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------
  Development Platform : Quadrant 1.0
  (embedded development platform)
  --------------------------------------------------------
   Hardware setup :
   connect A4 PIN to SDA
   connect A5 PIN to SCL
  ---------------------------------------------------------------
  I2C device at address 0x27 = 16*2 LCD
  I2C device at address 0x50 = EEPROM
  I2C device at address 0x68 = 1307 RTC
  I2C device at address 0x68 = MPU6050
  --------------------------------------------------------
  24 march 2021
*/


#include <MPU6050_tockn.h> //including mpu6050's library.
#include <Wire.h>//including wire libraary to comunicate with i2c devices.

MPU6050 mpu6050(Wire);

long timer = 0;//variable for hoding the timer value.

void setup() {
  Serial.begin(9600);//starting serial communication between arduino and computer.
  Wire.begin();//starting i2c communication.
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();

  if (millis() - timer > 1000) {//one second non-blockin delay.

    //print all information to serial monitor.
    Serial.println("=======================================================");
    Serial.print("temp : "); Serial.println(mpu6050.getTemp());
    Serial.print("accX : "); Serial.print(mpu6050.getAccX());
    Serial.print("  accY : "); Serial.print(mpu6050.getAccY());
    Serial.print("  accZ : "); Serial.println(mpu6050.getAccZ());

    Serial.print("gyroX : "); Serial.print(mpu6050.getGyroX());
    Serial.print("  gyroY : "); Serial.print(mpu6050.getGyroY());
    Serial.print("  gyroZ : "); Serial.println(mpu6050.getGyroZ());

    Serial.print("accAngleX : "); Serial.print(mpu6050.getAccAngleX());
    Serial.print("  accAngleY : "); Serial.println(mpu6050.getAccAngleY());

    Serial.print("gyroAngleX : "); Serial.print(mpu6050.getGyroAngleX());
    Serial.print("  gyroAngleY : "); Serial.print(mpu6050.getGyroAngleY());
    Serial.print("  gyroAngleZ : "); Serial.println(mpu6050.getGyroAngleZ());

    Serial.print("angleX : "); Serial.print(mpu6050.getAngleX());
    Serial.print("  angleY : "); Serial.print(mpu6050.getAngleY());
    Serial.print("  angleZ : "); Serial.println(mpu6050.getAngleZ());
    Serial.println("=======================================================");
    timer = millis();

  }

}
