# Temperature-Controlled Fan with Warning Indicators

This Arduino project automatically adjusts the speed of a DC motor (fan) based on ambient temperature using a TMP36 sensor. It includes visual (LEDs) and auditory (buzzer) alerts for specific temperature ranges.

## 🔧 Features

- 🌀 Motor speed controlled using PWM based on temperature.
- 🟢 Green LED for safe temperature (< 40°C).
- 🔴 Red LED for caution (40°C–79°C) and steady warning if > 79°C.
- 🔊 Buzzer alarm at critical temperatures (> 79°C).
- 📟 Serial monitor displays temperature and PWM values.

## 🧰 Components Used

| Component                             |  Quantity |
|---------------------------------------|-----------|
| Arduino UNO                           | 1         |
| TMP36 Temperature Sensor              | 1         |
| DC Motor (or Fan)                     | 1         |
| Green LED                             | 1         |
| Red LED                               | 1         |
| Buzzer                                | 1         |
| Breadboard + Jumper Wires + Resistors | As needed |

## 🔌 Pin Configuration

| Arduino Pin | Connected To     |
|-------------|------------------|
| A3          | TMP36 Output     |
| 6           | Motor (via PWM)  |
| 4           | Green LED        |
| 2           | Red LED          |
| 3           | Buzzer           |

## 🧠 How It Works

- **< 40°C**  : Green LED on, motor may run at low PWM, buzzer off.
- **40–79°C** : Red LED blinks, indicating caution. Motor speed increases with temperature.
- **> 79°C**  : Red LED stays on, buzzer sounds continuously to alert danger.

## 📈 Serial Output

Example output from Serial Monitor:
