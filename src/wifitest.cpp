#include <Arduino.h>
#include <WiFi.h>

//#define WIFISSID "Esek-HK"
//#define WIFIPASSWORD "jag lovar att bete mig"
#define WIFISSID "noot noot"
#define WIFIPASSWORD "12345678"
u_int8_t BSSID[8] = {0x08, 0x8e, 0x90, 0xd9, 0xe1, 0xe9, 0};
int numnetworks;

void setup() {
    Serial.begin(9600);
    
    
    numnetworks = WiFi.scanNetworks();
    delay(3000);
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
    





    Serial.println("Start ");
    Serial.println("attempting to connect:");
    WiFi.begin(WIFISSID, WIFIPASSWORD
        //,6,BSSID,true
        );
    while(WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(1000);
    }
    Serial.println("Connected");

}



void loop() {
    
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
    
    delay(10000);
    

}