/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  ---------------------------------------------------------------------------
  Development Platform : Dynamic 1.0
  (mobile robot development platform)
  ---------------------------------------------------------------------------
  ESP1 (esp8266) wifi example.
  controling a led through wifi
  ---------------------------------------------------------------------------
  Hardware setup :
  //connect RX of wifi to MCU RX0.
  //connect TX of wifi to MCU TX0.
  //connect MCU RST pin to one of the GND pins.

  //pres and hold GPIO0 and RST buttons together and release the RST button first then GPIO0.
  //this will put the esp8266 to programing mode.
  //now press upload button in arduin IDE.
  ---------------------------------------------------------------------------
  23 march 2021
*/

#include <ESP8266WiFi.h>
const char* ssid = "*****";//type your ssid
const char* password = "*******";//type your password

int ledPin = 2; // GPIO2 of ESP8266
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);


  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Match the request

  int value = LOW;
  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(ledPin, LOW);
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1) {
    digitalWrite(ledPin, HIGH);
    value = LOW;
  }

  // Set ledPin according to the request
  //digitalWrite(ledPin, value);


  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  client.print("Led pin is now: ");

  if (value == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("Click <a href=\"/LED=ON\">here</a> turn the LED on pin 2 ON<br>");
  client.println("Click <a href=\"/LED=OFF\">here</a> turn the LED on pin 2 OFF<br>");
  client.println("</html>");

  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");

}
