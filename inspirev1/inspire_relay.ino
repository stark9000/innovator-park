/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ------------------------------------------------------------------
  Development Platform : Inspire 1.0
  (Arduino development platform)
  ------------------------------------------------------------------
  Relay Example.
  ------------------------------------------------------------------
  Hardware setup :
  plug a Arduino nano board in to the inspre top development board.
  turn on power switch of the top development board.

  connect RLY PIN to Arduino Digital PIN-> 2(D2)
  ------------------------------------------------------------------
  22 march 2021
*/

int RELAY = 2;// the number of the RELAY pin.

void setup() {
  pinMode(RELAY, OUTPUT);//initializing RELAY pin as a output pin.
}

void loop() {
  digitalWrite(RELAY, HIGH);//turning on the relay.

  delay(1000);//waiting for one second to be elapsed.

  digitalWrite(RELAY, LOW);//turning off the relay.

  delay(1000);//waiting for one second to be elapsed.
}
