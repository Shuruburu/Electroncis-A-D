void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    pinMode(2,OUTPUT );
    digitalWrite(2, HIGH);
    pinMode(3,OUTPUT );
}

void loop() {
      digitalWrite(2, LOW);
      digitalWrite(3 , LOW);
      delay(500);
      digitalWrite(3 , HIGH) ;
      delay(500);
      digitalWrite(2, HIGH);
      digitalWrite(3  ,LOW);
      delay(500);
      digitalWrite(3, HIGH);
      delay(500);
}
