/*
Name:		Sketch2.ino
Created:	2/24/2018 5:01:20 PM
Author:	M.Mohsen
*/
#include <SoftwareSerial.h>

SoftwareSerial myserial(7, 8);


// the setup function runs once when you press reset or power the board

void setup() {
	myserial.begin(9600);
	pinMode(2, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	String t = myserial.readString();
	Serial.println(t);

	if (t != "") myserialEvent(t);
}


void myserialEvent(String t){
	
	if (t == "0"){
		digitalWrite(2, 0);
	}
	else if (t == "1"){
		digitalWrite(2, 1);
	}
}
