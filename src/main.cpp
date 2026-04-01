#include <Arduino.h>
#include <ESP8266WiFi.h>

const char* ssid = "WANTED";
const char* password = "espoir100";

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