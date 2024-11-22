/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ------------------------------------------------------------------
  Development Platform : Inspire 1.0
  (Arduino development platform)
  ------------------------------------------------------------------
  DHT11 Example.
  ------------------------------------------------------------------
  Hardware setup :
  plug a Arduino nano board in to the inspre top development board.
  turn on power switch of the top development board.
  
  Connect DHT PIN to Arduino analog PIN-> 0(A0)
  ------------------------------------------------------------------
  22 march 2021
*/

#include <DHT.h>;//including the DHT sensor library.

int DHTPIN = A0;//the number of the DHT11 DATA pin.

int DHTTYPE = DHT11;//selecting the DHT sensor model.

DHT dht(DHTPIN, DHTTYPE);//initiating a DHT object.


float Humidity;//a variable to hold the humidity value.

float Temperature;//a variable to hold the temperature value.


void setup() {
  Serial.begin(9600);//starting serial communication between arduino and computer.

  dht.begin();//initiating connection to the DHT sensor.
}

void loop() {
  //read data and store it in variables called "Humidity" and "Temperature".
  Humidity = dht.readHumidity();
  Temperature = dht.readTemperature();

  //printing values to the serial monitor.
  Serial.print("Humidity: ");
  Serial.print(Humidity);
  Serial.print(" %, Temp: ");
  Serial.print(Temperature);
  Serial.println(" Celsius");

  delay(2000);//keep a two second delay between each serial print.
}
