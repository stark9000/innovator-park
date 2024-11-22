/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------
  Development Platform : Quadrant 1.0
  (embedded development platform)
  --------------------------------------------------------
  Motor Driver Example.
  --------------------------------------------------------
    Hardware setup :
  // Motor A connections
    connect M1_EN to Arduino digital PIN-> 5(D5)

    connect M1_A to Arduino digital PIN-> 3(D3)

    connect M1_B to Arduino digital PIN-> 4(D4)

    // Motor B connections
    connect M2_EN to Arduino digital PIN-> 6(D6)

    connect M2_A to Arduino Digital PIN-> 7(D7)

    connect M2_B to Arduino Digital PIN-> 8(D8)
  --------------------------------------------------------
  24 march 2021
*/


// Motor A connections
int M1_EN = 5;//the number of the M1_EN pin.
int M1_A = 3;//the number of the M1_A pin.
int M1_B = 4;//the number of the M1_B pin.
// Motor B connections
int M2_EN = 6;//the number of the M2_EN pin.
int M2_A = 7;//the number of the M2_A pin.
int M2_B = 8;//the number of the M2_B pin.

void setup() {
  // Set all the motor control pins to outputs
  pinMode(M1_EN, OUTPUT);
  pinMode(M2_EN, OUTPUT);
  pinMode(M1_A, OUTPUT);
  pinMode(M1_B, OUTPUT);
  pinMode(M2_A, OUTPUT);
  pinMode(M2_B, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(M1_A, LOW);
  digitalWrite(M1_B, LOW);
  digitalWrite(M2_A, LOW);
  digitalWrite(M2_B, LOW);
}

void loop() {
  directionControl();
  delay(1000);
  speedControl();
  delay(1000);
}

// This function lets you control spinning direction of motors
void directionControl() {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(M1_EN, 255);
  analogWrite(M2_EN, 255);

  // Turn on motor A & B
  digitalWrite(M1_A, HIGH);
  digitalWrite(M1_B, LOW);
  digitalWrite(M2_A, HIGH);
  digitalWrite(M2_B, LOW);
  delay(2000);

  // Now change motor directions
  digitalWrite(M1_A, LOW);
  digitalWrite(M1_B, HIGH);
  digitalWrite(M2_A, LOW);
  digitalWrite(M2_B, HIGH);
  delay(2000);

  // Turn off motors
  digitalWrite(M1_A, LOW);
  digitalWrite(M1_B, LOW);
  digitalWrite(M2_A, LOW);
  digitalWrite(M2_B, LOW);
}

// This function lets you control speed of the motors
void speedControl() {
  // Turn on motors
  digitalWrite(M1_A, LOW);
  digitalWrite(M1_B, HIGH);
  digitalWrite(M2_A, LOW);
  digitalWrite(M2_B, HIGH);

  // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++) {
    analogWrite(M1_EN, i);
    analogWrite(M2_EN, i);
    delay(20);
  }

  // Decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i) {
    analogWrite(M1_EN, i);
    analogWrite(M2_EN, i);
    delay(20);
  }

  // Now turn off motors
  digitalWrite(M1_A, LOW);
  digitalWrite(M1_B, LOW);
  digitalWrite(M2_A, LOW);
  digitalWrite(M2_B, LOW);
}
