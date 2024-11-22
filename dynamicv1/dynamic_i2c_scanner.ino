/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ------------------------------------------------------------------
  Development Platform : Dynamic 1.0
  (mobile robot development platform)
  ------------------------------------------------------------------
  I2C Device Scanning Example.
  ------------------------------------------------------------------
  Hardware setup :
  All intergrated I2C devices are is allready mapped and connected
  to the Arduino board.
  ------------------------------------------------------------------
  I2C device at address 0x27 = 16*2 LCD
  I2C device at address 0x69 = MPU9250
  ------------------------------------------------------------------
  22 march 2021
*/

#include <Wire.h> //including the wire library in order to communicate with i2c bus devices.

void setup()
{
  Wire.begin(); //initializing connection to the i2c device(s).

  Serial.begin(9600);//starting serial communication between arduino and computer.

  Serial.println("\nI2C Scanner");//printing message to serial monitor.
}


void loop()
{
  byte error, address; //variables to hold the error values and i2c devices addresses.

  int nDevices;//a variable to hold the i2c device count.

  Serial.println("Scanning...");//printing message to serial monitor.

  nDevices = 0;
  for (address = 1; address < 127; address++ )
  {
    // the i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  !");

      nDevices++;
    }
    else if (error == 4)
    {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

  delay(5000);// wait 5 seconds between each next scan.
}
