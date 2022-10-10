#include <Arduino.h>
/*
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
const int led =4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,HIGH);
  Serial.println("Led is on");
  delay(4);
  digitalWrite(led,LOW);
  Serial.println("Led is off");
  delay(1);
}
const int buttonPin = 4;
const int led1Pin = 5;
const int led2Pin = 27;

int ledDurum = HIGH;         // çıkış pininin son durumu
int butonDurum=0;           // giriş pininin son durumu
int butonSonDurum = LOW;   // giriş pininden okunan önceki durum


unsigned long sonArkSuresi = 0;      
unsigned long gecikme = 50;    

void setup() {
  // put your setup code here, to run once:
  
  pinMode(buttonPin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() {

    int butonDeger = digitalRead(buttonPin); // ilk değerrimizi okuyoruz.

  if (butonDeger == 1) {
    digitalWrite(led1Pin,!digitalRead(led1Pin));//Kodlarda butona bastığımızda ledin yanmasını ve açık kalmasını sağlayan kod if koşul bloğu içindeki digitalWrite(led,!digitalRead(led)); kodudur.
      Serial.printf("if içinde : %d\n",butonDeger);
      Serial.println(!digitalRead(led1Pin));
    
  }
  if (butonDeger == 1) {
    digitalWrite(led2Pin,!digitalRead(led2Pin));//Kodlarda butona bastığımızda ledin yanmasını ve açık kalmasını sağlayan kod if koşul bloğu içindeki digitalWrite(led,!digitalRead(led)); kodudur.
      Serial.printf("if içinde : %d\n",butonDeger);
      Serial.println(!digitalRead(led2Pin));
    
  }*/
  /*/// put your main code here, to run repeatedly:
  if(digitalRead(buttonPin) == 0) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, LOW); 
  }else {
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, HIGH); 
  }
  //delay(1000);/
}*/
const int butonPin = 4;    // butonun bağlı olduğu pin
const int ledPin = 5;      // led'in bağlı olduğu pin

int ledDurum = HIGH;         // çıkış pininin son durumu
int butonDurum=0;           // giriş pininin son durumu
int butonSonDurum = LOW;   // giriş pininden okunan önceki durum

unsigned long sonArkSuresi = 0;      
unsigned long gecikme = 50;    

void setup() {
  pinMode(butonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  digitalWrite(ledPin, ledDurum);
}

void loop() {
  
  int butonDeger = digitalRead(butonPin); // ilk değerrimizi okuyoruz.

  if (butonDeger != butonSonDurum) {// ilk durumdan farklı ise millis komutu ile süreyi //başlatıyoruz
    sonArkSuresi = millis();
  }

  if ((millis() - sonArkSuresi) > gecikme) {// başta atadığımız gecikme süresini aşmış ise //butonun 1 veya 0 olduğuna dair kesin bir atama yapıyoruz.
    if (butonDeger != butonDurum) {
      butonDurum = butonDeger;
      if (butonDurum == HIGH) {
        ledDurum = !ledDurum;
      }
    }
  }

  digitalWrite(ledPin, ledDurum);

  butonSonDurum = butonDeger; // en son aldığımız değeri buton son durumuna yazıyoruz.
}

