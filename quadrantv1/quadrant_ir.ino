/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------
  Development Platform : Quadrant 1.0
  (embedded development platform)
  --------------------------------------------------------
  TCRT5000 IR Sensor Example.
  --------------------------------------------------------
  Hardware setup :
  connect IR_LED PIN to Arduino Analog PIN-> 0(A0)
  connect IR_SEN PIN to Arduino Analog PIN-> 1(A1)
  --------------------------------------------------------
  24 march 2021
*/

int IR_Rx = A1;
int IR_Tx = A0;
int value = 0;

void setup() {
  pinMode(IR_Tx, OUTPUT);
  pinMode(IR_Rx, INPUT);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(IR_Rx);
  digitalWrite(IR_Tx, HIGH);
  Serial.println(value);
}
