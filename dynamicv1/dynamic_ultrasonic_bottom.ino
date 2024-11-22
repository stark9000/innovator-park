/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  -----------------------------------------------------------------
  Development Platform : Dynamic 1.0
  (mobile robot development platform)
  -----------------------------------------------------------------
  hc-sr04 Ultrasonic Distance Sensor Example.
  -----------------------------------------------------------------
  Hardware setup :
  PINS of the ultrasonic sensors are already mapped and
  connected.PINs are as follows :

  front ultrasonic sensor TRIG PIN -> Arduino analog PIN 5(A5)
  front ultrasonic sensor ECHO PIN -> Arduino analog PIN 4(A4)

  -----------------------------------------------------------------
  23 march 2021
*/

const int  TRIG_PIN = A5; // the number of the PIN, that front ultrasonic sensor's trigger PIN is connected to.
const int  ECHO_PIN = A4;// the number of the PIN, that front ultrasonic sensor's echo PIN is connected to.

long  DURATION;//variable to store the duration.
int  DISTANCE;//variable to store the duration.


void setup() {

  //initializing all TRIG PINs as outputs.
  pinMode(TRIG_PIN, OUTPUT);

  //initializing all ECHO PINs as outputs.
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600);//starting serial communication between arduino and computer.
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);//turning off the trigger if its already on.
  delayMicroseconds(2);//waiting for two microseconds.

  //doing the calculations
  DURATION = pulseIn(ECHO_PIN, HIGH);
  DISTANCE = DURATION * 0.034 / 2;

  //printing calculations to the serial monitor.
  Serial.print("DISTANCE: ");
  Serial.print(DISTANCE);

}
