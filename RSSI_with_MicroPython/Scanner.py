import network
import time
import math

# Coordinates of hotspots
AP1 = {'ssid': 'AP1', 'x': 0, 'y': 0}
AP2 = {'ssid': 'AP2', 'x': 4, 'y': 0}  # adjust if distance is different

# Constants (you can calibrate later)
TX_POWER = -50  # RSSI at 1 meter
PATH_LOSS_EXPONENT = 2.0

def rssi_to_distance(rssi):
    return 10 ** ((TX_POWER - rssi) / (10 * PATH_LOSS_EXPONENT))

def trilaterate(ap1, ap2, d1, d2):
    x1, y1 = ap1['x'], ap1['y']
    x2, y2 = ap2['x'], ap2['y']
    a = (d1**2 - d2**2 + (x2 - x1)**2) / (2 * (x2 - x1))
    x = a
    y_squared = d1**2 - a**2
    y = math.sqrt(y_squared) if y_squared > 0 else 0
    return x, y

sta = network.WLAN(network.STA_IF)
sta.active(True)

def scan_and_estimate():
    results = sta.scan()
    rssi_data = {}

    for net in results:
        ssid = net[0].decode()
        rssi = net[3]
        if ssid == AP1['ssid']:
            rssi_data['AP1'] = rssi
        elif ssid == AP2['ssid']:
            rssi_data['AP2'] = rssi

    if 'AP1' in rssi_data and 'AP2' in rssi_data:
        d1 = rssi_to_distance(rssi_data['AP1'])
        d2 = rssi_to_distance(rssi_data['AP2'])
        x, y = trilaterate(AP1, AP2, d1, d2)

        print(f"\nRSSI - AP1: {rssi_data['AP1']} dBm | Distance: {d1:.2f} m")
        print(f"RSSI - AP2: {rssi_data['AP2']} dBm | Distance: {d2:.2f} m")
        print(f"Estimated Position: x = {x:.2f} m, y = {y:.2f} m")
    else:
        print("One or both APs not found")

while True:
    scan_and_estimate()
    time.sleep(2)
