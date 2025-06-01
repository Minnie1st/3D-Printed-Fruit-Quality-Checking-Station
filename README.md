# 3D-Printed-Fruit-Quality-Checking-Station

**Course:** LTAT.06.010 Pervasive Data Science Seminar  

---

## Overview

This project presents a fruit quality checking station built with 3D printing technology and IoT integration. It leverages sensor data collection, MQTT messaging, and a user-friendly Node-RED dashboard UI to evaluate fruit quality in real-time.

---

## Hardware and Software Components

- **3D Modeling:** Designed using Shapr3D, creating a custom enclosure and holder for the fruit sensor.
- **3D Printing:** Model sliced using Cura slicer and printed using Flsun super racer 3D printer.
- **Sensor Integration:** An Arduino-based sensor module reads light values .
- **Data Transmission:** Sensor data is sent via MQTT protocol to a broker.
- **Visualization and Interaction:** Node-RED is used to build a dashboard UI accessible on mobile devices, allowing users to select fruits and view quality assessment results instantly.

---

## Workflow

1. **3D Modeling and Printing**  
   The station’s casing and sensor mount were designed in Shapr3D and sliced with Cura for 3D printing.

2. **Sensor Data Collection**  
   Arduino reads sensor values detecting fruit characteristics such as color intensity or ripeness indicators.

3. **Data Publishing via MQTT**  
   The Arduino publishes sensor readings to a configured MQTT broker topic.

4. **Data Reception and UI with Node-RED**  
   Node-RED subscribes to the MQTT topic, processes incoming sensor data, and updates the UI dynamically. The UI enables fruit selection and displays quality status such as "Fresh," "Overripe," or "Spoiled" with intuitive visuals.

---

## Usage

- Place fruit above the station to be scanned.
- Sensor values are automatically transmitted to MQTT.
- Open the Node-RED dashboard on any device connected to the same network.
- Select the fruit type from the UI dropdown.
- View the fruit quality assessment live.

---

## Notes

- Ensure your MQTT broker is properly configured and accessible.
- Node-RED dashboard URL should be reachable from client devices.
- The UI is mobile-friendly and optimized for use on smartphones and tablets.

