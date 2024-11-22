/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  --------------------------------------------------------
  Development Platform : Quadrant 1.0
  (embedded development platform)
  --------------------------------------------------------
  Hardware setup :
   connect LDR PIN to Arduino Analog PIN-> 0(A0)
   turn on power switch of the top development board.
  --------------------------------------------------------
  22 march 2021
*/
int LDR = A0;// the number of the LDR pin.

void setup() {
  Serial.begin(9600);//starting serial communication between arduino and computer.

  pinMode(LDR, INPUT);//initializing LDR pin as a input pin.
}

void loop() {
  int LDR_VALUE = analogRead(LDR);//read and store the value of the LDR pin in the variable called "LDR_VALUE".

  Serial.println(LDR_VALUE);//printing the value of "LDR_VALUE" variable to the serial monitor.

  delay(1000);//waiting for one second to be elapsed.

}
