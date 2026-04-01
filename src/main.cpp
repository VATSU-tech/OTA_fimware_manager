#include <Arduino.h>
#include <ESP8266WiFi.h>

const char* ssid = "UNILUK-NET";
const char* password = "";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connexion...");
  }

  Serial.println("Connecté");
}

void loop() {
}