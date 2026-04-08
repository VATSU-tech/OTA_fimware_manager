// #include <Arduino.h>

// #define led D4
// #define interval 100

// bool state = false;
// unsigned int compteur = 0;

// unsigned long presentTime = 0;
// unsigned long previousTime = 0;

// void setup(){
//     Serial.begin(9600);
//     pinMode(led, OUTPUT);
// }

// void loop(){
//     presentTime = millis(); 

//     if (presentTime - previousTime > interval) {
//         compteur = state ? compteur + 1 : compteur - 1;
//         state = compteur >= 255 || compteur <= 0 ? !state : state;
//         previousTime = presentTime;
//         analogWrite(led, compteur);
//         Serial.println(compteur);
//     }
// }