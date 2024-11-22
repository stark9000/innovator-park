/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------
  Development Platform : Quadrant 1.0
  (embedded development platform)
  --------------------------------------------------------
  Buttons Example.
  --------------------------------------------------------
  Hardware setup :
  Connect BTN1 PIN to Arduino Digital PIN-> 2(D2)
  Connect BTN2 PIN to Arduino Digital PIN-> 3(D3)
  Connect BTN3 PIN to Arduino Digital PIN-> 4(D4)
  Connect BTN4 PIN to Arduino Digital PIN-> 5(D5)
  Connect BTN5 PIN to Arduino Digital PIN-> 6(D6)
  --------------------------------------------------------
  24 march 2021
*/

int button1 = 2;//PIN number of the push button 1.
int button2 = 3;//PIN number of the push button 2.
int button3 = 4;//PIN number of the push button 3.
int button4 = 5;//PIN number of the push button 4.
int button5 = 6;//PIN number of the push button 5.

//few variables to hold the button state.
boolean b1 = true;
boolean b2 = true;
boolean b3 = true;
boolean b4 = true;
boolean b5 = true;

void setup() {
  
  //initializing ALL button PINs as inputs.
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  
  Serial.begin(9600);//starting serial communication between arduino and computer.
}

void loop() {
  
  //reading all buttons and store states in variables.
  boolean b1 = digitalRead(button1);
  boolean b2 = digitalRead(button2);
  boolean b3 = digitalRead(button3);
  boolean b4 = digitalRead(button4);
  boolean b5 = digitalRead(button5);

//check variable value if it is "FALSE" and print message to serial monitor.
  if (!b1) {
    Serial.println("button 1 pressed !");
  }
  if (!b2) {
    Serial.println("button 2 pressed !");
  }
  if (!b3) {
    Serial.println("button 3 pressed !");
  }
  if (!b4) {
    Serial.println("button 4 pressed !");
  }
  if (!b5) {
    Serial.println("button 5 pressed !");
  }
}
