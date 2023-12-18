#include<math.h>
#include <Wire.h>
#include "rgb_lcd.h"
float a , read;
float previous = 0;
rgb_lcd lcd;
int count = 0;
long int clock =0 ;
float  read1, read2  ;
const int B = 4600;
const int R0 = 100000; 
const int b = 4275;
const int colorR = 255;
const int colorG = 124;
const int colorB = 123;
const int up= 50;
const int down  =  0 ;
void setup() {
  //loading the pins 
  pinMode(A0, INPUT);
  pinMode(A1 , INPUT);
  pinMode(A2 , INPUT);
  pinMode(A3 , INPUT);

  //
  Serial.begin (9600);
  lcd.begin(16 , 2);
}

void loop() {
  //reading the temperature
  lcd.setCursor(0, 0);
  read =analogRead(A0);
  double R3 = 1023.0/read-1.0;
  R3 = R0*R3;
  double tempa = 1.0/(log(R3/R0)/b+1/298.15)-273.15;
  //
  
  
  //reading and converting the voltage to thereshold
  read1  = analogRead(A3);
  float threshold = map(read1 , 0 ,1023 , 20 , 30);
  lcd.print("temperature ");
  lcd.setCursor(0, 1);
  lcd.print(tempa);
  //
  if(tempa >  threshold){
    Serial.println(up);
    Serial.print(" ");
       
  }
  else{
    Serial.println(down);
    Serial.print(" ");
  }
  delay(1000);
}
