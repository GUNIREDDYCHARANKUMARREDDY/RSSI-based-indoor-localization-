#include <WiFi.h>

void setup() {
  WiFi.softAP("AP1");  // Unique SSID
  Serial.begin(115200);
  Serial.println("AP1 started");
}

void loop() {}
