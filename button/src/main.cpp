#include <Arduino.h>
/*
int buton = 2;
int led = 3;
int butonDurum;
 
void setup() {
  pinMode(led, OUTPUT); //Led pinini çıkış pini olarak ayarladık.
  pinMode(buton, INPUT); //buton pinini giriş pini olarak ayarladık.
}
 
void loop() {
  butonDurum = digitalRead(buton); //buton değerini okutup değişkene aktardık.
  delay(250);
  if (butonDurum == 1) {
    digitalWrite(led,!digitalRead(led));
  }
}
 

int button = 4;
int led = 5;
int buttonState;
 
void setup() {
  Serial.begin(115200);  
  pinMode(led, OUTPUT); //Led pinini çıkış pini olarak ayarladık.
  pinMode(button, INPUT); //buton pinini giriş pini olarak ayarladık.
}
 
void loop() {
  buttonState = digitalRead(button); //buton değerini okutup değişkene aktardık.
  Serial.println(buttonState);
  delay(250);
  if (buttonState == 1) {
    digitalWrite(led,!digitalRead(led));//Kodlarda butona bastığımızda ledin yanmasını ve açık kalmasını sağlayan kod if koşul bloğu içindeki digitalWrite(led,!digitalRead(led)); kodudur.
      Serial.printf("if içinde : %d\n",buttonState);
      Serial.println(!digitalRead(led));
    
  }
  
}
*/
// Ark sorununa yazılımsal çözüm!!!
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
