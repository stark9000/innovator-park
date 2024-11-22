/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ------------------------------------------------------------------------------
  Development Platform : Inspire 1.0
  (Arduino development platform)
  ------------------------------------------------------------------------------
  Direction Indicators Example (BOTTOM Board).
  ------------------------------------------------------------------------------
  Hardware setup :
  plug in a Arduino nano board to the inspire bottom
  develepment board.
  ------------------------------------------------------------------------------
  Connections to the indicators allready maped and
  Connected as follows:

  LED_FORWARD ->(LED:D9 AND LED:D16) connected to arduino analog PIN 5(A5)
  LED_LEFT    ->(LED:D10) connected to arduino digital PIN 12(D12)
  LED_RIGHT   ->(LED:D11) connected to arduino digital PIN 13(D13)
  LED_BACK    ->(LED:D13 AND LED:D15)connected to arduino digital PIN 1(D1)
  LED_STOP    ->(LED:D12 AND LED:D14) connected to arduino digital PIN 0(D0)
  ------------------------------------------------------------------------------
  if you want to control direction indicators with top development platform
  use "Move Indicators" PINs.
  ------------------------------------------------------------------------------
  22 march 2021
*/

byte LED_FORWARD = A5;
byte LED_LEFT = 12;
byte LED_RIGHT = 13;
byte LED_BACK = 1;
byte LED_STOP = 0;

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
