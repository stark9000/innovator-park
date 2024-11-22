/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ----------------------------------------------------------------------------
  Development Platform : Inspire 1.0
  (Arduino development platform)
  ----------------------------------------------------------------------------
  Motor Driver Example(Bottom Board).
  ----------------------------------------------------------------------------
  Hardware setup :
  plug a Arduino nano board in to the inspre bottom development board.
  turn on both power & motor power switchs of the bottom development board.

  --------------------------------left motor----------------------------------
  Connect LEFT MOTOR EN to Arduino digital PIN-> 5(D5)

  Connect LEFT MOTOR A  to Arduino digital PIN-> 3(D4)

  Connect LEFT MOTOR B  to Arduino digital PIN-> 4(D3)

  --------------------------------right motor---------------------------------
  Connect RIGHT MOTOR EN to Arduino digital PIN-> 6(D6)

  Connect RIGHT MOTOR A  to Arduino digital PIN-> 7(D7)

  Connect RIGHT MOTOR B  to Arduino Digital PIN-> 8(D8)
  ----------------------------------------------------------------------------
  22 march 2021
*/

int LEFT_MOTOR_EN = 5; //initializing LEFT_MOTOR_EN pin as a output pin.

int LEFT_MOTOR_A = 4;//initializing LEFT_MOTOR_A pin as a output pin.

int LEFT_MOTOR_B = 3;//initializing LEFT_MOTOR_B pin as a output pin.

int RIGHT_MOTOR_EN = 6;//initializing RIGHT_MOTOR_EN pin as a output pin.

int RIGHT_MOTOR_A = 7;//initializing RIGHT_MOTOR_A pin as a output pin.

int RIGHT_MOTOR_B = 8;//initializing RIGHT_MOTOR_B pin as a output pin.


void setup() {
  // initializing all the motor control pins to be outputs.
  pinMode(LEFT_MOTOR_EN, OUTPUT);
  pinMode(RIGHT_MOTOR_EN, OUTPUT);

  pinMode(LEFT_MOTOR_A, OUTPUT);
  pinMode(LEFT_MOTOR_B, OUTPUT);

  pinMode(RIGHT_MOTOR_A, OUTPUT);
  pinMode(RIGHT_MOTOR_A, OUTPUT);

  // turning off all motors.
  digitalWrite(LEFT_MOTOR_A, LOW);
  digitalWrite(LEFT_MOTOR_B, LOW);

  digitalWrite(RIGHT_MOTOR_A, LOW);
  digitalWrite(RIGHT_MOTOR_B, LOW);
}

void loop() {
  directionControl(); // drive motors back and forth.

  delay(1000);//waiting for one second to be elapsed.

  speedControl();//controling the seed of the motors.

  delay(1000);//waiting for one second to be elapsed.
}


void directionControl() {
  // set motors to maximum speed.
  // PWM maximum possible values are 0 to 255.

  analogWrite(LEFT_MOTOR_EN, 255);

  analogWrite(RIGHT_MOTOR_EN, 255);

  // turning on motor 1 and 2.
  digitalWrite(LEFT_MOTOR_A, HIGH);

  digitalWrite(LEFT_MOTOR_B, LOW);

  digitalWrite(RIGHT_MOTOR_A, HIGH);

  digitalWrite(RIGHT_MOTOR_B, LOW);

  delay(2000);

  // changing motor directions.
  digitalWrite(LEFT_MOTOR_A, LOW);

  digitalWrite(LEFT_MOTOR_B, HIGH);

  digitalWrite(RIGHT_MOTOR_A, LOW);

  digitalWrite(RIGHT_MOTOR_B, HIGH);

  delay(2000);

  // turn off all motors.
  digitalWrite(LEFT_MOTOR_A, LOW);

  digitalWrite(LEFT_MOTOR_B, LOW);

  digitalWrite(RIGHT_MOTOR_A, LOW);

  digitalWrite(RIGHT_MOTOR_B, LOW);
}


void speedControl() {
  // turn on motors
  digitalWrite(LEFT_MOTOR_A, LOW);

  digitalWrite(LEFT_MOTOR_B, HIGH);

  digitalWrite(RIGHT_MOTOR_A, LOW);

  digitalWrite(RIGHT_MOTOR_B, HIGH);

  // accelerate from zero to maximum speed.
  for (int i = 0; i < 256; i++) {
    analogWrite(LEFT_MOTOR_EN, i);

    analogWrite(RIGHT_MOTOR_EN, i);

    delay(20);
  }

  // de-accelerate from maximum speed to zero.
  for (int i = 255; i >= 0; --i) {
    analogWrite(LEFT_MOTOR_EN, i);

    analogWrite(RIGHT_MOTOR_EN, i);

    delay(20);
  }

  // turning off all motors.
  digitalWrite(LEFT_MOTOR_A, LOW);

  digitalWrite(LEFT_MOTOR_B, LOW);

  digitalWrite(RIGHT_MOTOR_A, LOW);

  digitalWrite(RIGHT_MOTOR_B, LOW);
}
