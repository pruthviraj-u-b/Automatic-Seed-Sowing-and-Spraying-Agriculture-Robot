# Automatic-Seed-Sowing-and-Spraying-Agriculture-Robot
An autonomous Arduino-based robot designed to automate seed sowing and pesticide spraying. It navigates fields to dig soil, drop seeds at set intervals, cover them, and spray liquid with minimal human labor. Controlled via Bluetooth, it provides a low-cost, smart farming solution for small-scale farmers.


---

## 🧠 System Architecture & Key Features

* **Central Control Hub:** Leverages an Arduino Mega 2560 microcontroller utilizing 54 digital I/O and 16 analog pins for low-latency, real-time peripheral control.
* **Multi-Task Mechanical Integration:** Unifies four distinct farming operations—soil preparation (digging), servo-controlled seed dropping, mechanical soil coverage, and automated fluid distribution—into a single mobile platform.
* **High-Torque Mobility Dynamic:** Powered by four 150 RPM DC geared motors driven by an L298N dual H-Bridge motor driver, enabling steady $0.5\text{ m/s}$ navigation through rugged field terrains.
* **Wireless Command Link:** Integrates an HC-05 Bluetooth module for serial UART communication, enabling operators to remotely manage field movement and calibrate seeding intervals dynamically.
* **Dual-Mode Precision Actuation:** Uses an MG995 high-torque metal gear servo for heavy position adjustments alongside SG90 micro servos for high-accuracy, lightweight seed-dropper metering.

---

## 📈 Validated Performance Results

* **Seamless Multi-Function Execution:** Confirmed capability to perform soil furrowing, seed placement, and row closing sequentially in a single pass.
* **Configurable Spacing Metrics:** Successfully executed uniform seeding intervals calibrated between 10cm to 20cm based on crop-specific requirements.
* **Ultra-Low Cost Prototyping:** Achieved full system fabrication and multi-hazard agricultural deployment within a validated, budget-friendly hardware constraint of ₹4,219.

---

## 🛠️ Tech Stack & Hardware Components

### Software & Libraries
* **Languages:** C++ / C
* **Development Environment:** Arduino IDE
* **Libraries:** `Servo.h`, `SoftwareSerial.h`

### Hardware Bill of Materials (BOM)
* **Microcontroller:** Arduino Mega 2560 Core
* **Motor Driver:** L298N Dual H-Bridge Module
* **Wireless Link:** HC-05 Bluetooth Module
* **Actuators:** MG995 High-Torque Servo, SG90 Micro Servos
* **Drivetrain:** 4x 150 RPM DC Geared Motors
* **Fluid Subsystem:** 5V Sprinkler Submersible Pump, 2-Channel Relay Module
* **Power Architecture:** 14.8V Li-ion Battery Pack, LM2596 DC-DC Buck Converter


