/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ----------------------------------------------------------------------------
  Development Platform : Dynamic 1.0
  (mobile robot development platform)
  ----------------------------------------------------------------------------
  Bluetooth Send Example.
  ----------------------------------------------------------------------------
  Hardware setup :
  built-in bluetooth module already mapped and connected to
  Arduino board. the PINs are as follows:

  BT_TX connected to Arduino digital PIN 2(D2)
  BT_RX connected to Arduino digital PIN 3(D3)
  Serial 1 on Atmega PRO MINI
  ----------------------------------------------------------------------------
  //Android application used for this example:
  //https://play.google.com/store/apps/details?id=project.bluetoothterminal
  ----------------------------------------------------------------------------
  23 march 2021
*/

void setup() {
  Serial1.begin(9600);//starting software serial communication.
}

void loop() {
  Serial1.println("this is from Dynamic :) ");//printing a message to software serial.

  delay(1000);//keep a one second delay between each serial print.
}
