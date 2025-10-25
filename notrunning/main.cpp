#include <Arduino.h>

#define HALL1 4
#define HALL2 0

#define REDLIGHT 12
#define YELLOWLIGHT 14
#define GREENLIGHT 27

// put function declarations here:

int hall1_reading;
int hall2_reading;


void setup() {
  // put your setup code here, to run once:
  pinMode(HALL1, ANALOG);
  pinMode(HALL2, ANALOG);

  pinMode(REDLIGHT, OUTPUT);
  pinMode(YELLOWLIGHT, OUTPUT);
  pinMode(GREENLIGHT, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  hall1_reading = analogRead(HALL1);
  hall2_reading = analogRead(HALL2);
  if((hall1_reading  > 200) && (hall2_reading > 200)){
    digitalWrite(GREENLIGHT, HIGH);
    digitalWrite(YELLOWLIGHT, LOW);
    digitalWrite(REDLIGHT, LOW);
  }
  else if((hall1_reading  < 200) && (hall2_reading < 200)){
    digitalWrite(GREENLIGHT, LOW);
    digitalWrite(YELLOWLIGHT, LOW);
    digitalWrite(REDLIGHT, HIGH);
  }
  else{
    digitalWrite(GREENLIGHT, LOW);
    digitalWrite(YELLOWLIGHT, HIGH);
    digitalWrite(REDLIGHT, LOW);
  }
  delay(100);
  Serial.printf("Hall1 %i \n", hall1_reading);
  Serial.printf("Hall2 %i \n", hall2_reading);
  
}

// put function definitions here:
