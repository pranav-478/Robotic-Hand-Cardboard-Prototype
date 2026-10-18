# 🦾 Robotic Hand Gripper (Failed V1 Prototype)

![Robotic Hand Prototype]
<img width="1600" height="1200" alt="failed_attempt_robot_hand_picture" src="https://github.com/user-attachments/assets/dbc8346a-2eab-491d-a720-94616006a6fb" />


A rapid cardboard and string-actuated robotic hand prototype controlled by an Arduino Nano, an analog joystick, and two micro servos. 

## 🎥 Demo Video


https://github.com/user-attachments/assets/77617a10-a1ea-4248-a042-67bc8c41321e



> **⚠️ Prototype Status: FAILED / EXPERIMENTAL** 
> This repository documents a V1 physical build that did not meet its mechanical objectives. The code functions perfectly, but the physical mechanics of the cardboard and thread failed to grip objects as intended.

---

## 🚀 Project Overview
The goal of this project was to build a functional, low-cost robotic gripper that could curl around and hold objects based on analog joystick inputs. 
* **Servo 1 (Base):** Attached to the base to control the overall orientation of the hand.
* **Servo 2 (Tendon/Thread):** Attached to a string threaded through the cardboard fingers. Pulling the string was supposed to curl the hand inwards to grip an object.

## 💥 Why It Failed (Lessons Learned)
While the electronic hardware and Arduino code worked flawlessly, the mechanical design failed to achieve a functional grip.
1. **Insufficient Curling:** I expected the string-actuated mechanism to curl the cardboard significantly more than it did. The tension only caused a slight bend rather than a full grasping motion.
2. **Lack of Multi-Joint Articulation:** Because the cardboard lacked proper segmented joints (like human knuckles), the string simply bowed the material instead of folding it around an object.
3. **Next Steps for V2:** A future iteration needs individually hinged 3D-printed or precisely scored joints, and potentially multiple strings (tendons) for individual finger control rather than a single bulk pull.

---

## ⚙️ How the Code Works
The code reads analog inputs from an XY Joystick and directly maps them to servo angles.
* **X-Axis (`A1`):** Controls the base servo ("white servo").
* **Y-Axis (`A2`):** Controls the thread-pulling servo ("black servo").
* **Math:** Reads the raw analog values (0 to 1023) and scales them to a safe degree angle (0° to 180°) using a standard linear equation `(180.0 / 1023.0) * analogValue`.
* **Safety Constraint:** Uses the `constrain()` function to ensure the servos are never pushed past their 180-degree physical limit, preventing stripped gears.

---

## 🛠️ Hardware Stack
* **Microcontroller:** Arduino Nano
* **Actuators:** 2x SG90 Micro Servos
* **Input:** Analog XY Joystick Module
* **Body:** Cardboard, Thread/String, Tape
* **Wiring:** Breadboard and Jumper Wires

### Pinout Guide
| Component | Pin on Arduino Nano |
| :--- | :--- |
| **White Servo (Base)** | Digital Pin 3 |
| **Black Servo (Thread)** | Digital Pin 4 |
| **Joystick X-Axis** | Analog Pin A1 |
| **Joystick Y-Axis** | Analog Pin A2 |
| **Joystick VCC/GND** | 5V / GND |
