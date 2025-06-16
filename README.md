# RSSI-based-indoor-localization-2D
RSSI-based positioning and scanning with ESP32

# ESP32 RSSI-based Indoor Positioning(C++(ARDUINO IDE)

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



# ESP32 RSSI-Based Indoor Positioning (MicroPython(Thonny)

This project estimates the position of an ESP32 using Wi-Fi RSSI values from two fixed Wi-Fi hotspots (mobile phones). It uses trilateration to estimate the 2D position based on signal strengths.

---

##  Hardware Required

- 1x ESP32 Dev Board (with MicroPython flashed)
- 2x Mobile Phones (as Wi-Fi hotspots)
- USB cable
- Thonny IDE (or any MicroPython editor)

---

##  Setup: Mobile Hotspots

- **Mobile 1:**
  - Enable hotspot
  - Set SSID to `AP1`
  - No password (if possible)

- **Mobile 2:**
  - Enable hotspot
  - Set SSID to `AP2`
  - No password

- **Place the phones** at fixed known positions:
  - AP1 at (0, 0)
  - AP2 at (0, 1)  → (1 meter1 apart)

---


