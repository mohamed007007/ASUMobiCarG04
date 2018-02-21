
int i;                      //Integer variable for Counter 
void setup(){
  for (i=2;i<10;i++){       // Define Digital pin as OUTPUT Pin.
  pinMode(i,OUTPUT);
}
}
// Void setup ended _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
void loop(){
 //In loop area  4 program will execute 
 // first one , blink on one led each time starting from pin 2
  for(i=1;i<10;i++){
    digitalWrite(i,HIGH);
     delay(150);
    digitalWrite(i,LOW);
     delay(10);
}
//First program end

//******************************************************

// Second program , blink on one led each time starting from pin 9
for(i=10;i>1;i--){
    digitalWrite(i,HIGH);
     delay(150);
    digitalWrite(i,LOW);
     delay(10);
}
//Second program end

//******************************************************

// Third program , blink on 3 led each time starting from pin 1 and shifting
//it  LST FIRST
  for(i=1;i<11;i++){
    digitalWrite(i-1,HIGH);
    digitalWrite(i,HIGH);
     digitalWrite(i+1,HIGH);
     delay(150);
     digitalWrite(i-1,LOW);
    digitalWrite(i,LOW);
     digitalWrite(i+1,LOW);
     delay(10);
}
//Third program end

//******************************************************

// fourth program , blink on 3 led each time starting from pin 1 and shifting
//it  MSB FIRST
for(i=10;i>1;i--){
    digitalWrite(i-1,HIGH);
    digitalWrite(i,HIGH);
     digitalWrite(i+1,HIGH);
     delay(150);
     digitalWrite(i-1,LOW);
    digitalWrite(i,LOW);
     digitalWrite(i+1,LOW);
     delay(10);
}
}
//end and return to loop
