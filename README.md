# RSSI-based-indoor-localization-
RSSI-based positioning and scanning with ESP32

# Arduino RSSI-based Indoor Positioning

This project uses an ESP32 in station mode to scan WiFi RSSI values from two SoftAPs (ESP32-based) and estimate device position using trilateration.

## Hardware Used
- 3x ESP32
- Arduino IDE

## How It Works
- Two ESP32s act as WiFi Access Points (AP1 and AP2)
- One ESP32 acts as a scanner and reads RSSI values
- Position is estimated using distance calculation and circle intersection

## Output Example
RSSI1: -45 dBm
RSSI2: -37 dBm
Position: x = 2.1, y = 0.0
