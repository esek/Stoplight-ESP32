#include <Arduino.h>
#include <WiFi.h>

#define WIFISSID "noot noot"
#define WIFIPASSWORD "12345678"

bool isConnected = false;

void setup() {
    Serial.begin(9600);
    WiFi.begin(WIFISSID, WIFIPASSWORD);
    Serial.println("Start");

}



void loop() {
    if(WiFi.status() == WL_CONNECTED && !isConnected){
        Serial.println("Connected");
        isConnected = true;
    }
    if(WiFi.status() != WL_CONNECTED){
        Serial.println(".");
        isConnected = false;
        delay(500);
    }

}