/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  -------------------------------------------------------------------
  Development Platform : Inspire 1.0
  (Arduino development platform)
  -------------------------------------------------------------------
  Buzzer Example.
  -------------------------------------------------------------------
  Hardware setup :
  plug a Arduino nano board in to the inspre top development board.
  turn on power switch of the top development board.

  Connect BUZ PIN to Arduino Digital PIN-> 3(D3)
  -------------------------------------------------------------------
  22 march 2021
*/

int BUZZER = 3;//the number of the buzzer PIN.

void setup() {
  pinMode(BUZZER, OUTPUT);//initializing BUZZER PIN as a output PIN.
}

void loop() {
  digitalWrite(BUZZER, HIGH);//turning on the buzzer.

  delay(1000);//waiting for one second to be elapsed.

  digitalWrite(BUZZER, LOW);//turning off the buzzer.

  delay(1000);//waiting for one second to be elapsed.
}
