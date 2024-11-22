/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------
  Development Platform : Quadrant 1.0
  (embedded development platform)
  --------------------------------------------------------
   Bluetooth receive Example.
  --------------------------------------------------------
   Hardware setup :
   Connect BT RX PIN to Arduino Digital PIN-> 2(D2)
   Connect BT TX PIN to Arduino Digital PIN-> 3(D3)
  --------------------------------------------------------
  24 march 2021
*/


#include <SoftwareSerial.h> //including the software serial library.

SoftwareSerial btm(2, 3); // rx tx // initiating software serial object.

char c;//variable to hold the character recived by the serial data.

void setup() {
  btm.begin(9600);//starting software serial communication.

  Serial.begin(9600);//starting serial communication between arduino and computer.
}

void loop() {
  if (btm.available() > 0) {//check if software serial is containing any data.

    while (btm.available() > 0) {//while there is data,

      c = btm.read();//read it and store it in the variable called "c".

      Serial.print(c);//printing stored variable to the serial monitor.
    }
  }
}
