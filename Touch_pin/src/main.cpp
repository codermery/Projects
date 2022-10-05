#include <Arduino.h>
// ESP32 Touch Test
// Just test touch pin - Touch0 is T0 which is on GPIO 4.
#define led 2
void setup() {
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Touch Test");
  pinMode (led, OUTPUT);
}

void loop() {
  Serial.println(touchRead(4));  // get value of Touch 0 pin = GPIO 4
  if (touchRead(4)<=25)
      digitalWrite(led,HIGH);
  else
      digitalWrite(led,LOW);
  delay(1000);
}
