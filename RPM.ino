//relevent websites
//https://noctua.at/de/products/fan
//https://learn.sparkfun.com/tutorials/pull-up-resistors/all
//https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/


const int threshold = 100;  
unsigned long pulseCount = 0;  
bool pulseInProgress = false;  
unsigned long lastTime = 0;  
unsigned int totcounts = 0;
unsigned int duty = 10;

void setup() {
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  pinMode(A1,INPUT);
  analogWrite(10,10); //setting the different value 

}

void loop() {
  int sensorValue = analogRead(A1);
  totcounts++;

  if (sensorValue > threshold) {
    if (!pulseInProgress) {
      pulseInProgress = true;
      pulseCount++;
    }
  } else {
    pulseInProgress = false;  
  }

  if (millis() - lastTime >= 1000) {
    if(duty!=255){
    analogWrite(10, duty);
    duty++;
    }
    Serial.print(duty);
    Serial.print(" ");
    Serial.println(pulseCount*60/2); 

    pulseCount = 0;  // setting the value again to 0
    lastTime = millis();  //settting the period to 0 
    totcounts = 0; // setting counting to 0

  }
}