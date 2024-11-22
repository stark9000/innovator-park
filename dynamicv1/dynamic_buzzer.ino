/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ----------------------------------------------------------------------------
  Development Platform : Dynamic 1.0
  (mobile robot development platform)
  ----------------------------------------------------------------------------
  Buzzer Example.
  ----------------------------------------------------------------------------
  Hardware setup :
  Buzzer PIN already mapped and connected to Arduino digital PIN -> 13(D13)
  ----------------------------------------------------------------------------
  23 march 2021
*/

int Buz = 13;// the number of the buzzer PIN.

void setup() {
  pinMode(Buz, OUTPUT);//initializing Buz pin as a output pin.
}

void loop() {
  digitalWrite(Buz, HIGH);//turning on the buzzer.
  delay(1000);//waiting one second to be elapsed.
  digitalWrite(Buz, LOW);//turning off the buzzer.
  delay(1000);//waiting one second to be elapsed.
}
