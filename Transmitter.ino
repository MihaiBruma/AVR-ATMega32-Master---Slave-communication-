// Transmitter
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <Wire.h>
 const int rs = 13, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

 SoftwareSerial link(2, 3); // RX, TX - Communication
 LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

 byte lm35Pin = A0;
 float lm35V = 0;
 float tempC = 0;
 byte greenLED = 12;
 char text[20] ;
 char charVal[6];

  void setup() 
  {
    lcd.begin(16, 2);
    lcd.print("Temp is : 74.8*C");
    link.begin(9600);
    Serial.begin(9600);
    pinMode(greenLED, OUTPUT);
    
  }

  void loop()  
  {
   lcd.setCursor(0, 1);
   strcat(text, "Temp is: "); 
   digitalWrite(greenLED, HIGH);
   delay(100);
   digitalWrite(greenLED, LOW);
   lm35V = analogRead(lm35Pin);
   tempC = (lm35V/1023) * 500;
   dtostrf(tempC, 5, 1, charVal);  
   strcat(text, charVal); 
   text[16] = 0; 
   strcat(text, "*C");
   Serial.println(text); 
   link.println(text);
      
   delay(200);
  }
