#include <Arduino.h>
/*

int Pin=2;
int rPin=4;
int gPin=14;
int bPin=13;
void setup()
{
  pinMode(Pin,OUTPUT);
  pinMode(rPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  pinMode(bPin,OUTPUT);
}
void loop()
{
  digitalWrite(Pin,HIGH);
  digitalWrite(rPin,HIGH);
  digitalWrite(gPin,HIGH);
  digitalWrite(bPin,HIGH);
}
*/
int rPin=4;
int gPin=14;
int bPin=13;
 
//Potansiyometre bağlantı pinlerini tanımlıyoruz. 
const byte redPot=27;
const byte greenPot=12;
const byte bluePot=25;
 
//Potansiyometreden okunacak değerler için değişkenleri tanımlıyoruz. 
int potDegerR; int potDegerG; int potDegerB;
 
void setup() {
//RGB led pin bağlantılarını çıkış pini olarak tanımlıyoruz. 
pinMode(rPin,OUTPUT);
pinMode(gPin,OUTPUT);
pinMode(bPin,OUTPUT);
Serial.begin(115200); 
}
 
void loop() {
//Potansiyometre değerlerini okuyup değişkenlere aktarıyoruz.  
potDegerR=analogRead(redPot);
potDegerG=analogRead(greenPot);
potDegerB=analogRead(bluePot);
 
//Potansiyometre değerlerini pwm sinyallerine dönüştürüyoruz.
int potDr=map(potDegerR,0,4095,0,255);
int potDg=map(potDegerG,0,4095,0,255);
int potDb=map(potDegerB,0,4095,0,255);
 
//RGB led pinlerine potansiyometre değerlerini yazdırıyoruz.
analogWrite(rPin,potDr);
analogWrite(gPin,potDg);
analogWrite(bPin,potDb);

Serial.println("potDegerR");
Serial.println(potDr);
Serial.println("potDegerG");
Serial.println(potDg);
Serial.println("potDegerB");
Serial.println(potDb);
delay(100);
}
