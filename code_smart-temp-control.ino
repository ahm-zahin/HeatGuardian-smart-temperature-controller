const int sensorPin = A3;   // TMP36 Sensor
const int motorPin = 6;     // Motor connected to PWM pin 6
const int grnLed = 4;       //Green LED indicator
const int redLed = 2;       //Red LED indicator
const int buzzPin = 3;

float vRead;
float temp;

const int maxRPM = 3000;    // Maximum RPM at full PWM

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(grnLed, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  vRead = analogRead(sensorPin);
  vRead = (vRead * 5.0) / 1024.0;  // Voltage
  temp = (vRead - 0.5) * 100.0;    // Temperature in °C

  // Map temp to PWM (example: 29°C = 0 PWM, 99°C = 255 PWM)
  int motorPWM = map(temp, 29, 99, 0, 255);
  motorPWM = constrain(motorPWM, 0, 255);
  analogWrite(motorPin, motorPWM);

  //LED indicator
  if(temp < 40){
    digitalWrite(grnLed, HIGH);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzPin, LOW);
  }
  
  else if(temp > 79){
    digitalWrite(grnLed, LOW);
    digitalWrite(redLed, HIGH);
    digitalWrite(buzzPin, HIGH);
    delay(100);
  }
    
  else {
    digitalWrite(redLed, digitalRead(redLed)^1);
    digitalWrite(grnLed, LOW);
    digitalWrite(buzzPin, LOW);
  }
  
  
  // Serial monitoring
  Serial.print("Temp C: ");
  Serial.print(temp);
  Serial.print("\tMotor PWM: ");
  Serial.println(motorPWM);

  delay(1000);
}
