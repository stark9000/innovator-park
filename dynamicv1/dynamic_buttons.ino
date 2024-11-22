/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------
  Development Platform : Dynamic 1.0
  (mobile robot development platform)
  --------------------------------------------------------
  Buttons Example.
  --------------------------------------------------------
   Hardware setup :
   Buttons and button press indicator LEDs are all ready
   mapped and connected to the Arduino board.
   PINs are as follows :
  --------------------------------------------------------
   Buttons:
   BACKWARD button : PIN -> Arduino analog PIN 4(A4)
   RIGHT    button : PIN -> Arduino analog PIN 3(A3)
   FORWARD  button : PIN -> Arduino analog PIN 1(A1)
   LEFT     button : PIN -> Arduino analog PIN 0(A0)
   STOP     button : PIN -> Arduino analog PIN 2(A2)
  --------------------------------------------------------
   LEDs:
   BACKWARD LED : PIN -> Arduino digital PIN 39(D39)
   RIGHT    LED : PIN -> Arduino digital PIN 40(D40)
   FORWARD  LED : PIN -> Arduino digital PIN 36(D36)
   LEFT     LED : PIN -> Arduino digital PIN 37(D37)
   STOP     LED : PIN -> Arduino digital PIN 38(D38)
  --------------------------------------------------------
  23 march 2021
*/

//------------------------------BUTTON PINs----------------------------------------------------
int BUTTON_LEFT = A0;// the number of the Arduino PIN, that left button is connected to.

int BUTTON_RIGHT = A3;// the number of the Arduino PIN, that right button is connected to.

int BUTTON_FORWARD = A1;// the number of the Arduino PIN, that forward button is connected to.

int BUTTON_BACK = A4;// the number of the Arduino PIN, that backward button is connected to.

int BUTTON_STOP = A2;// the number of the Arduino PIN, that stop button is connected to.

//------------------------------LED PINs-------------------------------------------------------
int LED_LEFT = 37;// the number of the Arduino PIN, that left LED is connected to.

int LED_RIGHT = 40;// the number of the Arduino PIN, that right LED is connected to.

int LED_FORWARD = 36;// the number of the Arduino PIN, that forward LED is connected to.

int LED_BACK = 39;// the number of the Arduino PIN, that backward LED is connected to.

int LED_STOP = 38;// the number of the Arduino PIN, that stop LED is connected to.



void setup() {

  //initializing all button PINs as inputs.
  pinMode(BUTTON_LEFT, INPUT);
  pinMode(BUTTON_RIGHT, INPUT);
  pinMode(BUTTON_FORWARD, INPUT);
  pinMode(BUTTON_BACK, INPUT);
  pinMode(BUTTON_STOP, INPUT);

  //initializing all LED PINs as outputs.
  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_FORWARD, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);
  pinMode(LED_STOP, OUTPUT);
  pinMode(LED_BACK, OUTPUT);
}

void loop() {

  //digital read each button and check if the value is equal to zero.

  if (digitalRead(BUTTON_LEFT) == 0) {//if the button is pressed, the value will be zero
    digitalWrite(LED_LEFT, HIGH);//if value is zero turn the Corresponding LED on.
  } else {
    digitalWrite(LED_LEFT, LOW);//else turn off the LED.
  }

  if (digitalRead(BUTTON_RIGHT) == 0) {//if the button is pressed, the value will be zero
    digitalWrite(LED_RIGHT, HIGH);//if value is zero turn the Corresponding LED on.
  } else {
    digitalWrite(LED_RIGHT, LOW);//else turn off the LED.
  }

  if (digitalRead(BUTTON_FORWARD) == 0) {//if the button is pressed, the value will be zero
    digitalWrite(LED_FORWARD, HIGH);//if value is zero turn the Corresponding LED on.
  } else {
    digitalWrite(LED_FORWARD, LOW);//else turn off the LED.
  }

  if (digitalRead(BUTTON_BACK) == 0) {//if the button is pressed, the value will be zero
    digitalWrite(LED_BACK, HIGH);//if value is zero turn the Corresponding LED on.
  } else {
    digitalWrite(LED_BACK, LOW);//else turn off the LED.
  }

  if (digitalRead(BUTTON_STOP) == 0) {//if the button is pressed, the value will be zero
    digitalWrite(LED_STOP, HIGH);//if value is zero turn the Corresponding LED on.
  } else {
    digitalWrite(LED_STOP, LOW);//else turn off the LED.
  }

}
