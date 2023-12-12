#include<math.h>
#include <Wire.h>
#include "rgb_lcd.h"
float a , read;
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
const int above = 30;
const int below = 20;
const float low = 21;
void setup() {
  //setting up the pins;
  pinMode(A2 , INPUT);
  pinMode(A0, INPUT);
  pinMode(A3 , INPUT);
  pinMode(A1,INPUT);
  //setting up the pins
  Serial.begin(9600);
  lcd.begin(16 ,2 );
  lcd.print("Yan Sokal");
  pinMode(10,  OUTPUT);
}

void loop() {
  if(millis()-clock > 1000){
    clock = clock + 1000 ;
    Serial.println((count*60)/2);
    count=0;
  }
    //lcd.setCursor(0, 0);
    //lcd.print("low thr");
    //lcd.print(low);
    //lcd.setCursor(0,1);
   // lcd.print("High thr");
  //reading the pins 
    a  = analogRead(A2);
    read  = analogRead(A0);
    read1  = analogRead(A3);
    read2 = analogRead(A1);
  //reading the pins 
    analogWrite(10, 120);

  double threshhold = map(read1 ,  0 ,1023 , 23, 27);
  // lcd.print(threshhold);
  double R = 1023.0/a-1.0;
  double R3 = 1023.0/read-1.0;
  
  R = R0*R;
  R3 = R0*R3;
  double temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15;
  double tempa = 1.0/(log(R3/R0)/b+1/298.15)-273.15;
 // Serial.println(temperature);
 /* if(threshhold < temperature){
      analogWrite(10, 1900);
  }
  else if(low > temperature){
      analogWrite(10, 0);
  } */
  if(read2< 1000){
    count++;
  }
  delay(7);
;}

