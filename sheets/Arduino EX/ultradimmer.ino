/*
Name:		Sketch2.ino
Created:	2/24/2018 5:01:20 PM
Author:	M.Mohsen
*/
const int trig = 7, echo = 8;
// the setup function runs once when you press reset or power the board
long duration;
float bright;

void setup() {
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {

//set trig to low
	digitalWrite(trig, LOW);
	delayMicroseconds(2);

//give the pulse

	digitalWrite(trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig, LOW);

// process and output
	duration = pulseIn(echo, HIGH);
	bright = 255 - duration * .16;
	analogWrite(3,bright > 0 ? bright : 0);

}



