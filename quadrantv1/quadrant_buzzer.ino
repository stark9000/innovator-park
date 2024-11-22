/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------
  Development Platform : Quadrant 1.0
  (embedded development platform)
  --------------------------------------------------------
  Buzzer Example.
  --------------------------------------------------------
  Hardware setup :
  Connect BUZ PIN to Arduino Digital (PWM)PIN-> 3(D3)
  --------------------------------------------------------
  24 march 2021
*/

int BUZZER = 3;// the number of the BUZZER pin.
int Frequency = 200;      // Starting frequency

void setup() {
  pinMode(BUZZER, OUTPUT);//initializing BUZZER pin as a output pin.
}

void loop() {
// Buzzer without tone
  digitalWrite(BUZZER, HIGH);//turning on the BUZZER.
  delay(1000);//waiting for one second to be elapsed.
  digitalWrite(BUZZER, LOW);//turning off the BUZZER.
  delay(1000);//waiting for one second to be elapsed.
  
// Buzzer With tone

tone(BUZZER,Frequency);
delay(500);
noTone(BUZZER);
delay(500);

  
}
