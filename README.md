<h1 align="center">🔥 Smoke & Fire Detection System</h1>

<p align="center">
  A safety-focused embedded system designed to detect smoke and flame using sensors integrated with Arduino. The system automatically triggers visual and audio alerts, controls exhaust fans, and activates water sprinklers for fire response.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Arduino-Uno-00979D?style=flat-square&logo=arduino&logoColor=white"/>
  <img src="https://img.shields.io/badge/MQ2-Gas%20Sensor-orange?style=flat-square"/>
  <img src="https://img.shields.io/badge/Flame-Sensor-red?style=flat-square"/>
  <img src="https://img.shields.io/badge/Fire-Safety-critical?style=flat-square&color=red"/>
</p>

---

## 🛠️ Components Used

- 🔌 **Arduino Uno R3**
- 🌫 **MQ-2 Gas Sensor** (Smoke detection)
- 🔥 **Flame Sensor**
- 📢 **Buzzer** (Alarm)
- 💡 **LED** (Warning light)
- 🌬 **Exhaust Fan**
- 💧 **Water Sprinkler** (Fire response)
- 📟 **16x2 LCD Display**
- 🔌 **Relay Module**
- 🧠 Jumper wires, Breadboard, Power supply

---

## ✨ Features

- 🚨 Detects smoke and flame using sensors  
- 🔊 Triggers buzzer and warning LED automatically  
- 🌬 Activates exhaust fan to remove smoke  
- 💧 Starts sprinkler system for fire control  
- 📟 LCD shows real-time sensor data and warnings  
- 🛡 Ideal for small offices, homes, and labs

---

## 🔌 Circuit Overview

- MQ-2 Sensor → A0 (Analog)
- Flame Sensor → A1 (Analog)
- Fan Relay → A2
- Pump Relay → A3
- Buzzer → D8

---

## 🚀 How to Use

1. **Connect all components** as per the circuit.
2. **Upload code** to Arduino using Arduino IDE.
3. Power the board → system initializes.
4. If smoke/flame is detected:
   - LCD shows alert
   - Buzzer and LED activate
   - Fan and sprinkler turn on via relays

---

## 📁 Project Structure
├── smoke_fire_detector.ino → Arduino code
├── circuit_diagram.png → Circuit layout image
├── README.md → Project documentation
└── images/ → Demo photos / screenshots

---

## 📸 Preview

| Normal Condition | Smoke Detected | Fire Detected |
|------------------|----------------|----------------|
| ![](images/normal.png) | ![](images/smoke.png) | ![](images/fire.png) |

> Add images inside `images/` folder for display.

---

## 📌 Future Upgrades

- [ ] GSM module for SMS alerts  
- [ ] IoT integration for remote monitoring  
- [ ] Battery backup  
- [ ] Mobile app notification system  

---

## 👨‍💻 Author

**Muhammad Taha Ansari**  
Embedded Systems Enthusiast | Electrical Engineering Student  
📧 [tahaansari1703@gmail.com](mailto:tahaansari1703@gmail.com)  
🌐 [Portfolio](https://muhammadtaha-website.com)  
📍 Karachi, Pakistan

---

<p align="center"><i>"Detect early, respond instantly — a smart step toward fire safety."</i></p>

