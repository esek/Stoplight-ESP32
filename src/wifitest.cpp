#include <Arduino.h>
#include <WiFi.h>

#define WIFISSID "Esek-HK"
#define WIFIPASSWORD "jag lovar att bete mig"

int numnetworks;

void setup() {
    Serial.begin(9600);
    WiFi.begin(WIFISSID, WIFIPASSWORD);
    Serial.println("Start");
    

}



void loop() {
    /*
    numnetworks = WiFi.scanNetworks();
    printf("Found %i Networks \n", numnetworks);
    
    for (int i = 0; i < numnetworks; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
      delay(10);
    }
    Serial.println("done! new scan soon\n\n");
    delay(10000);*/

    
    
    if(WiFi.status() == WL_CONNECTED){
        Serial.println("Connected");
        isConnected = true;
    }
    else if(WiFi.status() != WL_CONNECTED){
        Serial.println("not connected");
        isConnected = false;
    }
    else if(WiFi.status() != WL_CONNECTED){
        Serial.println("not connected");
        isConnected = false;
    }
    

}