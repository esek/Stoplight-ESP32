#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>

#define WIFISSID "Esek-HK"
#define WIFIPASSWORD "jag lovar att bete mig"

const char *serverName = "https://skitaskita.esek.se/shit/stop";

WiFiClientSecure client;

void setup()
{
  Serial.begin(9600);

  Serial.println("Start ");
  Serial.println("attempting to connect:");
  WiFi.begin(WIFISSID, WIFIPASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Connected");

  client.setInsecure();
  Serial.println("\nStarting connection to server...");
  if (!client.connect("skitaskita.esek.se", 443))
    Serial.println("Connection failed!");
  else
  {
    Serial.println("Connected to server!");
    // Make a HTTP request:
    client.println("POST /shit/start HTTP/1.1");
    client.println("content-type: application/json");
    client.println("content-length: 12");
    client.println("host: skitaskita.esek.se");
    client.println();
    // client.println();
    client.println("{\"id\": \"32\"}");

    while (client.connected())
    {
      String line = client.readStringUntil('\n');
      if (line == "\r")
      {
        Serial.println("headers received");
        break;
      }
    }
    
    client.stop();
  }
}

void loop()
{
  
  delay(10000);
}