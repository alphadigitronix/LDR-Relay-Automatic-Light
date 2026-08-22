# 💡 LDR Relay Automatic Light Using Arduino UNO

**Project 27 — ADS Arduino Inventor Kit**

## 📌 Abstract

The **LDR Relay Automatic Light** is an Arduino-based lighting automation mini project that automatically switches a light according to ambient brightness.

An **LDR sensor module** continuously measures the surrounding light level.

When the environment becomes dark, Arduino activates a **relay module**, representing an automatic light switching ON.

When the environment becomes sufficiently bright again, Arduino switches the relay OFF.

A status LED indicates the commanded light state, while the Serial Monitor displays the LDR reading and system status.

---

## 🎯 Objective

To build an automatic lighting-control system using an LDR sensor, Arduino UNO, and relay module.

---

## 🧰 Components Required

| Component                      |    Quantity |
| ------------------------------ | ----------: |
| Arduino UNO                    |           1 |
| LDR Sensor Module              |           1 |
| 1-Channel Relay Module         |           1 |
| LED                            |           1 |
| 330Ω Resistor                  |           1 |
| Breadboard                     |           1 |
| Jumper Wires                   | As required |
| USB Cable                      |           1 |
| Low-Voltage Demonstration Load |    Optional |

---

## 🔌 Component Connections

### LDR Sensor Module

| LDR Module | Arduino UNO |
| ---------- | ----------- |
| VCC        | 5V          |
| GND        | GND         |
| AO         | A0          |

The project uses the **analog output (AO)** so Arduino can monitor changes in light intensity.

### Relay Module

| Relay Module | Arduino UNO |
| ------------ | ----------- |
| VCC          | 5V          |
| GND          | GND         |
| IN           | D8          |

### Status LED

| LED         | Arduino UNO     |
| ----------- | --------------- |
| Anode (+)   | D6 through 330Ω |
| Cathode (−) | GND             |

---

## 🔄 System Flow

**Ambient Light**

↓

**LDR Sensor**

↓

**Arduino UNO**

↓

**Light-Level Decision**

↓

**Relay Module**

↓

**Automatic Light**

---

## ☀️🌙 Control Logic

Example thresholds used in the supplied program:

| LDR Reading | Condition       | Relay Light         |
| ----------: | --------------- | ------------------- |
|       ≤ 400 | Dark            | ON                  |
|     401–599 | Transition Zone | Keep previous state |
|       ≥ 600 | Bright          | OFF                 |

These are example values and should be calibrated for the actual LDR module and environment.

---

## 🔁 Why Two Thresholds?

The project uses:

**Dark threshold = 400**

**Bright threshold = 600**

Using separate ON and OFF thresholds prevents the relay from repeatedly switching when the sensor value fluctuates near a single threshold.

This technique is known as **hysteresis**.

---

## ⚙️ Working Principle

1. The LDR sensor detects ambient light.
2. Arduino reads its analog output through A0.
3. The ADC reading is compared with the programmed thresholds.
4. When the reading reaches the calibrated dark region, Arduino activates the relay.
5. The status LED turns ON.
6. The relay-controlled demonstration light is considered ON.
7. When ambient brightness rises sufficiently, Arduino deactivates the relay.
8. The status LED turns OFF.
9. The system continuously repeats the process.
---


---
## 💻 Arduino Code

The complete program is available in:

`LDR_Relay_Automatic_Light.ino`

No additional Arduino library is required.

---

## ▶️ How to Run

1. Assemble the circuit according to the connection tables.
2. Connect the LDR module's AO pin to A0.
3. Verify relay VCC, GND, and IN.
4. Connect Arduino UNO using USB.
5. Open `LDR_Relay_Automatic_Light.ino`.
6. Select **Arduino UNO**.
7. Select the correct COM port.
8. Upload the program.
9. Open Serial Monitor at **9600 baud**.
10. Observe the LDR reading in normal room light.
11. Cover the LDR sensor with your hand.
12. Observe the relay and LED.
13. Expose the sensor to bright light and observe the system again.

---

## 🧪 Calibration

LDR modules can produce different readings depending on the module and lighting conditions.

Before selecting the final thresholds:

1. Record the LDR value in bright light.
2. Record the value in normal room light.
3. Cover the sensor and record the dark value.
4. Choose suitable ON and OFF thresholds between these readings.

For example:

`Bright = 800`

`Room = 650`

`Dark = 250`

A possible configuration could then be:

`DARK_THRESHOLD = 400`

`BRIGHT_THRESHOLD = 600`

---

## ⚠️ Important LDR Note

Some LDR modules produce:

**Bright → Higher value**

**Dark → Lower value**

Other circuits/modules may behave in the opposite direction.

If your sensor reading increases when you cover the LDR, reverse the comparison logic in the program.

Always calibrate using the Serial Monitor before relying on fixed threshold values.

---

## 🔌 Relay Operation

Many Arduino-compatible relay modules are **active LOW**:

`LOW → Relay ON`

`HIGH → Relay OFF`

The supplied program assumes an active-LOW relay.

If your relay is active HIGH, reverse the relay output logic.

---

## ✅ Expected Output

### Dark Condition

Serial Monitor example:

`LDR Value: 275 | DARK -> LIGHT ON`

Result:

**Relay ON**

**Status LED ON**

### Bright Condition

Serial Monitor example:

`LDR Value: 780 | BRIGHT -> LIGHT OFF`

Result:

**Relay OFF**

**Status LED OFF**

---

## ⚠️ Safety Note

This project is designed as a **low-voltage educational automation prototype**.

Use an LED or another suitable low-voltage load to demonstrate relay operation.

Do not connect exposed household AC mains during beginner/student experiments.

---

## 📝 Notes

* Calibrate the LDR before selecting thresholds.
* Avoid positioning the LDR where the controlled light directly shines onto it during testing, as this can cause feedback and repeated switching.
* Verify whether your relay is active LOW or active HIGH.
* Use a 330Ω resistor with the status LED.
* The two-threshold design provides more stable switching.
* The project is intended for educational automation experiments.

---

## 🌍 Applications

* Automatic outdoor lighting
* Garden-light prototypes
* Corridor-light automation
* Night-light systems
* Smart-home lighting
* Energy-saving demonstrations
* Light-sensitive automation

---

## 🎓 Learning Outcomes

After completing this project, you will understand:

* LDR sensor interfacing
* Analog sensor readings
* `analogRead()`
* Relay module control
* Automatic lighting
* Threshold calibration
* Hysteresis
* Sensor-based automation
* Status indication

---

## 📜 License

This project is licensed under the **MIT License**.

Copyright (c) 2026 Alphadigitronix Solutions

See the `LICENSE` file for complete license terms.

---

## 🏢 Alphadigitronix Solutions

**ADS Arduino Inventor Kit**

**THINK • BUILD • INNOVATE**
