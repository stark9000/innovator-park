/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------
  Development Platform : Quadrant 1.0
  (embedded development platform)
  --------------------------------------------------------
   Bluetooth Send Example.
  --------------------------------------------------------
   Hardware setup :
   connect BT RX PIN to Arduino Digital PIN-> 2(D2)
   connect BT TX PIN to Arduino Digital PIN-> 3(D3)
  --------------------------------------------------------
  24 march 2021
*/

#include <SoftwareSerial.h>//including the software serial library.

SoftwareSerial btm(2, 3);// initiating software serial object.

void setup() {
  btm.begin(9600);//starting software serial communication.
}

void loop() {
  btm.println("this is from Quadrant :) ");//printing a message to software serial.

  delay(1000);//keep a one second delay between each serial print.
}
