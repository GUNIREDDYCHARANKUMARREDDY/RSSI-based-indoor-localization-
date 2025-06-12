#include <WiFi.h>
#include <math.h>

// Coordinates of APs
float x1 = 0, y1_coord = 0;   // AP1
float x2 = 0, y2 = 4;         // AP2

int txPower = -45;  // Calibrate this value based on actual RSSI at 1 meter
float pathLossExp = 2.5;  // Environmental factor

float rssiToDistance(int rssi) {
  return pow(10, (txPower - rssi) / (10 * pathLossExp));
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  delay(1000);
}

void loop() {
  Serial.println("Scanning...");
  int n = WiFi.scanNetworks();

  int rssi1 = -100, rssi2 = -100;

  for (int i = 0; i < n; i++) {
    String ssid = WiFi.SSID(i);
    if (ssid == "AP1") {
      rssi1 = WiFi.RSSI(i);
    }
    if (ssid == "AP2") {
      rssi2 = WiFi.RSSI(i);
    }
  }

  if (rssi1 > -90 && rssi2 > -90) {
    float d1 = rssiToDistance(rssi1);
    float d2 = rssiToDistance(rssi2);

    // Use renamed y1_coord to avoid conflict
    float x = (pow(d1, 2) - pow(d2, 2) + pow(y2 - y1_coord, 2)) / (2 * (y2 - y1_coord));
    float y = 0;

    Serial.println("Position Estimated:");
    Serial.print("RSSI1: "); Serial.print(rssi1); Serial.print(" dBm  ");
    Serial.print("RSSI2: "); Serial.print(rssi2); Serial.println(" dBm");

    Serial.print("Estimated Distance to AP1: "); Serial.println(d1);
    Serial.print("Estimated Distance to AP2: "); Serial.println(d2);
    Serial.print("Position (x, y): "); Serial.print(x); Serial.print(", "); Serial.println(y);
  } else {
    Serial.println("APs not found!");
  }

  delay(200);
}
