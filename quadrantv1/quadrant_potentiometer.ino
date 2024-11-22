/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------
  Development Platform : Quadrant 1.0
  (embedded development platform)
  --------------------------------------------------------
  PotentioMeter Example.
  --------------------------------------------------------
  Hardware setup :
  Connect POT to Arduino analog PIN-> 0(A0)
  --------------------------------------------------------
  24 march 2021
*/

int Potentiometer = A0;//the number of the POT pin.
int value = 0;//a variable to hold the potentiometer value.

void setup() {
  pinMode(Potentiometer, INPUT);;//initializing POT pin as a input pin.
  Serial.begin(9600);//starting serial communication between arduino and computer.
}

void loop() {
  value = analogRead(Potentiometer);//read and store the value of the POT pin in the variable called "value".
  Serial.println(value);//printing the value of "value" variable to the serial monitor.
  delay(1000);//waiting for one second to be elapsed.
}
