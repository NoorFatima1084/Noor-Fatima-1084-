Embedded IoT Systems — Homework 2
Dual-LED PWM Control with OLED Monitoring (ESP32)
Student: Noor Fatima
Class: IoT_BCS_B-5th
Registration No.: 24-NTU-CS-FL-1084  
Project Overview
This project uses an ESP32 to fade two LEDs with Pulse Width Modulation (PWM). Each LED operates at a different PWM frequency. In Task 2, an SSD1306 I²C OLED is added to display the live duty-cycle percentage and configured frequency of both LEDs.
Tasks
Task 1: Dual-LED PWM Control
- Connect two LEDs to the ESP32, each with its own 220 Ω current-limiting resistor.
- LED 1 uses a PWM frequency of 1000 Hz (1 kHz) on GPIO25.
- LED 2 uses a PWM frequency of 5000 Hz (5 kHz) on GPIO26.
- Both LEDs fade smoothly from minimum to maximum brightness and back.
- The LEDs operate in opposite phases: while one becomes brighter, the other becomes dimmer.
- PWM uses an 8-bit resolution, giving duty values from 0 to 255.
- The Task 1 Wokwi test initially used GPIO25 and GPIO26; the final code and hardware use GPIO18 and GPIO19.
Task 2: OLED Monitoring
- Add an SSD1306 OLED display (128×64, I²C) to the Task 1 circuit.
- The OLED continuously displays the duty-cycle percentage and PWM frequency for both LEDs.
- The display uses the same duty values that are written to the LED PWM outputs.
- LED 1 is displayed at 1000 Hz and LED 2 at 5000 Hz.
- The LEDs continue fading in opposite phases while the OLED updates.
Components and Tools
- ESP32 DevKit board
- 2 LEDs (red and green)
- 2 × 220 Ω resistors
- SSD1306 OLED display (128×64, I²C)
- Breadboard and jumper wires
- VS Code with PlatformIO
- Wokwi simulator
- Git and GitHub
- Adafruit SSD1306 library
- Adafruit GFX Library
Pin Connections
Component	ESP32 connection
LED 1 anode	GPIO18 through a 220 Ω resistor
LED 1 cathode	GND
LED 2 anode	GPIO19 through a 220 Ω resistor
LED 2 cathode	GND
OLED VCC	3V3
OLED GND	GND
OLED SDA	GPIO21
OLED SCL	GPIO22
OLED I²C address	0x3C


How It Works
1. The ESP32 configures the two PWM outputs at 1 kHz and 5 kHz with 8-bit resolution.
2. The program increases or decreases each LED's duty value in steps of 5.
3. The direction reverses when a duty value reaches 0 or 255.
4. A 20 ms delay is used between steps, producing a smooth fade.
5. In Task 2, the program converts the duty values into percentages and refreshes the OLED display.
Software Setup
1. Open the project folder in VS Code with PlatformIO installed.
2. Make sure the project uses the ESP32 DevKit board and Arduino framework.
3. Install the required libraries through platformio.ini:
   - adafruit/Adafruit SSD1306
   - adafruit/Adafruit GFX Library
4. Build the project and run the Wokwi simulation, or connect the ESP32 hardware and upload the program.
5. For Task 1, use the version of src/main.cpp without OLED support. For Task 2, use the final version that includes OLED support.
Project Structure
Embedded-IoT-Homework-2/
├── diagram.json
├── wokwi.toml
├── platformio.ini
├── src/
│   └── main.cpp
├── screenshots/
│   ├── wokwi_circuit.png
│   ├── wokwi_running_oled.png
│   ├── hardware_circuit.jpg
│   └── hardware_oled_output.jpg
└── README.md
Results
- Task 1: Both LEDs faded smoothly in opposite phases in the Wokwi simulation and on the physical hardware.
- Task 2: The OLED displayed the live duty-cycle percentages and the configured frequencies of both LEDs.
- Since the LEDs operate in opposite phases, their displayed duty-cycle percentages add up to approximately 100% (allowing for rounding).
- The project was tested in Wokwi and on the physical ESP32 circuit.
Safety
- Use a separate 220 Ω current-limiting resistor for each LED.
- Connect the OLED VCC to 3V3.
- Disconnect power before changing circuit wiring.
GitHub
Repository: https://github.com/NoorFatima1084/Noor-Fatima-1084-