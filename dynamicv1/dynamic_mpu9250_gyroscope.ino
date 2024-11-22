/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------
  Development Platform : Dynamic 1.0
  (mobile robot development platform)
  --------------------------------------------------------
  MPU9050 Example.
  --------------------------------------------------------
  Hardware setup :
  MPU9050 is allready mapped and connected to the
  Arduino board.I2C address is : 0x69
   --------------------------------------------------------
  23 march 2021
*/

#include <Wire.h>//including wire library, in order to communicate with I2C devices.
int MPU9250_ADDRESS = 0x69;//MPU9250 module's i2c address.
int MAG_ADDRESS = 0x0C;//MPU9250 module's magnetometer i2c address.

int GYRO_FULL_SCALE_250_DPS = 0x00;
int GYRO_FULL_SCALE_500_DPS = 0x08;
int GYRO_FULL_SCALE_1000_DPS = 0x10;
int GYRO_FULL_SCALE_2000_DPS = 0x18;

int ACC_FULL_SCALE_2_G = 0x00;
int ACC_FULL_SCALE_4_G = 0x08;
int ACC_FULL_SCALE_8_G = 0x10;
int ACC_FULL_SCALE_16_G = 0x18;

// This function read Nbytes bytes from I2C device at address Address.
// Put read bytes starting at register Register in the Data array.


long int ti;

void setup()
{
  Wire.begin();
  Serial.begin(9600);

  // Set accelerometers low pass filter at 5Hz
  I2CwriteByte(MPU9250_ADDRESS, 29, 0x06);
  // Set gyroscope low pass filter at 5Hz
  I2CwriteByte(MPU9250_ADDRESS, 26, 0x06);


  // Configure gyroscope range
  I2CwriteByte(MPU9250_ADDRESS, 27, GYRO_FULL_SCALE_1000_DPS);
  // Configure accelerometers range
  I2CwriteByte(MPU9250_ADDRESS, 28, ACC_FULL_SCALE_4_G);
  // Set by pass mode for the magnetometers
  I2CwriteByte(MPU9250_ADDRESS, 0x37, 0x02);

  // Request continuous magnetometer measurements in 16 bits
  I2CwriteByte(MAG_ADDRESS, 0x0A, 0x16);


  // Store initial time
  ti = millis();
}

// Counter
long int cpt = 0;

// Main loop, read and display data
void loop()
{
  // Display time
  Serial.print (millis() - ti, DEC);
  Serial.print ("\t");
  // ____________________________________
  // ::: accelerometer and gyroscope :::

  // Read accelerometer and gyroscope
  uint8_t Buf[14];
  I2Cread(MPU9250_ADDRESS, 0x3B, 14, Buf);

  // Create 16 bits values from 8 bits data

  // Accelerometer
  int16_t ax = -(Buf[0] << 8 | Buf[1]);
  int16_t ay = -(Buf[2] << 8 | Buf[3]);
  int16_t az = Buf[4] << 8 | Buf[5];

  // Gyroscope
  int16_t gx = -(Buf[8] << 8 | Buf[9]);
  int16_t gy = -(Buf[10] << 8 | Buf[11]);
  int16_t gz = Buf[12] << 8 | Buf[13];

  //printing accelerometer values to serial monitor.
  Serial.print (ax, DEC);
  Serial.print ("\t");
  Serial.print (ay, DEC);
  Serial.print ("\t");
  Serial.print (az, DEC);
  Serial.print ("\t");

  //printing gyroscope values to serial monitor.
  Serial.print (gx, DEC);
  Serial.print ("\t");
  Serial.print (gy, DEC);
  Serial.print ("\t");
  Serial.print (gz, DEC);
  Serial.print ("\t");

  //-----------------------------------------------
  //reading magnetometer values.
  //waiting data to be ready.
  uint8_t ST1;
  do
  {
    I2Cread(MAG_ADDRESS, 0x02, 1, &ST1);
  }
  while (!(ST1 & 0x01));

  //reading magnetometer data.
  uint8_t Mag[7];
  I2Cread(MAG_ADDRESS, 0x03, 7, Mag);

  // Create 16 bits values from 8 bits data

  // Magnetometer
  int16_t mx = -(Mag[3] << 8 | Mag[2]);
  int16_t my = -(Mag[1] << 8 | Mag[0]);
  int16_t mz = -(Mag[5] << 8 | Mag[4]);


  //printing magnetometer values to serial monitor.
  Serial.print (mx + 200, DEC);
  Serial.print ("\t");
  Serial.print (my - 70, DEC);
  Serial.print ("\t");
  Serial.print (mz - 700, DEC);
  Serial.print ("\t");
  Serial.println("");
}

void I2Cread(uint8_t Address, uint8_t Register, uint8_t Nbytes, uint8_t* Data)
{
  // Set register address
  Wire.beginTransmission(Address);
  Wire.write(Register);
  Wire.endTransmission();

  // Read Nbytes
  Wire.requestFrom(Address, Nbytes);
  uint8_t index = 0;
  while (Wire.available())
    Data[index++] = Wire.read();
}

// Write a byte (Data) in device (Address) at register (Register)
void I2CwriteByte(uint8_t Address, uint8_t Register, uint8_t Data)
{
  // Set register address
  Wire.beginTransmission(Address);
  Wire.write(Register);
  Wire.write(Data);
  Wire.endTransmission();
}
