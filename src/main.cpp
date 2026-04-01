#include <Arduino.h>

#define led LED_BUILTIN

void setup() {  
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
}

void loop() {
}