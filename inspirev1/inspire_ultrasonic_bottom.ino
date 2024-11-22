/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ------------------------------------------------------------------
  Development Platform : Inspire 1.0
  (Arduino development platform)
  ------------------------------------------------------------------
  hc-sr04 Ultrasonic Distance Sensor Example.
  ------------------------------------------------------------------
  Hardware setup :
  plug a Arduino nano board in to the inspre top development board.
  turn on power switch of the top development board.
  
  connect ECHO PIN to Arduino Digital PIN-> 11(D11)
  connect TRIG PIN to Arduino Digital PIN-> 10(D10)
  ------------------------------------------------------------------
  22 march 2021
*/

int ECHO = 11;// the number of the ECHO pin.

int TRIG = 10;// the number of the TRIG pin.


long duration; //a variable to hold the duration of sound wave travel value.

int distance; //a variable to hold the distance measurement value.

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
  distance = duration * 0.034 / 2; //speed of sound wave divided by 2 (to go forward and reflect on something and come back).

  // displays the calculated distance in the serial monitor.
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
