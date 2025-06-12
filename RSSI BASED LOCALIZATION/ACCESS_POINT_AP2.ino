#include <WiFi.h>

void setup() {
  WiFi.softAP("AP2");  // Unique SSID
  Serial.begin(115200);
  Serial.println("AP2 started");
}

void loop() {}
