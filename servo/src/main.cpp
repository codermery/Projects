#include <Arduino.h>
#include <ServoESP32.h> 

static const int servoPin=4;
static const int potaentiometerPin=15;

Servo_ESP32 servo1;

void setup(){

    Serial.begin(115200);
    servo1.attach(servoPin);  
}
void loop(){

    int servoPosition = map(analogRead(potaentiometerPin),0,4096,0,180);
    servo1.write(servoPosition);
    Serial.println(servoPosition);
    delay(20);
}
