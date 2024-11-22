/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------
  Development Platform : Quadrant 1.0
  (embedded development platform)
  --------------------------------------------------------
  EEPROM Example.
  --------------------------------------------------------
  Hardware setup :
  Connect Arduino analog PIN 4(A4) to I2C SDA PIN
  Connect Arduino analog PIN 5(A5) TO I2C SCL PIN
  --------------------------------------------------------
  I2C device at address 0x27 = 16*2 LCD
  I2C device at address 0x50 = EEPROM
  I2C device at address 0x68 = 1307 RTC
  I2C device at address 0x68 = MPU6050
  --------------------------------------------------------
  24 march 2021
*/

#include <Wire.h> //including wire library, in oder to communicate with i2c bus devices.

int EEPROM_I2C_ADDRESS = 0x50;//address of the AT24c32 eeprom chip on i2c bus.

void setup()
{
  Wire.begin();//initializing connection to the i2c devices.

  Serial.begin(9600);//starting serial communication between arduino and computer.

  int address = 0; // starting address in the eeprom.

  byte val = 100; // value to write to the eeprom.

  writeAddress(address, val);//writing data to eeprom.

  byte readVal = readAddress(address);//variable to hold the vale read from eeprom.

  Serial.print("The returned value is ");//printing a message to serial monitor.

  Serial.println(readVal);//printing the value to serial monitor.

}

void loop()
{

}

void writeAddress(int address, byte val)//function to write data to eeprom.
{
  Wire.beginTransmission(EEPROM_I2C_ADDRESS); //starting data transmission with the device at specified address.

  Wire.write((int)(address >> 8));   // MSB most significant bit.

  Wire.write((int)(address & 0xFF)); // LSB least significant bit.

  Wire.write(val);//writing data to wire.

  Wire.endTransmission();//closing transmition.

  delay(5);//wait for 5 microseconds.
}

byte readAddress(int address)//function to read data from eeprom.
{
  byte rData = 0xFF; // variable to hold the data read from eeprom.

  Wire.beginTransmission(EEPROM_I2C_ADDRESS);//starting data transmission with the device at specified address.

  Wire.write((int)(address >> 8));   // writing data to (MSB) most significant bit.

  Wire.write((int)(address & 0xFF)); // writing data to (LSB) least significant bit.

  Wire.endTransmission();//closing transmission.

  Wire.requestFrom(EEPROM_I2C_ADDRESS, 1); // reqesting data.

  rData =  Wire.read(); // reading data from eeprom and storing data un the variable.

  return rData;//returning stored value.
}
