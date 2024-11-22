/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
 ------------------------------------------------------------
  Development Platform : Quadrant 1.0
  (embedded development platform)
 ------------------------------------------------------------
  MAX7219 4Digit Seven Segment Display Example.
 ------------------------------------------------------------
  Hardware setup :
  Hardware setup :
  Connect "7 Segment[cc]" PINs near dotmatrix to the PINs
  of "7 Segment[cc]" beleow the 4digit seven segment display.

  connect MAX7219  DIN PIN to Arduino digital PIN 2(D2).
  connect MAX7219  CS   PIN to Arduino digital PIN 3(D3).
  connect MAX7219  CLK  PIN to Arduino digital PIN 4(D4).
 ------------------------------------------------------------
  24 march 2021
*/

#include <LedControl.h> // library for LED control with MAX7219.

int DIN = 2;
int CLK = 3;
int CS = 4;

LedControl lc = LedControl(DIN, CLK, CS, 1); //DIN | CLK | CS | number of matrices.

void setup() {

  lc.shutdown(0, false); // the MAX7219 is in power-saving mode on startup, we have to do a wakeup call.
  lc.setIntensity(0, 15); // set the brightness of display between 0 and 15.
  lc.clearDisplay(0); // clear the display.

  lc.setDigit(0, 3, 0, false);
  lc.setDigit(0, 2, 0, false);
  lc.setDigit(0, 1, 0, true);
  lc.setDigit(0, 0, 0, false);

}

void loop() {
  lc.setDigit(0, 3, 1, true);
  lc.setDigit(0, 2, 1, false);
  lc.setDigit(0, 1, 3, true);
  lc.setDigit(0, 0, 3, false);
}
