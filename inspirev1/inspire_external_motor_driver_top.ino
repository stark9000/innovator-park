/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ----------------------------------------------------------------------------
  Development Platform : Inspire 1.0
  (Arduino development platform)
  ----------------------------------------------------------------------------
  External Motor Driver Example(Top Board).
  ----------------------------------------------------------------------------
  Hardware setup :
  plug a Arduino nano board in to the inspre bottom development board.
  turn on both power & motor power switchs of the bottom development board.

  --------------------------------left motor----------------------------------
  Connect M1EN to Arduino digital PIN-> 5(D5)

  Connect IN1  to Arduino digital PIN-> 3(D3)

  Connect IN2  to Arduino digital PIN-> 4(D4)

  --------------------------------right motor---------------------------------
  Connect M2EN to Arduino digital PIN-> 6(D6)

  Connect IN3  to Arduino digital PIN-> 7(D7)

  Connect IN4  to Arduino Digital PIN-> 8(D8)
  ----------------------------------------------------------------------------
  22 march 2021
*/

int M1EN = 5; //initializing M1EN pin as a output pin.

int IN1 = 3;//initializing IN1 pin as a output pin.

int IN2 = 4;//initializing IN2 pin as a output pin.

int M2EN = 6;//initializing M2EN pin as a output pin.

int IN3 = 7;//initializing IN3 pin as a output pin.

int IN4 = 8;//initializing IN4 pin as a output pin.


void setup() {
  // initializing all the motor control pins to be outputs.
  pinMode(M1EN, OUTPUT);
  pinMode(M2EN, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN3, OUTPUT);

  // turning off all motors.
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
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

  analogWrite(M1EN, 255);

  analogWrite(M2EN, 255);

  // turning on motor 1 and 2.
  digitalWrite(IN1, HIGH);

  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);

  digitalWrite(IN4, LOW);

  delay(2000);

  // changing motor directions.
  digitalWrite(IN1, LOW);

  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);

  digitalWrite(IN4, HIGH);

  delay(2000);

  // turn off all motors.
  digitalWrite(IN1, LOW);

  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);

  digitalWrite(IN4, LOW);
}


void speedControl() {
  // turn on motors
  digitalWrite(IN1, LOW);

  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);

  digitalWrite(IN4, HIGH);

  // accelerate from zero to maximum speed.
  for (int i = 0; i < 256; i++) {
    analogWrite(M1EN, i);

    analogWrite(M2EN, i);

    delay(20);
  }

  // de-accelerate from maximum speed to zero.
  for (int i = 255; i >= 0; --i) {
    analogWrite(M1EN, i);

    analogWrite(M2EN, i);

    delay(20);
  }

  // turning off all motors.
  digitalWrite(IN1, LOW);

  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);

  digitalWrite(IN4, LOW);
}
