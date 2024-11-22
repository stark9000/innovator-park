/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  -----------------------------------------------------------------------------
  Development Platform : Inspire 1.0
  (Arduino development platform)
  -----------------------------------------------------------------------------
  Motor Driver Example(Top Board).
  -----------------------------------------------------------------------------
  Hardware setup :
  plug a Arduino nano board in to the inspre top development board.
  turn on both power switchs of the top development board & bottom one.

   --------------------------------left motor----------------------------------
    connect LEFT EN to Arduino Digital PIN-> 5(D5)

    connect LEFT A to Arduino Digital PIN-> 3(D4)

    connect LEFT B to Arduino Digital PIN-> 4(D3)

   --------------------------------right motor----------------------------------
    connect RIGHT EN to Arduino Analog PIN-> 6(D6)

    connect RIGHT A to Arduino Digital PIN-> 7(D7)

    connect RIGHT B to Arduino Digital PIN-> 8(D8)
  ----------------------------------------------------------------------------
  22 march 2021
*/

int LEFT_EN = 5; //initializing LEFT_EN pin as a output pin.

int LEFT_A = 4;//initializing LEFT_A pin as a output pin.

int LEFT_B = 3;//initializing LEFT_B pin as a output pin.

int RIGHT_EN = 6;//initializing RIGHT_EN pin as a output pin.

int RIGHT_A = 7;//initializing RIGHT_A pin as a output pin.

int RIGHT_B = 8;//initializing RIGHT_B pin as a output pin.


void setup() {
  // initializing all the motor control pins to be outputs.
  pinMode(LEFT_EN, OUTPUT);
  pinMode(RIGHT_EN, OUTPUT);

  pinMode(LEFT_A, OUTPUT);
  pinMode(LEFT_B, OUTPUT);

  pinMode(RIGHT_A, OUTPUT);
  pinMode(RIGHT_B, OUTPUT);

  // turning off all motors.
  digitalWrite(LEFT_A, LOW);
  digitalWrite(LEFT_B, LOW);

  digitalWrite(RIGHT_A, LOW);
  digitalWrite(RIGHT_B, LOW);
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

  analogWrite(LEFT_EN, 255);

  analogWrite(RIGHT_EN, 255);

  //left mortor foward
  digitalWrite(LEFT_A, HIGH);

  digitalWrite(LEFT_B, LOW);

  //---------------------------------
  //right mortor backward
  digitalWrite(RIGHT_A, HIGH);

  digitalWrite(RIGHT_B, LOW);

  //---------------------------------
  delay(2000);
  //---------------------------------
  // changing motor directions.

  //left mortor backward
  digitalWrite(LEFT_A, LOW);

  digitalWrite(LEFT_B, HIGH);

  //---------------------------------
  //right mortor foward
  digitalWrite(RIGHT_A, LOW);

  digitalWrite(RIGHT_B, HIGH);

  //---------------------------------
  delay(2000);

  //---------------------------------
  // turn off all motors.
  digitalWrite(LEFT_A, LOW);

  digitalWrite(LEFT_B, LOW);

  digitalWrite(RIGHT_A, LOW);

  digitalWrite(RIGHT_B, LOW);
}


void speedControl() {
  // turn on motors
  digitalWrite(LEFT_A, LOW);

  digitalWrite(LEFT_B, HIGH);

  digitalWrite(RIGHT_A, LOW);

  digitalWrite(RIGHT_B, HIGH);

  // accelerate from zero to maximum speed.
  for (int i = 0; i < 256; i++) {
    analogWrite(LEFT_EN, i);

    analogWrite(RIGHT_EN, i);

    delay(20);
  }

  // de-accelerate from maximum speed to zero.
  for (int i = 255; i >= 0; --i) {
    analogWrite(LEFT_EN, i);

    analogWrite(RIGHT_EN, i);

    delay(20);
  }

  // turning off all motors.
  digitalWrite(LEFT_A, LOW);

  digitalWrite(LEFT_B, LOW);

  digitalWrite(RIGHT_A, LOW);

  digitalWrite(RIGHT_B, LOW);
}
