/*
  INNOVATOR INTERNATIONAL (PVT)LTD.
  https://www.innovator.lk/
  --------------------------------------------------------
  Development Platform : Quadrant 1.0
  (embedded development platform)
  --------------------------------------------------------
  ESP01 WI-FI Example.
  --------------------------------------------------------
  Hardware setup :
  connect WIFI ESP RX of wifi to Arduino (0 PIN)RX.
  connect WIFI ESP TX of wifi to Arduino (1 PIN)TX.
  connect WIFI RST PIN to BTN 1 PIN.
  connect WIFI GPIO 0 PIN to BTN 2 PIN.
  --------------------------------------------------------
  press and hold GPIO0 and RST buttons together and
  release the RST button first then GPIO0.
  this will put the esp8266 to programing mode.
  now press upload button in Arduino IDE.
  --------------------------------------------------------
  24 march 2021
*/

#include <ESP8266WiFi.h>
//controling a led through wifi.
// to program esp8266.

const char* ssid = "VIRUS";//type your ssid.
const char* password = "Zoneaziro1~";//type your password.

int ledPin = 2; // GPIO2 of ESP8266.
WiFiServer server(80);//creating a wifi servr object.

void setup() {
  Serial.begin(9600);//starting serial communication between arduino and computer.
  delay(10);//waiting to ten seconds to be elapsed.

  pinMode(ledPin, OUTPUT);//initializing ledpin as output pin.
  digitalWrite(ledPin, LOW);//turning off the led at startup.

  // connect to WiFi network.
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

  // starting the server.
  server.begin();
  Serial.println("Server started");

  // printing the IP address.
  Serial.print("Use this URL in a web browser to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop() {
  // check if a client has connected.
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // wait until the client sends some data.
  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }

  // read the first line of the request.
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // check html request.
  // set ledPin according to the request
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(ledPin, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1) {
    digitalWrite(ledPin, LOW);
    value = LOW;
  }

  // return the response
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
