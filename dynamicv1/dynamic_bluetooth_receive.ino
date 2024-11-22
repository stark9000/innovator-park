/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ----------------------------------------------------------------------------
  Development Platform : Dynamic 1.0
  (mobile robot development platform)
  ----------------------------------------------------------------------------
  Bluetooth Receive Example.
  ----------------------------------------------------------------------------
  Hardware setup :
  built-in bluetooth module already mapped and connected to 
  Arduino board. the PINs are as follows:

  BT_TX connected to Arduino digital PIN18(D18)
  BT_RX connected to Arduino digital PIN19(D19)
  Serial 1 on Atmega PRO MINI
  -----------------------------------------------------------------------------
  //Android application used for this example:
  //https://play.google.com/store/apps/details?id=project.bluetoothterminal
  -----------------------------------------------------------------------------
  23 march 2021
*/

char c;//variable to hold the character recived by the serial data.

void setup() {
  Serial1.begin(9600);//starting software serial communication.

  Serial.begin(9600);//starting serial communication between arduino and computer.
}

void loop() {
  if (Serial1.available() > 0) {//check if software serial is containing any data.

    while (Serial1.available() > 0) {//while there is data,

      c = Serial1.read();//read it and store it in the variable called "c".

      Serial.print(c);//printing stored variable to the serial monitor.
    }
  }
}
