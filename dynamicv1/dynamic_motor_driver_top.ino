/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
   --------------------------------------------------------------------------
  Development Platform : Dynamic 1.0
  (mobile robot development platform)
  ---------------------------------------------------------------------------
  Motor Driver Example(Top Board).
  ---------------------------------------------------------------------------
  Hardware setup for Dynamic top development board :
  Motor Driver PINs are allready mapped and connected to
  the Arduino board.PINs are as follows :

  LEFT FRONT MOTOR   EN PIN connected to Arduino digital PIN -> 8(D8)
  LEFT FRONT MOTOR    A PIN connected to Arduino digital PIN -> 26(D26)
  LEFT FRONT MOTOR    B PIN connected to Arduino digital PIN -> 27(D27)

  LEFT BACK MOTOR    EN PIN connected to Arduino digital PIN -> 7(D8)
  LEFT BACK MOTOR     A PIN connected to Arduino digital PIN -> 6(D8)
  LEFT BACK MOTOR     B PIN connected to Arduino digital PIN -> 5(D8)

  RIGHT FRONT MOTOR  EN PIN connected to Arduino digital PIN -> 10(D10)
  RIGHT FRONT MOTOR   A PIN connected to Arduino digital PIN -> 28(D28)
  RIGHT FRONT MOTOR   B PIN connected to Arduino digital PIN -> 29(D29)

  RIGHT BACK MOTOR   EN PIN connected to Arduino digital PIN -> 9(D9)
  RIGHT BACK MOTOR    A PIN connected to Arduino digital PIN -> 30(D30)
  RIGHT BACK MOTOR    B PIN connected to Arduino digital PIN -> 31(D31)

  23 march 2021
*/

int LEFT_FRONT_MOTOR_EN = 8;// the number of the Arduino PIN, that left front motor EN PIN is connected to.
int LEFT_FRONT_MOTOR_A = 26;// the number of the Arduino PIN, that left front motor A PIN is connected to.
int LEFT_FRONT_MOTOR_B = 27;// the number of the Arduino PIN, that left front motor B PIN is connected to.

int LEFT_BACK_MOTOR_EN = 7;// the number of the Arduino PIN, that left back motor EN PIN is connected to.
int LEFT_BACK_MOTOR_B = 5;// the number of the Arduino PIN, that left back motor A PIN is connected to.
int LEFT_BACK_MOTOR_A = 6;// the number of the Arduino PIN, that left back motor B PIN is connected to.

int RIGHT_FRONT_MOTOR_EN = 10;// the number of the Arduino PIN, that right front motor EN PIN is connected to.
int RIGHT_FRONT_MOTOR_A = 28;// the number of the Arduino PIN, that right front motor A PIN is connected to.
int RIGHT_FRONT_MOTOR_B = 29;// the number of the Arduino PIN, that right front motor B PIN is connected to.

int RIGHT_BACK_MOTOR_EN = 9;// the number of the Arduino PIN, that right back motor EN PIN is connected to.
int RIGHT_BACK_MOTOR_A = 30;// the number of the Arduino PIN, that right back motor A PIN is connected to.
int RIGHT_BACK_MOTOR_B = 31;// the number of the Arduino PIN, that right back motor B PIN is connected to.


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
  SPEED_CONTROL();//0 to 255 pwm speed control.
  delay(2000);//waiting for 2 seconds.
  FOWARD();//turning all motors forward.
  delay(2000);//waiting for 2 seconds.
  STOP() ;//stopping all motors.
  delay(2000);//waiting for 2 seconds.
  BACKWARDS();//running all motors backward.
  delay(2000);//waiting for 2 seconds.
  LEFT();
  delay(2000);//waiting for 2 seconds.
  RIGHT();
  delay(2000);//waiting for 2 seconds.
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
  digitalWrite(RIGHT_FRONT_MOTOR_A, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_B, HIGH);

  digitalWrite(LEFT_BACK_MOTOR_A, LOW);
  digitalWrite(LEFT_BACK_MOTOR_B, HIGH);
  digitalWrite(RIGHT_BACK_MOTOR_A, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_B, HIGH);
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
  digitalWrite(RIGHT_FRONT_MOTOR_A, HIGH);
  digitalWrite(RIGHT_FRONT_MOTOR_B, LOW);

  digitalWrite(LEFT_BACK_MOTOR_A, HIGH);
  digitalWrite(LEFT_BACK_MOTOR_B, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_A, HIGH);
  digitalWrite(RIGHT_BACK_MOTOR_B, LOW);
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

void LEFT() {
  analogWrite(LEFT_FRONT_MOTOR_EN, 255);
  analogWrite(LEFT_BACK_MOTOR_EN, 255);
  analogWrite(RIGHT_FRONT_MOTOR_EN, 255);
  analogWrite(RIGHT_BACK_MOTOR_EN, 255);

  digitalWrite(LEFT_FRONT_MOTOR_A, HIGH);
  digitalWrite(LEFT_FRONT_MOTOR_B, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_A, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_B, HIGH);

  digitalWrite(LEFT_BACK_MOTOR_A, HIGH);
  digitalWrite(LEFT_BACK_MOTOR_B, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_A, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_B, HIGH);
}
void RIGHT() {
  analogWrite(LEFT_FRONT_MOTOR_EN, 255);
  analogWrite(LEFT_BACK_MOTOR_EN, 255);
  analogWrite(RIGHT_FRONT_MOTOR_EN, 255);
  analogWrite(RIGHT_BACK_MOTOR_EN, 255);

  digitalWrite(LEFT_FRONT_MOTOR_A, LOW);
  digitalWrite(LEFT_FRONT_MOTOR_B, HIGH);
  digitalWrite(RIGHT_FRONT_MOTOR_A, HIGH);
  digitalWrite(RIGHT_FRONT_MOTOR_B, LOW);

  digitalWrite(LEFT_BACK_MOTOR_A, LOW);
  digitalWrite(LEFT_BACK_MOTOR_B, HIGH);
  digitalWrite(RIGHT_BACK_MOTOR_A, HIGH);
  digitalWrite(RIGHT_BACK_MOTOR_B, LOW);

}

void SPEED_CONTROL() {
  digitalWrite(LEFT_FRONT_MOTOR_A, LOW);
  digitalWrite(LEFT_FRONT_MOTOR_B, HIGH);
  digitalWrite(RIGHT_FRONT_MOTOR_A, LOW);
  digitalWrite(RIGHT_FRONT_MOTOR_B, HIGH);

  digitalWrite(LEFT_BACK_MOTOR_A, LOW);
  digitalWrite(LEFT_BACK_MOTOR_B, HIGH);
  digitalWrite(RIGHT_BACK_MOTOR_A, LOW);
  digitalWrite(RIGHT_BACK_MOTOR_B, HIGH);

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
