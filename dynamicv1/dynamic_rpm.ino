/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  -----------------------------------------------------------
  Development Platform : Dynamic 1.0
  (mobile robot development platform)
  -----------------------------------------------------------
  RPM Example.
  -----------------------------------------------------------
  Hardware setup :
  Optical Encoder PINs are allready mapped and connected to
  the Arduino board.PINs are as follows :
  LEFT  ENCODER  connected to Arduino digital PIN -> 2(D2)
  RIGHT ENCODER  connected to Arduino digital PIN -> 3(D3)
  -----------------------------------------------------------
  24 march 2021
*/

int LEFT_ENCODER_COUNTER = 0,  RIGHT_ENCODER_COUNTER = 0; //variable to hold the encoder counts.

unsigned long TIME_NOW = 0, TIME_ELAPSED = 0;//variables to hold the delay timer values.

float LEFT_WHEEL, RIGHT_WHEEL; //variables to hold the rpm values.

void setup() {
  Serial.begin(9600);//starting serial communication between arduino and computer.
  attachInterrupt(0, Right_Encoder_Count, FALLING);//enabaling Arduino digital PIN 2(D2)falling edge interrupt.
  attachInterrupt(1, Left_Encoder_Count, FALLING);//enabaling Arduino digital PIN 3(D3)falling edge interrupt.
}

void loop() {
  TIME_NOW = millis();//storing the currunt millis count in the variable.
  if (abs(TIME_NOW - TIME_ELAPSED) >= 1000) {//check if delay time has elapsed.
    detachInterrupt(0);//disabaling Arduino digital PIN 1(D1) falling edge interrupt.
    detachInterrupt(1);//disabaling Arduino digital PIN 1(D1) falling edge interrupt.

    //doing the RPM calculation and storing the values in variables.
    LEFT_WHEEL = (float)LEFT_ENCODER_COUNTER * 60 / 20;
    RIGHT_WHEEL = (float)RIGHT_ENCODER_COUNTER * 60 / 20;

    //printing values to serial monitor.
    Serial.print("left:");
    Serial.print(LEFT_WHEEL);
    Serial.print("     right:");
    Serial.println(RIGHT_WHEEL);

    //resetting variable values.
    LEFT_ENCODER_COUNTER = 0;
    RIGHT_ENCODER_COUNTER = 0;
    TIME_ELAPSED =  millis();

    //enabaling inturrupts again.
    attachInterrupt(0, Right_Encoder_Count, FALLING);
    attachInterrupt(1, Left_Encoder_Count, FALLING);
    return 1;//if delay time has elapsed then value is 1.
  } else {
    return 0;//if delay time has not elapsed then value is 0.
  }
}


//incrimenting the encoder counters.
//these functions are called by inturrupt routein.
void Right_Encoder_Count()
{
  RIGHT_ENCODER_COUNTER++;
}

void Left_Encoder_Count()
{
  LEFT_ENCODER_COUNTER++;
}
