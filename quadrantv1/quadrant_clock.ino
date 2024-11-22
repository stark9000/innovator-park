/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ------------------------------------------------------------------
  Development Platform : Quadrant 1.0
  (embedded development platform)
  ------------------------------------------------------------------
  RTC Example.
  ------------------------------------------------------------------
  Hardware setup :
  Connect Arduino analog PIN 4(A4) to I2C SDA PIN
  Connect Arduino analog PIN 5(A5) TO I2C SCL PIN
  ------------------------------------------------------------------
  I2C device at address 0x27 = 16*2 LCD
  I2C device at address 0x50 = EEPROM
  I2C device at address 0x68 = 1307 RTC
  ------------------------------------------------------------------
  22 march 2021
*/
#include <Wire.h>//including wire library in order to communicate with i2c bus devices.

#include <RTClib.h>//including real time clock library in order to use its functions.

RTC_DS1307 rtc;//creating a rtc object.


char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};//char array for storing the days of a week.


void setup () {

  Serial.begin(9600);//starting serial communication between arduino and computer.

  if (! rtc.begin()) {//check if we can connect to the rtc module.

    Serial.println("Couldn't find RTC");//if we can't connect to rtc module, print a message to serial monitor.

    while (1);//keep checking until we are able to connect to the rtc module.
  }
  if (! rtc.isrunning()) {//check if rtc is running.

    Serial.println("RTC is NOT running!");//else print message to the serial monitor.

    rtc.adjust(DateTime(2021, 3, 22, 10, 00, 0));//adjusting date and time.
  }
}
void loop () {
  DateTime now = rtc.now(); //obtaining current the date and time.

  //printing all information to serial monitor.
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);//obtaining the day of the week from the "daysOfTheWeek" array.
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  delay(3000);//keep a 3 second time delay between each serial print.
}
