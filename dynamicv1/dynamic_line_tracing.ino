/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  -------------------------------------------------------------------
  Development Platform : Dynamic 1.0
  (mobile robot development platform)
  -------------------------------------------------------------------
  TCRT5000 Line Following Sensors Example.
  -------------------------------------------------------------------
  Hardware setup :
  The line tracing sensors and the LEDs are allready
  mapped and connected to the Arduino board.
  PINs are as follows :

  LINE TRACING SENSOR 1: connected to Arduino analog PIN -> 8(A8)
  LINE TRACING SENSOR 2: connected to Arduino analog PIN -> 9(A9)
  LINE TRACING SENSOR 3: connected to Arduino analog PIN -> 10(A10)
  LINE TRACING SENSOR 4: connected to Arduino analog PIN -> 11(A11)
  LINE TRACING SENSOR 5: connected to Arduino analog PIN -> 12(A12)
  LINE TRACING SENSOR 6: connected to Arduino analog PIN -> 13(A13)
  LINE TRACING SENSOR 7: connected to Arduino analog PIN -> 14(A14)
  LINE TRACING SENSOR 8: connected to Arduino analog PIN -> 15(A15)
  -------------------------------------------------------------------
  PINs of the LEDs(these LEDs are already connected and mapped)
  that are used to indicate the line tracing sensors are follows :

  LED 1 PIN connected to Arduino digital PIN -> 22(D22)
  LED 1 PIN connected to Arduino digital PIN -> 23(D23)
  LED 1 PIN connected to Arduino digital PIN -> 24(D24)
  LED 1 PIN connected to Arduino digital PIN -> 25(D25)
  LED 1 PIN connected to Arduino digital PIN -> 32(D32)
  LED 1 PIN connected to Arduino digital PIN -> 33(D33)
  LED 1 PIN connected to Arduino digital PIN -> 34(D34)
  LED 1 PIN connected to Arduino digital PIN -> 35(D35)
  -------------------------------------------------------------------
  23 march 2021
*/

int IR1 = A8; // the number of the Arduino PIN, that line tracing sensor 1 is connected to.
int IR2 = A9; // the number of the Arduino PIN, that line tracing sensor 2 is connected to.
int IR3 = A10;// the number of the Arduino PIN, that line tracing sensor 3 is connected to.
int IR4 = A11;// the number of the Arduino PIN, that line tracing sensor 4 is connected to.
int IR5 = A12;// the number of the Arduino PIN, that line tracing sensor 5 is connected to.
int IR6 = A13;// the number of the Arduino PIN, that line tracing sensor 6 is connected to.
int IR7 = A14;// the number of the Arduino PIN, that line tracing sensor 7 is connected to.
int IR8 = A15;// the number of the Arduino PIN, that line tracing sensor 8 is connected to.

int LED1 = 22;// the number of the Arduino PIN, that LED 1 is connected to.
int LED2 = 23;// the number of the Arduino PIN, that LED 2 is connected to.
int LED3 = 24;// the number of the Arduino PIN, that LED 3 is connected to.
int LED4 = 25;// the number of the Arduino PIN, that LED 4 is connected to.
int LED5 = 32;// the number of the Arduino PIN, that LED 5 is connected to.
int LED6 = 33;// the number of the Arduino PIN, that LED 6 is connected to.
int LED7 = 34;// the number of the Arduino PIN, that LED 7 is connected to.
int LED8 = 35;// the number of the Arduino PIN, that LED 8 is connected to.

int s1, s2, s3, s4, s5 , s6, s7, s8; // creating few variables to hold the each line tracing sensor value.

void setup() {

  //making all PINs connected as line tracing sensors to be input's.
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);
  pinMode(IR6, INPUT);
  pinMode(IR7, INPUT);
  pinMode(IR8, INPUT);

  //making all LED PINs as outputs.
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);

}

void loop() {
  //reading each line tracing sensors to variables.
  s1 = digitalRead(IR1);
  s2 = digitalRead(IR2);
  s3 = digitalRead(IR3);
  s4 = digitalRead(IR4);
  s5 = digitalRead(IR5);
  s6 = digitalRead(IR6);
  s7 = digitalRead(IR7);
  s8 = digitalRead(IR8);

  //check the variable values and turning on off corrosponding LED's.
  
  if (s1) {
    digitalWrite(LED1, LOW);
  } else {
    digitalWrite(LED1, HIGH);
  }

  if (s2) {
    digitalWrite(LED2, LOW);
  } else {
    digitalWrite(LED2, HIGH);
  }

  if (s3) {
    digitalWrite(LED3, LOW);
  } else {
    digitalWrite(LED3, HIGH);
  }

  if (s4) {
    digitalWrite(LED4, LOW);
  } else {
    digitalWrite(LED4, HIGH);
  }

  if (s5) {
    digitalWrite(LED5, LOW);
  } else {
    digitalWrite(LED5, HIGH);
  }

  if (s6) {
    digitalWrite(LED6, LOW);
  } else {
    digitalWrite(LED6, HIGH);
  }

  if (s7) {
    digitalWrite(LED7, LOW);
  } else {
    digitalWrite(LED7, HIGH);
  }

  if (s8) {
    digitalWrite(LED8, LOW);
  } else {
    digitalWrite(LED8, HIGH);
  }
}
