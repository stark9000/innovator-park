/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  -------------------------------------------------------------------
  Development Platform : Dynamic 1.0
  (mobile robot development platform)
  -------------------------------------------------------------------
  LEDs Example.
  -------------------------------------------------------------------
  Hardware setup :
  PINs of the LEDs(these LEDs are already connected and mapped)

  LED 1 PIN connected to Arduino digital PIN -> 22(D22)
  LED 2 PIN connected to Arduino digital PIN -> 23(D23)
  LED 3 PIN connected to Arduino digital PIN -> 24(D24)
  LED 4 PIN connected to Arduino digital PIN -> 25(D25)
  LED 5 PIN connected to Arduino digital PIN -> 32(D32)
  LED 6 PIN connected to Arduino digital PIN -> 33(D33)
  LED 7 PIN connected to Arduino digital PIN -> 34(D34)
  LED 8 PIN connected to Arduino digital PIN -> 35(D35)
  -------------------------------------------------------------------
  23 march 2021
*/

int LED1 = 22;// the number of the Arduino PIN, that LED 1 is connected to.
int LED2 = 23;// the number of the Arduino PIN, that LED 2 is connected to.
int LED3 = 24;// the number of the Arduino PIN, that LED 3 is connected to.
int LED4 = 25;// the number of the Arduino PIN, that LED 4 is connected to.
int LED5 = 32;// the number of the Arduino PIN, that LED 5 is connected to.
int LED6 = 33;// the number of the Arduino PIN, that LED 6 is connected to.
int LED7 = 34;// the number of the Arduino PIN, that LED 7 is connected to.
int LED8 = 35;// the number of the Arduino PIN, that LED 8 is connected to.


void setup() {
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
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  digitalWrite(LED6, HIGH);
  digitalWrite(LED7, HIGH);
  digitalWrite(LED8, HIGH);
  delay(1000);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, LOW);
  digitalWrite(LED8, LOW);
  delay(1000);
}
