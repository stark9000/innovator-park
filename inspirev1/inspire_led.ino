/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------
  Development Platform : Inspire 1.0
  (Arduino development platform)
  --------------------------------------------------------
  LED Blink Example.
  --------------------------------------------------------
  Hardware setup :
  Connect LED1 PIN to Arduino Digital PIN-> 2(D2)
  --------------------------------------------------------
  22 march 2021
*/
int LED1 = 2;// the number of the LED 1 pin.

void setup() {
  pinMode(LED1, OUTPUT);//initializing LED1 pin as a output pin.
}

void loop() {
  digitalWrite(LED1, HIGH);//turning on the led.

  delay(1000);//waiting for one second to be elapsed.

  digitalWrite(LED1, LOW);//turning off the led.

  delay(1000);//waiting for one second to be elapsed.
}