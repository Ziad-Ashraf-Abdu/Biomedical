# Biomedical

A collection of Arduino-based biomedical instrumentation and sensor projects. This repository brings together several standalone sketches that demonstrate how to build simple, low-cost devices for measuring physiological or environmental parameters and driving ultrasound transducers.

---

## 🚀 Projects Overview

1. **Photometric Glucose Monitor**

   * Uses an LED and photodiode to estimate “glucose concentration” via light absorption
   * Displays readings and status (No Sample / Prediabetes / Diabetic / Severe Diabetes) on a 16×2 LCD
   * Serial logging every 2 seconds

2. **HIFU Neuromodulation DIY**

   * Reads ambient light via a photodiode
   * Converts light level into a custom assembly–driven delay loop
   * Toggles a digital pin to generate a square‑wave pulse train whose frequency varies with light intensity
   * Serial output for sensor and delay values

3. **Ultrasonic Distance & Speed Meter**

   * Uses an HC‑SR04 ultrasonic sensor to measure distance in cm
   * Computes object speed by comparing two readings one second apart
   * Displays distance and speed on a 16×2 LCD
   * “Approach alert” message when an object comes within 5 cm
   * Continuous serial logging

---

## 📁 Repository Structure

Biomedical/
│
├── Glucose\_Monitor/
│   └── Glucose\_Monitor.ino
│
├── HIFU\_Neuromodulation\_DYI/
│   └── HIFU\_Neuromodulation\_DYI.ino
│
├── Ultrasonic\_Distance\_Speed\_Meter/
│   └── Ultrasonic\_Distance\_Speed\_Meter.ino
│
└── README.md

---

## ⚙️ Prerequisites

* Arduino UNO (or compatible) board
* USB cable for programming
* 16×2 character LCD + I²C backpack or direct wiring (Photometric & Distance/Speeder)
* LED and current‑limiting resistor
* Photodiode or phototransistor sensor
* Ultrasonic sensor module (HC‑SR04)
* Transducer capable of HIFU frequencies (for the Frequency Converter)
* Jumper wires, breadboard, and basic electronic components

---

## 🔧 Installation & Wiring

1. Clone the repository from [https://github.com/Ziad-Ashraf-Abdu/Biomedical.git](https://github.com/Ziad-Ashraf-Abdu/Biomedical.git) and navigate into it.
2. Open the desired `.ino` sketch in the Arduino IDE (File > Open).
3. Wire up components following the pin definitions in each sketch’s top comments.
4. In the Arduino IDE, select your board under Tools > Board and the correct USB port under Tools > Port.
5. Upload the sketch, then open the Serial Monitor at 9600 baud to view output. The LCD (and any LEDs) will provide live feedback.

---

## ▶️ Usage

* **Photometric Glucose Monitor**: Place your sample under the LED/photodiode assembly and watch the LCD update “Glucose Conc.” and status every 2 seconds.
* **HIFU Neuromodulation DIY**: Vary ambient light on the photodiode to change pulse frequency; observe “Sensor” and “Delay” values in the Serial Monitor.
* **Analog‑to‑HIFU Frequency Converter**: Adjust your analog input (potentiometer or sensor) to sweep ultrasound drive frequency; monitor readings on Serial.
* **Ultrasonic Distance & Speed Meter**: Position an object in front of the HC‑SR04; the LCD shows distance and speed. If an object comes within 5 cm, the “Team Shooky” message appears until it moves away.

---

## 🤝 Contributing

Contributions are welcome!

1. Fork the repository
2. Create a feature branch: `git checkout -b feature/YourFeature`
3. Commit your changes: `git commit -m "Add some feature"`
4. Push to your branch: `git push origin feature/YourFeature`
5. Open a Pull Request

Please describe your changes and test on an Arduino-compatible board.

---

## 📄 License

This project is licensed under the MIT License. See LICENSE for details.

---

## 📬 Contact

If you have questions or suggestions, feel free to open an issue or reach out to [ziad.mohamed04@eng-st.cu.edu.eg](mailto:ziad.mohamed04@eng-st.cu.edu.eg). Happy tinkering!
