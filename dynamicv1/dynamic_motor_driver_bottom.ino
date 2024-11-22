/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
   --------------------------------------------------------------------------
  Development Platform : Dynamic 1.0
  (mobile robot development platform)
  ---------------------------------------------------------------------------
  Motor Driver Example(Bottom Board).
  ---------------------------------------------------------------------------
  Hardware setup for Dynamic bottom development board :
  Motor Driver PINs are allready mapped and connected to
  the Arduino board.PINs are as follows :

  LEFT FRONT MOTOR   EN PIN connected to Arduino digital PIN -> 6(D6)
  LEFT FRONT MOTOR    A PIN connected to Arduino digital PIN -> 4(D4)
  LEFT FRONT MOTOR    B PIN connected to Arduino digital PIN -> 5(D5)

  LEFT BACK MOTOR    EN PIN connected to Arduino digital PIN -> 9(D9)
  LEFT BACK MOTOR     A PIN connected to Arduino digital PIN -> 7(D7)
  LEFT BACK MOTOR     B PIN connected to Arduino digital PIN -> 8(D8)

  RIGHT FRONT MOTOR  EN PIN connected to Arduino digital PIN -> 12(D12)
  RIGHT FRONT MOTOR   A PIN connected to Arduino digital PIN -> 10(D10)
  RIGHT FRONT MOTOR   B PIN connected to Arduino digital PIN -> 11(D11)

  RIGHT BACK MOTOR   EN PIN connected to Arduino analog PIN -> A0(A0)
  RIGHT BACK MOTOR    A PIN connected to Arduino analog PIN -> A2(A2)
  RIGHT BACK MOTOR    B PIN connected to Arduino analog PIN -> A1(A1)
   ---------------------------------------------------------------------------
  23 march 2021
*/

int LEFT_FRONT_MOTOR_EN = 6;// the number of the Arduino PIN, that left front motor EN PIN is connected to.
int LEFT_FRONT_MOTOR_A = 4;// the number of the Arduino PIN, that left front motor A PIN is connected to.
int LEFT_FRONT_MOTOR_B = 5;// the number of the Arduino PIN, that left front motor B PIN is connected to.

int LEFT_BACK_MOTOR_EN = 9;// the number of the Arduino PIN, that left back motor EN PIN is connected to.
int LEFT_BACK_MOTOR_B = 8;// the number of the Arduino PIN, that left back motor A PIN is connected to.
int LEFT_BACK_MOTOR_A = 7;// the number of the Arduino PIN, that left back motor B PIN is connected to.

int RIGHT_FRONT_MOTOR_EN = 12;// the number of the Arduino PIN, that right front motor EN PIN is connected to.
int RIGHT_FRONT_MOTOR_A = 10;// the number of the Arduino PIN, that right front motor A PIN is connected to.
int RIGHT_FRONT_MOTOR_B = 11;// the number of the Arduino PIN, that right front motor B PIN is connected to.

int RIGHT_BACK_MOTOR_EN = A0;// the number of the Arduino PIN, that right back motor EN PIN is connected to.
int RIGHT_BACK_MOTOR_A = A2;// the number of the Arduino PIN, that right back motor A PIN is connected to.
int RIGHT_BACK_MOTOR_B = A1;// the number of the Arduino PIN, that right back motor B PIN is connected to.


void setup() {

  //making all motor driver PINs as output PINs
  pinMode(LEFT_FRONT_MOTOR_EN, OUTPUT);
  pinMode(LEFT_FRONT_MOTOR_A, OUTPUT);
  pinMode(LEFT_FRONT_MOTOR_B, OUTPUT);

  pinMode(LEFT_BACK_MOTOR_EN, OUTPUT);
  pinMode(LEFT_BACK_MOTOR_A, OUTPUT);
  pinMode(LEFT_BACK_MOTOR_B, OUTPUT);

  pinMode(RIGHT_FRONT_MOTOR_EN, OUTPUT);
  pinMode(RIGHT_FRONT_MOTOR_A, OUTPUT);
  pinMode(RIGHT_FRONT_MOTOR_B, OUTPUT);

  pinMode(RIGHT_BACK_MOTOR_EN, OUTPUT);
  pinMode(RIGHT_BACK_MOTOR_A, OUTPUT);
  pinMode(RIGHT_BACK_MOTOR_B, OUTPUT);

  // turning all motors off at startup
  digitalWrite(LEFT_FRONT_MOTOR_A, LOW);
  digitalWrite(LEFT_FRONT_MOTOR_B, LOW);

  digitalWrite(LEFT_BACK_MOTOR_A, LOW);
  digitalWrite(LEFT_BACK_MOTOR_B, LOW);

  digitalWrite(RIGHT_FRONT_MOTOR_A, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_B, LOW);

  digitalWrite(RIGHT_BACK_MOTOR_A, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_B, LOW);
}

