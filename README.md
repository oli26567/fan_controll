# Temperature-Controlled Fan

This project is an Arduino-based automatic fan control system that adjusts fan operation according to ambient temperature. It demonstrates core concepts of embedded systems, sensor interfacing, and hardware automation for efficient energy management.

---

## Functionality

- Temperature Sensing:
  - Uses a temperature sensor module (e.g., DHT11 or LM35) to measure ambient temperature in real time.
- Automatic Fan Control:
  - The Arduino compares the measured temperature against a predefined threshold (e.g., 25 °C).
  - When the temperature exceeds the threshold, the fan turns ON automatically.
  - When the temperature drops below the threshold, the fan turns OFF.
- Manual Reset:
  - A physical button allows users to manually stop the fan at any time while pressed.
- Display Output:
  - An LCD screen shows the current temperature (and optionally humidity), giving users clear feedback.
- Real-Time Processing:
  - The system continuously monitors temperature data and updates fan operation dynamically.

---

## How It Works
The Arduino continuously reads temperature values from the sensor and processes the data using its analog-to-digital converter. It then compares the current temperature against the defined threshold:

1. If temperature > 25 °C:
  Arduino sends a HIGH signal to the motor driver or transistor circuit to power the fan.
2. If temperature ≤ 25 °C:
  Arduino cuts off power to the fan.
3. If the reset button is pressed:
  The fan immediately turns off, regardless of temperature, resuming automatic control once released.
This setup demonstrates the integration of sensing, logic processing, and actuation in a simple yet practical automation circuit.

---

## Technologies Used

- Platform: Arduino Uno R3
- Language: Arduino C/C++
- Core Components:
  - Temperature sensor (e.g., DHT11 / LM35)
  - DC fan
  - LCD display
  - Push button
  - Breadboard and jumper wires
- Concepts:
  - Sensor data acquisition
  - PWM and digital I/O control
  - Conditional logic
  - User input handling
  - Real-time embedded system design
 
---

## Future Improvements

- Add adjustable temperature thresholds via potentiometer or digital input.
- Display additional data such as humidity and fan status on the LCD.
- Implement PID or fuzzy logic for smooth fan speed control.
- Integrate with Wi-Fi or Bluetooth for remote monitoring and control.
- Enclose the circuit in a compact 3D-printed housing for safety and aesthetics.

---

## Applications

- Home Automation: Automatically regulate fans or AC units for energy savings.
- Electronics Protection: Prevent overheating in PCs, servers, or control boxes.
- Industrial Systems: Maintain safe operating temperatures in manufacturing environments.
- Agriculture: Control ventilation or cooling systems in greenhouses.

