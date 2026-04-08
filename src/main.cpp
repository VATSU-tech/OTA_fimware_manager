#include <Arduino.h>

#define led D4
#define interval 50

bool state = false;
unsigned int compteur = 200;

unsigned long presentTime = 0;
unsigned long previousTime = 0;

void setup(){
    Serial.begin(9600);
    pinMode(led, OUTPUT); 
}

void loop(){
    presentTime = millis();

    if ((presentTime - previousTime) >= interval) {
        state = compteur >= 255 || compteur <= 200 ? !state : state;
        compteur = state ? compteur + 1 : compteur - 1;
        analogWrite(led, compteur);
        Serial.println(compteur);
        previousTime = presentTime;
    }
}