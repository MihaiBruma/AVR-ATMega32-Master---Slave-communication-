//Receiver 
 #include <SoftwareSerial.h>
 //#include <Adafruit_LiquidCrystal.h>
 //#include <Wire.h>

  SoftwareSerial link(2, 3); // RX, TX - Communication
  //Adafruit_LiquidCrystal lcd(0);

  byte greenLED = 12;
  char cString[20];
  byte chPos = 0;
  byte ch = 0;
  char dataStr[6];

  void setup() 
  {
  link.begin(9600); 
  Serial.begin(9600);    
  pinMode(greenLED, OUTPUT);
  }

  void loop()  
  {  
 // if (link.available())
 //     Serial.write(link.read());
 // if (Serial.available())
 //     link.write(Serial.read());
  //lcd.setCursor(0, 1);
  //lcd.setBacklight(1);
   while(link.available())
   {
     ch = link.read();
     cString[chPos] = ch;
     chPos++;     
     
   digitalWrite(greenLED, HIGH); 
   delay(100);
   digitalWrite(greenLED, LOW);
   }
   cString[chPos] = 0; 
   chPos = 0;
   
   Serial.print(cString);
  }

