#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>

const char* ssid = "WANTED";
const char* password = "espoir100";

String version_url = "https://raw.githubusercontent.com/VATSU-tech/OTA_fimware_manager/main/.pio/build/nodemcuv2/version.txt";
String firmware_url = "https://raw.githubusercontent.com/VATSU-tech/OTA_fimware_manager/main/.pio/build/nodemcuv2/firmware.bin";

String currentVersion = "1.0";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connexion...");
  }

  Serial.println("Connecté");

  checkUpdate();
}

void loop() {
  // rien ici
}

void checkUpdate() {
  WiFiClient client;
  HTTPClient http;

  http.begin(client, version_url);
  int httpCode = http.GET();

  if (httpCode == 200) {
    String newVersion = http.getString();
    newVersion.trim();

    Serial.println("Version distante: " + newVersion);

    if (newVersion != currentVersion) {
      Serial.println("Mise à jour disponible !");
      updateFirmware();
    } else {
      Serial.println("Déjà à jour");
    }
  }

  http.end();
}

void updateFirmware() {
  WiFiClient client;

  t_httpUpdate_return ret = ESPhttpUpdate.update(client, firmware_url);

  switch (ret) {
    case HTTP_UPDATE_FAILED:
      Serial.println("Echec");
      break;

    case HTTP_UPDATE_NO_UPDATES:
      Serial.println("Pas de maj");
      break;

    case HTTP_UPDATE_OK:
      Serial.println("Succès → reboot");
      break;
  }
}