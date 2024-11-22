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
  front ultrasonic sensor ECHO PIN -> Arduino analog PIN 43(D43)

  left ultrasonic sensor TRIG PIN -> Arduino analog PIN 11(D11)
  left ultrasonic sensor ECHO PIN -> Arduino analog PIN 12(D12)

  right ultrasonic sensor TRIG PIN -> Arduino analog PIN 17(D17)
  right ultrasonic sensor ECHO PIN -> Arduino analog PIN 16(D16)
  -----------------------------------------------------------------
  23 march 2021
*/

const int FRONT_TRIG_PIN = A5; // the number of the PIN, that front ultrasonic sensor's trigger PIN is connected to.
const int FRONT_ECHO_PIN = 43;// the number of the PIN, that front ultrasonic sensor's echo PIN is connected to.

const int LEFT_TRIG_PIN = 11;// the number of the PIN, that left ultrasonic sensor's trigger PIN is connected to.
const int LEFT_ECHO_PIN = 12;// the number of the PIN, that left ultrasonic sensor's echo PIN is connected to.

const int RIGHT_TRIG_PIN = 17;// the number of the PIN, that right ultrasonic sensor's trigger PIN is connected to.
const int RIGHT_ECHO_PIN = 16;// the number of the PIN, that right ultrasonic sensor's echo PIN is connected to.

long FRONT_DURATION;//variable to store the duration.
int FRONT_DISTANCE;//variable to store the duration.

long LEFT_DURATION;//variable to store the duration.
int LEFT_DISTANCE;//variable to store the duration.

long RIGHT_DURATION;//variable to store the duration.
int RIGHT_DISTANCE;//variable to store the duration.

void setup() {

  //initializing all TRIG PINs as outputs.
  pinMode(FRONT_TRIG_PIN, OUTPUT);
  pinMode(LEFT_TRIG_PIN, OUTPUT);
  pinMode(RIGHT_TRIG_PIN, OUTPUT);

  //initializing all ECHO PINs as outputs.
  pinMode(FRONT_ECHO_PIN, INPUT);
  pinMode(LEFT_ECHO_PIN, INPUT);
  pinMode(RIGHT_ECHO_PIN, INPUT);

  Serial.begin(9600);//starting serial communication between arduino and computer.
}

void loop() {

  
  //-------------------------front ultrasonic sensor------------------------------
  
  digitalWrite(FRONT_TRIG_PIN, LOW);//turning off the trigger if its already on.
  delayMicroseconds(2);//waiting for two microseconds.

  digitalWrite(FRONT_TRIG_PIN, HIGH);//turning on the trigger.
  delayMicroseconds(10);//waiting for ten microseconds.

  digitalWrite(FRONT_TRIG_PIN, LOW);//turning off the trigger.

  //doing the calculations
  FRONT_DURATION = pulseIn(FRONT_ECHO_PIN, HIGH);
  FRONT_DISTANCE = FRONT_DURATION * 0.034 / 2;

  //printing calculations to the serial monitor.
  Serial.print("FRONT_DISTANCE: ");
  Serial.print(FRONT_DISTANCE);

  
//  //-------------------------left ultrasonic sensor------------------------------
  
  digitalWrite(LEFT_TRIG_PIN, LOW);//turning off the trigger if its already on.
  delayMicroseconds(2);//waiting for two microseconds.
  
  digitalWrite(LEFT_TRIG_PIN, HIGH);//turning on the trigger.
  delayMicroseconds(10);//waiting for ten microseconds.
  
  digitalWrite(LEFT_TRIG_PIN, LOW);//turning off the trigger.
  
  //doing the calculations
  LEFT_DURATION = pulseIn(LEFT_ECHO_PIN, HIGH);
  LEFT_DISTANCE = LEFT_DURATION * 0.034 / 2;
  
  //printing calculations to the serial monitor.
  Serial.print("  LEFT_DISTANCE: ");
  Serial.print(LEFT_DISTANCE);

  
  //-------------------------right ultrasonic sensor------------------------------
  
  digitalWrite(RIGHT_TRIG_PIN, LOW);//turning off the trigger if its already on.
  delayMicroseconds(2);//waiting for two microseconds.
  
  digitalWrite(RIGHT_TRIG_PIN, HIGH);//turning on the trigger.
  delayMicroseconds(10);//waiting for ten microseconds.
  
  digitalWrite(RIGHT_TRIG_PIN, LOW);//turning off the trigger.
  
  //doing the calculations
  RIGHT_DURATION = pulseIn(RIGHT_ECHO_PIN, HIGH);
  RIGHT_DISTANCE = RIGHT_DURATION * 0.034 / 2;

  //printing calculations to the serial monitor.
  Serial.print("  RIGHT_DISTANCE: ");
  Serial.println(RIGHT_DISTANCE);
}
