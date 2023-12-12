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
float expected =25.5;
unsigned int dutyup= 25;
unsigned int dutydown =255; 
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
  analogWrite(10 ,  255);
  startMillis = millis();
;}
void loop() {
   
   
   //reading the values from the arduino
  
    a = analogRead(A1);
    read = analogRead(A3);
    read1 =  analogRead(A2);

    lcd.setCursor(0, 1);
    lcd.print(dutyup);
    lcd.print(" ");
    lcd.print(dutydown);
    double R3 = 1023.0/read1-1.0;
    R3 = R0*R3;
    double tempa = 1.0/(log(R3/R0)/b+1/298.15)-273.15;
    
    if(tempa > expected + 0.3){
        if(dutydown!=255){
          dutydown++;
        }
        analogWrite(10 ,  dutydown);
    }
    else if(tempa < expected - 0.3){
        if(dutydown!=0){
          dutydown--;
        }
        analogWrite(10 ,  dutydown);
    }
    Serial.print(dutydown);
    Serial.print(" ");
    Serial.println(tempa);
    
    delay(500);

  //reading the values of the arduino
}
