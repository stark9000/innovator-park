/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ------------------------------------------------------------------
  Development Platform : Inspire 1.0
  (Arduino development platform)
  ------------------------------------------------------------------
  LDR Example.
  ------------------------------------------------------------------
  Hardware setup :
  plug a Arduino nano board in to the inspre top development board.
  turn on power switch of the top development board.
  
  Connect LDR PIN to Arduino Analog PIN-> 0(A0)
  ------------------------------------------------------------------
  22 march 2021
*/

int LDR = A0;// the number of the LDR pin.

void setup() {
  Serial.begin(9600);//starting serial communication between arduino and computer.

  pinMode(LDR, INPUT);//initializing LDR PIN as a input PIN.
}

void loop() {
  int LDR_VALUE = analogRead(LDR);//read and store the value of the LDR PIN in the variable called "LDR_VALUE".
  
  Serial.println(LDR_VALUE);//printing the value of "LDR_VALUE" variable to the serial monitor.
  
  delay(1000);//waiting for one second to be elapsed.
               
}
