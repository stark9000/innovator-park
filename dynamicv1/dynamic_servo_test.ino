/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------
  Development Platform : Dynamic 1.0
  (mobile robot development platform)
  --------------------------------------------------------
  Servo Motor Example.
  --------------------------------------------------------
  Hardware setup :
  Connect servo motors to "SERVO MOTORs" PINs located on
  top development board.
  --------------------------------------------------------
  SG90 servo motor PIN outs :
  //orange = pwm
  //red    = 5v
  //brown  = gnd
  --------------------------------------------------------
  23 march 2021
*/

#include <Servo.h> //including the servo library in order to use its functions.

// set the number of servo motors.
#define SERVOS  4
// creating the servo object to control a servo motor(s).
Servo myservo[SERVOS];

// attach servo motor(s) to digital PIN on the Arduino.
int servo_pins[SERVOS] = {4, 44, 45, 46}; //d4.15,d45.72

// default angle for the servo in degrees.
int default_pos[SERVOS] = {0};

void setup() {

  for (int i = 0; i < SERVOS; i++) {

    // attach the servo to the servo object.
    myservo[i].attach(servo_pins[i]);

    // make all the servos go to the default position.
    myservo[i].write(default_pos[i]);
  }

  // wait some time for the servo to get to the position.
  delay(15);
}

void loop() {

  // go from 0 degrees to 180 degrees.
  // move in steps of 1 degree.
  for (int angle = 0; angle <= 180; angle += 1) {

    // update the angle for all servos
    for (int i = 0; i < SERVOS; i++) {

      // tell servo to go to the position in variable 'angle'
      // where 'angle' is in degrees.
      myservo[i].write(angle);

      // wait some time for the servo to get to the position.
      delay(15);
    }
  }

  // go from 180 degrees to 0 degrees.
  // move in steps of 1 degree.
  for (int angle = 180; angle >= 0; angle -= 1) {

    // update the angle for all servos
    for (int i = 0; i < SERVOS; i++) {

      // tell servo to go to the position in variable 'angle'
      // where 'angle' is in degrees.
      myservo[i].write(angle);

      // wait some time for the servo to get to the position.
      delay(15);
    }
  }
}
