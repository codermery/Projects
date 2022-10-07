#include <Arduino.h>
/*
const int led = 5;

void setup() {
pinMode(led,OUTPUT);
Serial.begin(115200);
}
void loop() {

  digitalWrite(led,HIGH);
  delay(1000);


}
/

const int led = 5;

void setup() {
pinMode(led,OUTPUT);
Serial.begin(115200);
}
void loop() {
int sensorValue = analogRead(27); //A0 Analog Input Pininden sensör değerimizi okuyoruz ve sensorValue değişkenine atıyoruz.
Serial.print(sensorValue); //Serial Monitor kısmından sensör değerini görebilmemiz için sensorValue değişkenindeki değeri yazdırıyoruz.
   if (sensorValue < 9){
   digitalWrite(led,HIGH);
   }
   else{
   digitalWrite(led,LOW);
   }
delay(1000);
}

*/
#define timeSeconds 10

// Set GPIOs for LED and PIR Motion Sensor
const int led = 2;
const int motionSensor = 27;
const int analog_pin = 14;
//int situation = 0;

// Timer: Auxiliary variables
unsigned long now = millis();
unsigned long lastTrigger = 0;
boolean startTimer = false;

// Checks if motion was detected, sets LED HIGH and starts a timer
void IRAM_ATTR detectsMovement() {
  
  Serial.println("MOTION DETECTED!!!");
  digitalWrite(led, HIGH);
  startTimer = true;
  lastTrigger = millis();
}

void setup() {
  // Serial port for debugging purposes
  Serial.begin(115200);
  
  // PIR Motion Sensor mode INPUT_PULLUP
  pinMode(motionSensor, INPUT_PULLUP);
  pinMode(analog_pin, INPUT_PULLUP);
  //pinMode(situation,OUTPUT);
  // Set motionSensor pin as interrupt, assign interrupt function and set mode RISING
  //attachInterrupt(digitalPinToInterrupt(motionSensor), detectsMovement, FALLING);

  // Set LED to LOW
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
  // Current time
  /*if(analog_pin<=900){
    situation = 1;
  }*/
  now = millis();
  Serial.print("Analog Reading=");
  Serial.print(analogRead(analog_pin));
  Serial.printf(" ");
  Serial.print("\t Digital Reading=");
  Serial.println(digitalRead(motionSensor));
  //Serial.print("\t situation= ");
  //Serial.println(digitalRead(situation));
  delay(1000);
  // Turn off the LED after the number of seconds defined in the timeSeconds variable
  if(startTimer && (now - lastTrigger > (timeSeconds*1000))) {
  //  Serial.println("Motion stopped...");
    digitalWrite(led, LOW);
    startTimer = false;
  }
}
/*
// for ESP32 microcontroller
const int analog_pin = 4;
const int internal_LED = 2;

void setup(){
  Serial.begin(115200);
  pinMode(analog_pin, INPUT);
  pinMode(internal_LED, OUTPUT);
}

void loop(){
  Serial.print("analog Reading = ");
  Serial.println(analogRead(analog_pin));
  if(digitalRead(analog_pin) <= 400){
    digitalWrite(internal_LED, LOW); //turn off the led
  }
  else{
    digitalWrite(internal_LED, HIGH); //turn on the led
  }
  delay(1000);
}

// for ESP32 microcontroller
const int digital_pin = 4;
const int analog_pin = 14;

void setup(){
  Serial.begin(115200);
  pinMode(digital_pin,INPUT);
}

void loop(){
  Serial.print("Analog Reading=");
  Serial.print(analogRead(analog_pin));
  Serial.print("\t Digital Reading=");
  Serial.println(digitalRead(digital_pin));
  delay(1000);
}
*/
