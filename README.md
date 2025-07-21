# Smart IoT Exhaust Fan System (In Progress)

An ESP32-based IoT fan system built using FreeRTOS for real-time gas detection, exhaust control, and wireless communication. Designed to prioritize safety by reacting to hazardous conditions with minimal delay.

---

## Purpose

This project explores how real-time embedded systems can be used for environmental hazard detection (e.g., smoke/gas) and mitigation through automatic exhaust control. It demonstrates task prioritization, sensor interrupt handling, and secure ESP-NOW communication.

---

## Tools & Technologies

- Microcontroller: ESP32 (2 nodes)
- Framework: ESP-IDF with FreeRTOS
- Communication: ESP-NOW (custom wireless protocol)
- Web Server: Lightweight HTTP server for manual override/status
- Sensors: MQ2 Gas Sensor
- Language: C

---

## Architecture

1. **Sensor Node (above stove):**
   - Reads gas levels from MQ2 sensor
   - Triggers interrupt on hazardous readings
   - Sends wireless signal to Fan Node via ESP-NOW

2. **Fan Node (near exhaust fan):**
   - Receives signal and activates exhaust system
   - Monitors temperature (optional)
   - Hosts a simple web interface to show status and allow manual control

---

## Security Considerations

- ESP-NOW communication restricted to known MAC addresses
- Future improvements: payload encryption, message signing, and OTA update authentication
- Segmenting ESP32s

---

## Features

- [x] Real-time gas detection
- [x] Interrupt-based task switching
- [x] RTOS thread prioritization (FreeRTOS)
- [x] Wireless control via ESP-NOW
- [x] Web-based monitoring interface
- [ ] OTA firmware update integration (planned)
- [ ] Sensor spoofing detection (planned)

---

## Lessons Learned

- How to structure and prioritize safety-critical tasks in a real-time environment
- Mutex use in concurrent sensor and network communication
- Design tradeoffs in ESP-NOW packet reliability vs. overhead
- Considerations for embedded IoT device security in untrusted environments

---

## References

- [ESP-IDF Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
- [MQ2 Datasheet](https://components101.com/sensors/mq2-gas-sensor)

---

Here is a rough first build (looks bad I know)

![First Build](https://github.com/kylnan/Smoke-Detector-Fan/blob/main/IMG_0898.jpg)
