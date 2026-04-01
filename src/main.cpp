#include <Arduino.h>

#define led D2

void setup() {  
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  Serial.println("Salut NodeMCU VA");
  delay(1000);

}