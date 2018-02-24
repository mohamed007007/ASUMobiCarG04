int pulse=8;
void setup() {
  pinMode(pulse, OUTPUT);
}

void loop() {
 digitalWrite(pulse,HIGH);  
  delay(500);  
  digitalWrite(pulse,LOW);  
  delay(1500);  
                                     
}
