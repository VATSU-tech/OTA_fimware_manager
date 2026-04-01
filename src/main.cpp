#include <Arduino.h>
#include <ESP8266WiFi.h>

const char* ssid = "UNILUK-NET";
const char* password = "";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
}

void loop() {
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connexion...");
  }

  Serial.println("Connecté");
}