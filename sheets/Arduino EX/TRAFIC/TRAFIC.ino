
int green=10;
int yellow=11;
int red=12;



void setup() {
 pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
   pinMode(red,OUTPUT);

}

void loop() {
  digitalWrite (green,HIGH);
  digitalWrite (yellow,LOW);
  digitalWrite (red,LOW);
  delay (3000);
  digitalWrite (green,LOW);
  digitalWrite (yellow,HIGH);
  digitalWrite (red,LOW);
  delay (3000);
  digitalWrite (green,LOW);
  digitalWrite (yellow,LOW);
  digitalWrite (red,HIGH);
  delay (3000);

}