void loop() {
  SPEED_CONTROL();
  delay(2000);
  FOWARD();
  delay(2000);
  STOP() ;
  delay(2000);
  BACKWARDS();
  delay(2000);
}

void FOWARD() {
  // set motors to maximum speed.
  // PWM maximum possible values are 0 to 255.
  analogWrite(LEFT_FRONT_MOTOR_EN, 255);
  analogWrite(LEFT_BACK_MOTOR_EN, 255);
  analogWrite(RIGHT_FRONT_MOTOR_EN, 255);
  analogWrite(RIGHT_BACK_MOTOR_EN, 255);

  //driving all motors forward
  digitalWrite(LEFT_FRONT_MOTOR_A, LOW);
  digitalWrite(LEFT_FRONT_MOTOR_B, HIGH);
  digitalWrite(RIGHT_FRONT_MOTOR_A, HIGH);
  digitalWrite(RIGHT_FRONT_MOTOR_B, LOW);
  digitalWrite(LEFT_BACK_MOTOR_A, LOW);
  digitalWrite(LEFT_BACK_MOTOR_B, HIGH);
  digitalWrite(RIGHT_BACK_MOTOR_A, HIGH);
  digitalWrite(RIGHT_BACK_MOTOR_B, LOW);
}

void BACKWARDS() {
  // set motors to maximum speed.
  // PWM maximum possible values are 0 to 255.
  analogWrite(LEFT_FRONT_MOTOR_EN, 255);
  analogWrite(LEFT_BACK_MOTOR_EN, 255);
  analogWrite(RIGHT_FRONT_MOTOR_EN, 255);
  analogWrite(RIGHT_BACK_MOTOR_EN, 255);

  //driving all motors backwards
  digitalWrite(LEFT_FRONT_MOTOR_A, HIGH);
  digitalWrite(LEFT_FRONT_MOTOR_B, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_A, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_B, HIGH);

  digitalWrite(LEFT_BACK_MOTOR_A, HIGH);
  digitalWrite(LEFT_BACK_MOTOR_B, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_A, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_B, HIGH);
}

void STOP() {
  // turn off all motors.
  digitalWrite(LEFT_FRONT_MOTOR_A, LOW);
  digitalWrite(LEFT_FRONT_MOTOR_B, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_A, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_B, LOW);
  digitalWrite(LEFT_BACK_MOTOR_A, LOW);
  digitalWrite(LEFT_BACK_MOTOR_B, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_A, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_B, LOW);
}

void SPEED_CONTROL() {
  // Turn on motors
  digitalWrite(LEFT_FRONT_MOTOR_A, LOW);
  digitalWrite(LEFT_FRONT_MOTOR_B, HIGH);
  digitalWrite(RIGHT_FRONT_MOTOR_A, HIGH);
  digitalWrite(RIGHT_FRONT_MOTOR_B, LOW);
  digitalWrite(LEFT_BACK_MOTOR_A, LOW);
  digitalWrite(LEFT_BACK_MOTOR_B, HIGH);
  digitalWrite(RIGHT_BACK_MOTOR_A, HIGH);
  digitalWrite(RIGHT_BACK_MOTOR_B, LOW);


  // accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++) {
    analogWrite(LEFT_FRONT_MOTOR_EN, i);
    analogWrite(RIGHT_FRONT_MOTOR_EN, i);
    analogWrite(LEFT_BACK_MOTOR_EN, i);
    analogWrite(RIGHT_BACK_MOTOR_EN, i);
    delay(20);
  }

  // decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i) {
    analogWrite(LEFT_FRONT_MOTOR_EN, i);
    analogWrite(RIGHT_FRONT_MOTOR_EN, i);
    analogWrite(LEFT_BACK_MOTOR_EN, i);
    analogWrite(RIGHT_BACK_MOTOR_EN, i);
    delay(20);
  }

  // turning all motors off
  digitalWrite(LEFT_FRONT_MOTOR_A, LOW);
  digitalWrite(LEFT_FRONT_MOTOR_B, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_A, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_B, LOW);
  digitalWrite(LEFT_BACK_MOTOR_A, LOW);
  digitalWrite(LEFT_BACK_MOTOR_B, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_A, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_B, LOW);
}
