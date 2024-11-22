/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ------------------------------------------------------------------------------------
  Development Platform : Quadrant 1.0
  (embedded development platform)
  ------------------------------------------------------------------------------------
  Attiny13 Example.
  ------------------------------------------------------------------------------------
  Hardware setup :
  connect PB0 to Arduino digital PIN 11(D11)
  connect PB1 to Arduino digital PIN 12(D12)
  connect PB2 to Arduino digital PIN 13(D13)
  connect PB5 to Arduino digital PIN 10(D10)
  connect LED1 to Arduino digital PIN  9(D9)
  connect PB4 to LED2
  ------------------------------------------------------------------------------------
  install : https://mcudude.github.io/MicroCore/package_MCUdude_MicroCore_index.json
  to Arduino IDE.
  ------------------------------------------------------------------------------------
  then go to File -> ArduinoISP -> upload the sketch to Arduino board.
  if ArduinoISP is working you'll see LED1 fade in and fade off.
  ------------------------------------------------------------------------------------
  now select tools -> board -> microcore -> Attiny13.
  then go to tools -> and select Arduino as ISP.
  now tools -> burn bootloader.
  ------------------------------------------------------------------------------------
  now go to file -> examples -> basic -> blink.
  change "LED_BUILTIN" to "4"
  then go to sketch -> upload using programmer.
  if everything is gone accordingly you'll see LED2 blinking.
  ------------------------------------------------------------------------------------
  24 march 2021
*/

void setup() {
  pinMode(4, OUTPUT);
}


void loop() {
  digitalWrite(4, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
