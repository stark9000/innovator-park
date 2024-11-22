/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ------------------------------------------------------------------
  Development Platform : Inspire 1.0
  (Arduino development platform)
  ------------------------------------------------------------------
  Push Button Example.
  ------------------------------------------------------------------
  Hardware setup :
  plug a Arduino nano board in to the inspre top development board.
  turn on power switch of the top development board.

  connect BTN1 PIN to Arduino Digital PIN-> 2(D2)
  ------------------------------------------------------------------
  22 march 2021
*/

int BUTTON1 = 2;//the number of the push button PIN.
int BUTTON1_STATE = 1;//a variable to hold the button state.

void setup() {
  Serial.begin(9600);//starting serial communication between arduino and computer.

  pinMode(BUTTON1, INPUT);//initializing BUTTON PIN as a input PIN.
}

void loop() {
  BUTTON1_STATE = digitalRead(BUTTON1);//read the state of the push button value.
  
  if ( BUTTON1_STATE == false) {//check if the value of the variable is equal to 0.
    
    Serial.println("Button one Pressed !");//if value of the variable 0,then print a message to serial monitor.
    
    delay(100);//wait some time.
  }
}
