#include<math.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
const int B = 4275;
const int R0 = 100000; 
const int colorR = 255;
const int colorG = 124;
const int colorB = 123;
const int above = 50;
const int below = 0;
//const int threshhold = 30;
void setup() 
{
    pinMode(2 , OUTPUT);
    //digitalWrite(2, HIGH); 
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    // Print a message to the LCD.
    lcd.print("Yan's cool !");
    Serial.begin(9600);
    delay(1000);
}


void loop() {
  int a , read;
  read = analogRead(A3);
  a = analogRead(A0);
  float threshhold =map(read ,  0 ,1023 , 20, 30);
  float R = 1023.0/a-1.0;

  R = R0*R;
  float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15;
  Serial.println("temperature");
  Serial.println(temperature);
  lcd.print("Yan's cool !");
  lcd.print(temperature); 
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(threshhold);
  lcd.setCursor(0, 0 );
  if( temperature > threshhold ){
    digitalWrite(2, LOW); 
    Serial.println(below);
  }
  else{
    digitalWrite(2 , HIGH);
    Serial.println(above);
  }
  //Serial.print("C ");
  delay(1000); 
}
