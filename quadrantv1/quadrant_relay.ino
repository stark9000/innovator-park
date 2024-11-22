/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------
  Development Platform : Quadrant 1.0
  (embedded development platform)
  --------------------------------------------------------
  Relay Example.
  --------------------------------------------------------
  Hardware setup :
  Connect RELAY PIN to Arduino digital PIN 2(D2)
  --------------------------------------------------------
  24 march 2021
*/

int RELAY = 2;// the number of the RELAY pin.

void setup() {
  pinMode(RELAY, OUTPUT);//initializing RELAY pin as a output pin.
}

void loop() {
  digitalWrite(RELAY, HIGH);//turning on the RELAY.

  delay(1000);//waiting for one second to be elapsed.

  digitalWrite(RELAY, LOW);//turning off the RELAY.

  delay(1000);//waiting for one second to be elapsed.
}
