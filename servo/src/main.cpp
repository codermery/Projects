#include <Arduino.h>
/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-servo-motor-controlled-by-potentiometer
 */

#include <Servo.h>

#define PIN_POTENTIOMETER 12 // ESP32 pin GIOP36 (ADC0) onnected to potentiometer
#define PIN_SERVO         4 // ESP32 pin GIOP26 onnected to servo motor

Servo myServo;  // create servo object to control a servo

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  myServo.attach(PIN_SERVO);  // attaches ESP32 pin to the servo object
}

void loop() {
  // reads the value of the potentiometer (value between 0 and 4095)
  int analogValue = analogRead(PIN_POTENTIOMETER);

  // scales it to use it with the servo (value between 0 and 180) //map(value, fromLow, fromHigh, toLow, toHigh)
  int angle = map(analogValue, 0, 4095, 0, 180);

  // sets the servo position according to the scaled value
  myServo.write(angle);

  // print out the value
  Serial.print("Analog value: ");
  Serial.print(analogValue);
  Serial.print(" => Angle: ");
  Serial.println(angle);
  delay(100);
}
