// #include <Arduino.h>
// #include <ESP8266WiFi.h>
// #include <ESP8266HTTPClient.h>
// #include <ESP8266httpUpdate.h>
// #include <WiFiClientSecureBearSSL.h>

// const char* ssid = "The Real Bienv";
// const char* password = "8d9610E<>"; // TODO: mets le vrai mot de passe WiFi

// // NOTE:
// // Les fichiers générés dans .pio/build ne sont pas dans le repo GitHub.
// // Mets ton firmware et version dans un dossier commité, par ex:
// // firmware/version.txt et firmware/firmware.bin
// const char* version_url =
//     "https://raw.githubusercontent.com/VATSU-tech/OTA_fimware_manager/main/firmware/version.txt";
// const char* firmware_url =
//     "https://raw.githubusercontent.com/VATSU-tech/OTA_fimware_manager/main/firmware/firmware.bin";

// const char* currentVersion = "1.0.0";

// void checkUpdate();
// void updateFirmware();

// void setup() {
//   Serial.begin(9600);
//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.println("Connexion...");
//   }

//   Serial.println("Connecté");

//   checkUpdate();
// }

// void loop() {
//   // rien ici
// }

// void checkUpdate() {
//   std::unique_ptr<BearSSL::WiFiClientSecure> client(
//       new BearSSL::WiFiClientSecure);
//   client->setInsecure(); // TODO: remplace par un certificat si tu veux du TLS sûr

//   HTTPClient http;
//   if (!http.begin(*client, version_url)) {
//     Serial.println("Erreur HTTP begin pour version_url");
//     return;
//   }

//   int httpCode = http.GET();
//   if (httpCode == 200) {
//     String newVersion = http.getString();
//     newVersion.trim();

//     Serial.println("Version distante: " + newVersion);

//     if (newVersion != currentVersion) {
//       Serial.println("Mise à jour disponible !");
//       updateFirmware();
//     } else {
//       Serial.println("Déjà à jour");
//     }
//   } else {
//     Serial.printf("Erreur HTTP version: %d\n", httpCode);
//   }

//   http.end();
// }

// void updateFirmware() {
//   std::unique_ptr<BearSSL::WiFiClientSecure> client(
//       new BearSSL::WiFiClientSecure);
//   client->setInsecure(); // TODO: remplace par un certificat si tu veux du TLS sûr

//   // Optionnel: LED intégrée pendant l'update
//   ESPhttpUpdate.setLedPin(LED_BUILTIN, LOW);

//   t_httpUpdate_return ret =
//       ESPhttpUpdate.update(*client, firmware_url, currentVersion);

//   switch (ret) {
//     case HTTP_UPDATE_FAILED:
//       Serial.printf("Echec: %s\n", ESPhttpUpdate.getLastErrorString().c_str());
//       break;

//     case HTTP_UPDATE_NO_UPDATES:
//       Serial.println("Pas de maj");
//       break;

//     case HTTP_UPDATE_OK:
//       Serial.println("Succès → reboot");
//       break;
//   }
// }

#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Hello, world!");
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}