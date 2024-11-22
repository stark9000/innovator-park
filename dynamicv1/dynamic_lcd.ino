/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ----------------------------------------------------------------------------
  Development Platform : Dynamic 1.0
  (mobile robot development platform)
  ----------------------------------------------------------------------------
  HD44780 16*2 LCD Example.
  ----------------------------------------------------------------------------
  Hardware setup :
  16*2 LCD is allready connected to the Arduino board.
  LCD's I2C adress is 0x27.
  ----------------------------------------------------------------------------
  23 march 2021
*/


#include  <LiquidCrystal_I2C.h>//including the LCD driver library. 

LiquidCrystal_I2C lcd(0x27, 16, 2);//initializing the LCD I2C address(0x27) and LCD's number of columns(16) and rows(2).



void setup() {
  lcd.begin();//initializing connection to the LCD.

  lcd.backlight();//turning on the backlight of the LCD.

  lcd.setCursor(0, 0);//setting the cursor position to column 0 and row 0.

  lcd.print("Dynamic");//printing a message to LCD.

  delay(1000);//waiting for one second to be elapsed.

  lcd.clear();//clearing the charcters printedd on the LCD.
}

void loop() {
  lcd.setCursor(2, 0);//setting the cursor position to column 2 and row 0.

  lcd.print("Hello world !");//printing a message to LCD.
}
