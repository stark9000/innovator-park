/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ----------------------------------------------------------------------
  Development Platform : Quadrant 1.0
  (embedded development platform)
  ----------------------------------------------------------------------
  hc-sr04 Ultrasonic Distance Sensor Example.
  ----------------------------------------------------------------------
  Hardware setup :
  connect ECHO PIN of the HC-SR04 module to Arduino digital PIN 2(D2)
  connect TRIG PIN of the HC-SR04 module to Arduino digital PIN 3(D3)
  ----------------------------------------------------------------------
  24 march 2021
*/

int TRIG = 2;// the number of the ECHO pin.
int ECHO = 3;// the number of the TRIG pin.


long duration; // variable to hold the duration of sound wave travel value.
int distance; // variable to hold the distance measurement value.

void setup() {
  pinMode(TRIG, OUTPUT); //initializing TRIG pin as a output pin.
  pinMode(ECHO, INPUT); //initializing ECHO pin as a input pin.

  Serial.begin(9600); //starting serial communication between arduino and computer.
}
void loop() {
  // making the TRIG pin LOW for 2 microseconds.
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  // making the TRIG pin HIGH for 10 microseconds.
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // reads the ECHO pin value and returns the sound wave travel time in microseconds.
  duration = pulseIn(ECHO, HIGH);
  // calculating the distance.
  distance = duration * 0.034 / 2; // speed of sound wave divided by 2 (to go forward and reflect on something and come back).

  // displays the calculated distance in the serial monitor.
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
