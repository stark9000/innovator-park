 /*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------
  Development Platform : Quadrant 1.0
  (embedded development platform)
  --------------------------------------------------------
  DHT11 Sensor Example.
  --------------------------------------------------------
  Hardware setup :
  connect DHT's DATA PIN to Arduino analog PIN-> 0(A0)
  --------------------------------------------------------
  24 march 2021
*/

#include <DHT.h>;//including the DHT sensor library.

int DHTPIN = A0; // the number of the RELAY pin.

int DHTTYPE = DHT11;// selecting the DHT sensor model.

DHT dht(DHTPIN, DHTTYPE);//initializing DHT object.


float Humidity; // variable to hold the humidity value.
float Temperature;// variable to hold the temperature value.


void setup() {
  Serial.begin(9600);//starting serial communication between arduino and computer.

  dht.begin(); //initializing connection to the DHT sensor.
}

void loop() {
  //read data and store it to variables called "Humidity" and "Temperature".
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
