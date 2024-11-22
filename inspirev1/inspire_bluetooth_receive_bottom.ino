/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ---------------------------------------------------------------------------
  Development Platform : Inspire 1.0
  (Arduino development platform)
  ---------------------------------------------------------------------------
  Bluetooth Receive Data Example.
  ---------------------------------------------------------------------------
  Hardware setup :
  plug a Arduino nano board in to the inspre top development board.
  
  connect BLE RX PIN to Arduino Digital PIN-> 2(D2)
  connect BLE TX PIN to Arduino Digital PIN-> 3(D3)
  ---------------------------------------------------------------------------
  //Android Application :
  //https://play.google.com/store/apps/details?id=project.bluetoothterminal
  ---------------------------------------------------------------------------
  23 march 2021
*/

#include <SoftwareSerial.h>//including the software serial library.
SoftwareSerial btm(3, 2);//initiating software serial object.

char c;//a variable to hold the character received by the serial data.

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
