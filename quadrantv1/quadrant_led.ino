/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------
  Development Platform : Quadrant 1.0
  (embedded development platform)
  --------------------------------------------------------
  LED Example.
  --------------------------------------------------------
  Hardware setup :
  Connect LED1 PIN to Arduino Digital PIN-> 2(D2)
  Connect LED2 PIN to Arduino Digital PIN-> 3(D3)
  Connect LED3 PIN to Arduino Digital PIN-> 4(D4)
  Connect LED4 PIN to Arduino Digital PIN-> 5(D5)
  Connect LED5 PIN to Arduino Digital PIN-> 6(D6)
  Connect LED6 PIN to Arduino Digital PIN-> 7(D7)
  Connect LED7 PIN to Arduino Digital PIN-> 8(D8)
  --------------------------------------------------------
  24 march 2021
*/

int LED1 = 2; // the number of the LED1 PIN.
int LED2 = 3; // the number of the LED2 PIN.
int LED3 = 4; // the number of the LED3 PIN.
int LED4 = 5; // the number of the LED4 PIN.
int LED5 = 6; // the number of the LED5 PIN.
int LED6 = 7; // the number of the LED6 PIN.
int LED7 = 8; // the number of the LED7 PIN.

void setup() {
  //initializing ALL LED PINs as a output PINs.
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
}

void loop() {
  //making all LEDs on
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  digitalWrite(LED6, HIGH);
  digitalWrite(LED7, HIGH);
  
  delay(1000);//waiting for one second to be elapsed.

  //making all LEDs off
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, LOW);
  
  delay(1000);//waiting for one second to be elapsed.
}
