/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ----------------------------------------------------------------------------
  Development Platform : Dynamic 1.0
  (mobile robot development platform)
  ----------------------------------------------------------------------------
  IR Proximity Example.
  ----------------------------------------------------------------------------
  Hardware setup :
  PINs of the IR Sensor's mounted around the top development board are
  already mapped and connected.PINs are as follows :

  IR FRONT LEFT  : Arduino digital PIN -> 49(D49)
  IR FRONT RIGHT : Arduino digital PIN -> 50(D50)
  IR RIGHT       : Arduino digital PIN -> 48(D48)
  IR BACK RIGHT  : Arduino digital PIN -> 47(D47)
  IR BACK LEFT   : Arduino digital PIN -> 42(D42)
  IR LEFT        : Arduino digital PIN -> 41(D41)
  ----------------------------------------------------------------------------
  23 march 2021
*/


int IR_FRONT_LEFT = 49;// the number of the Arduino PIN, that front left IR sensor is connected to.
int IR_FRONT_RIGHT = 50;// the number of the Arduino PIN, that front right IR sensor is connected to.

int IR_LEFT = 48;// the number of the Arduino PIN, that left IR sensor is connected to.
int IR_RIGHT = 47;// the number of the Arduino PIN, that right IR sensor is connected to.

int IR_BACK_LEFT = 42;// the number of the Arduino PIN, that back left IR sensor is connected to.
int IR_BACK_RIGHT = 41;// the number of the Arduino PIN, that back right IR sensor is connected to.

int s1, s2, s3, s4, s5, s6; //creating variables to hold ir sensor readings.

void setup() {
  Serial.begin(9600); //starting serial communication between arduino and computer.
}

void loop() {

  //reading and printing each sensors value in to the serial monitor
  
  s1 = digitalRead(IR_FRONT_LEFT);
  Serial.print(s1);
  Serial.print("\t");


  s2 = digitalRead(IR_FRONT_RIGHT);
  Serial.print(s2);
  Serial.print("\t");

  s3 = digitalRead(IR_LEFT);
  Serial.print(s3);
  Serial.print("\t");

  s4 = digitalRead(IR_RIGHT);
  Serial.print(s4);
  Serial.print("\t");

  s5 = digitalRead(IR_BACK_LEFT);
  Serial.print(s5);
  Serial.print("\t");

  s6 = digitalRead(IR_BACK_RIGHT);
  Serial.print(s6);
  Serial.print("\t");

  Serial.println("end");
}
