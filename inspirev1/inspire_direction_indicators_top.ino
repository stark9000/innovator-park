/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------------------------
  Development Platform : Inspire 1.0
  (Arduino development platform)
  --------------------------------------------------------------------------
  Direction Indicators Example (TOP Board).
  --------------------------------------------------------------------------
   Hardware setup :
   plug in a Arduino nano board to the inspire top
   develepment board.
  --------------------------------------------------------------------------
   Connect "Move Indicators" PIN FW(FORWARD) to arduino digital PIN 2(D2)
   Connect "Move Indicators" PIN L (LEFT)    to arduino digital PIN 3(D3)
   Connect "Move Indicators" PIN R (RIGHT)   to arduino digital PIN 4(D4)
   Connect "Move Indicators" PIN BK(BACK)    to arduino digital PIN 5(D5)
   Connect "Move Indicators" PIN ST(STOP)    to arduino digital PIN 6(D6)
  --------------------------------------------------------------------------
  22 march 2021
*/

byte LED_FORWARD = 2;//the number of the Arduino digital PIN,that FW PIN connected to.

byte LED_LEFT = 3;//the number of the Arduino digital PIN,that L PIN connected to.

byte LED_RIGHT = 4;//the number of the Arduino digital PIN,that R PIN connected to.

byte LED_BACK = 5;//the number of the Arduino digital PIN,that BK PIN connected to.

byte LED_STOP = 6;//the number of the Arduino digital PIN,that ST PIN connected to.

boolean FW, BK, ST, L, R, count;

void setup() {
  //initializing all LED PINs as output PINs.
  pinMode(LED_FORWARD, OUTPUT);
  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);
  pinMode(LED_BACK, OUTPUT);
  pinMode(LED_STOP, OUTPUT);

  //turning all LEDs off at the begining.
  digitalWrite(LED_FORWARD, LOW);
  digitalWrite(LED_LEFT, LOW);
  digitalWrite(LED_RIGHT, LOW);
  digitalWrite(LED_BACK, LOW);
  digitalWrite(LED_STOP, LOW);
}

void loop() {
  for (int i = 0; i <= 10; i++) {
    forwardIndicator();
  }
  for (int i = 0; i <= 10; i++) {
    stopIndicator();
  }
  for (int i = 0; i <= 10; i++) {
    backwardIndicator();
  }
  for (int i = 0; i <= 10; i++) {
    leftIndicator();
  }

  for (int i = 0; i <= 10; i++) {
    rightIndicator();
  }
}

void leftIndicator() {
  digitalWrite(LED_LEFT, HIGH);
  digitalWrite(LED_RIGHT, LOW);
  delay(500);
  digitalWrite(LED_LEFT, LOW);
  delay(500);
}
void rightIndicator() {
  digitalWrite(LED_RIGHT, HIGH);
  digitalWrite(LED_LEFT, LOW);
  delay(500);
  digitalWrite(LED_RIGHT, LOW);
  delay(500);
}

void forwardIndicator() {
  digitalWrite(LED_FORWARD, HIGH);
  digitalWrite(LED_STOP, LOW);
  delay(500);
  digitalWrite(LED_FORWARD, LOW);
  delay(500);
}

void stopIndicator() {
  digitalWrite(LED_STOP, HIGH);
  digitalWrite(LED_FORWARD, LOW);
  delay(500);
  digitalWrite(LED_STOP, LOW);
  delay(500);
}

void backwardIndicator() {
  digitalWrite(LED_BACK, HIGH);
  digitalWrite(LED_FORWARD, LOW);
  delay(500);
  digitalWrite(LED_BACK, LOW);
  delay(500);
}
