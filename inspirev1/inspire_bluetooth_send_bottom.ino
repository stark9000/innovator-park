/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------------------------
  Development Platform : Inspire 1.0
  (Arduino development platform)
  --------------------------------------------------------------------------
  Bluetooth Data Sending Example.
  --------------------------------------------------------------------------
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

void setup() {
  btm.begin(9600);//starting software serial communication.
}

void loop() {
  btm.println("this is from inspire :) ");//printing a message to software serial.
  delay(1000);//keep a one second delay between each serial print.
}
