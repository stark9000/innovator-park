/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  -------------------------------------------------------------------
  Development Platform : Inspire 1.0
  (Arduino development platform)
  -------------------------------------------------------------------
  PotentioMeter Example.
  -------------------------------------------------------------------
  Hardware setup :
  plug a Arduino nano board in to the inspre top development board.
  turn on power switch of the top development board.

  Connect POT PIN to Arduino Analog PIN-> 0(A0)
  turn on power switch of the top development board.
  -------------------------------------------------------------------
  22 march 2021
*/

int POTENTIOMETER = A0;//the number of the POT pin.

void setup() {
  Serial.begin(9600);//starting serial communication between arduino and computer.

  pinMode(POTENTIOMETER, INPUT);//initializing POT pin as a input pin.

}

void loop() {
  int POTENTIOMETER_VALUE = analogRead(POTENTIOMETER);//read and store the value of the POT pin in the variable called "POTENTIOMETER_VALUE".

  Serial.println(POTENTIOMETER_VALUE);//printing the value of "POTENTIOMETER_VALUE" variable to the serial monitor.

  delay(1000);//waiting for one second to be elapsed.
}
