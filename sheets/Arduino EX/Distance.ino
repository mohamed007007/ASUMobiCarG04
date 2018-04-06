/*
Name:		Sketch2.ino
Created:	2/24/2018 5:01:20 PM
Author:	M.Mohsen
*/
const int trig = 7;
const int echo = 8;
long duration;

float distance[10];
int i = 0;

float average(float distance[10]){
	float sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += distance[i];
	}
	return sum / 10.0;
}
// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	digitalWrite(trig, LOW);
	delayMicroseconds(2);

	digitalWrite(trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig, LOW);

	duration = pulseIn(echo, HIGH);

	distance[i] = duration * (0.034 / 2);
	i++;

	Serial.println(average(distance));

	i = (i == 10) ? 0 : i;
}





