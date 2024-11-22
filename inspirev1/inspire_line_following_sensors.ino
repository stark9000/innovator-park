/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ------------------------------------------------------------------
  Development Platform : Inspire 1.0
  (Arduino development platform)
  ------------------------------------------------------------------
  TRCT5000 IR Sensor(Line Following Sensors) Example.
  ------------------------------------------------------------------
  Hardware setup :
  plug a Arduino nano board in to the inspre top development board.
  turn on power switch of the both top & bottom development boards.

  Connect Line Tracing IR1 PIN to Arduino Digital PIN-> 2(D2)

  Connect Line Tracing IR2 PIN to Arduino Digital PIN-> 3(D3)

  Connect Line Tracing IR3 PIN to Arduino Digital PIN-> 4(D4)

  Connect Line Tracing IR4 PIN to Arduino Digital PIN-> 5(D5)

  Connect Line Tracing IR5 PIN to Arduino Digital PIN-> 6(D6)
  -----------------------------------------------------------------
  22 march 2021
*/

int IR1 = 2;// the number of the IR1 pin.
int IR2 = 3;// the number of the IR2 pin.
int IR3 = 4;// the number of the IR3 pin.
int IR4 = 5;// the number of the IR4 pin.
int IR5 = 6;// the number of the IR5 pin.

int s1, s2, s3, s4, s5; //creating five variables to hold the states of IR sensors.

void setup() {
  pinMode(IR1, INPUT);//initializing IR1 pin as a input pin.
  pinMode(IR2, INPUT);//initializing IR2 pin as a input pin.
  pinMode(IR3, INPUT);//initializing IR3 pin as a input pin.
  pinMode(IR4, INPUT);//initializing IR4 pin as a input pin.
  pinMode(IR5, INPUT);//initializing IR5 pin as a input pin.

  Serial.begin(9600);//starting serial communication between arduino and computer.
}

void loop() {
  s1 = digitalRead(IR1);//reading and storing the state of IR1 to s1 variable
  Serial.print(s1);//printing the value of "s1" variable to serial monitor.
  Serial.print("\t");//printing a tab character to serial monitor.


  s2 = digitalRead(IR2);//reading and storing the state of IR2 to s2 variable
  Serial.print(s2);//printing the value of "s2" variable to serial monitor.
  Serial.print("\t");//printing a tab character to serial monitor.

  s3 = digitalRead(IR3);//reading and storing the state of IR3 to s3 variable
  Serial.print(s3);//printing the value of "s3" variable to serial monitor.
  Serial.print("\t");//printing a tab character to serial monitor.

  s4 = digitalRead(IR4);//reading and storing the state of IR4 to s4 variable
  Serial.print(s4);//printing the value of "s4" variable to serial monitor.
  Serial.print("\t");//printing a tab character to serial monitor.

  s5 = digitalRead(IR5);//reading and storing the state of IR5 to s5 variable
  Serial.print(s5);//printing the value of "s5" variable to serial monitor.
  Serial.print("\t");//printing a tab character to serial monitor.

  Serial.println("end");//printing a line end with a string.
}
