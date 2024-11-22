/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------
  Development Platform : Dynamic 1.0
  (mobile robot development platform)
  --------------------------------------------------------
  Seven Segment Example.
  --------------------------------------------------------
  Hardware setup :
  Seven Segment Display Driver(7219) PINs are allready
  mapped and connected to the Arduino board.
  PINs are as follows :
  --------------------------------------------------------
  DIN connected to Arduino digital PIN -> 51
  CS  connected to Arduino digital PIN -> 52
  CLK connected to Arduino digital PIN -> 53
  --------------------------------------------------------
  23 march 2021
*/

int DIN  = 51;
int CLK  = 52;
int CS   = 53;

#include <LedControl.h>
LedControl lc = LedControl(DIN, CLK, CS, 1);

void setup() {
  lc.shutdown(0, false);//The MAX7219 is in power-saving mode on startup,so we do a wakeup call.

  lc.setIntensity(0, 15);//setting the display brightness to its maximum.(brightness : 0 t0 15).

  lc.clearDisplay(0);//clearing the display.

  //sending data to display.
  lc.setDigit(0, 3, 1, false);
  lc.setDigit(0, 2, 2, true);
  lc.setDigit(0, 1, 3, true);
  lc.setDigit(0, 0, 4, false);
}

void loop() {


}
