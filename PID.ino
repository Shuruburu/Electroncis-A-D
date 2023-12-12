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
const int above = 30;
const int below = 20;
const float low = 21;
unsigned long startMillis;
float  Integral = 0;
float proportional = 0;
float derivatie = 0;
float expected =25;
float error;
int duty = 127;
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
  analogWrite(10 ,  duty);
  startMillis = millis();
;}
void loop() {
    count++;
    a = analogRead(A1);
    read = analogRead(A3);
    read1 =  analogRead(A2);
    //expected = map(read ,  0 ,1023 , 21, 26);
    //analogWrite(10 ,threshhold);  
    lcd.setCursor(0, 1);
    lcd.print(expected);
    double R3 = 1023.0/read1-1.0;
    R3 = R0*R3;
    double tempa = 1.0/(log(R3/R0)/b+1/298.15)-273.15;
    //Serial.println(tempa);
    //calculating the errors
    Integral = Integral + (expected  - tempa);
    derivatie =  proportional  -  (expected  - tempa);
    proportional  = expected  - tempa;
    error = 2*(Integral/count) + derivatie + 2*proportional;
    if(abs(error) > 0.2){
      if(error > 0){
        if(duty !=0){
          duty--;
        }
        analogWrite(10 ,duty); //cos 
      }
      else{
        if(duty!=255){
          duty++;
        }
        analogWrite(10 ,duty);
      }
    }
    Serial.println(tempa);
    delay(500);
}
