#include <Servo.h>

Servo servoA;
Servo servoB;
Servo servoC;

const int joyStickPinA = A1;
const int joyStickPinB = A2;

const int switchPinA = 2;
const int switchPinB = 3;

const int servoPinA = 11;
const int servoPinB = 12;
const int servoPinC= 13;

int joyStickPositionA;
int joyStickPositionB;


void setup() {
  pinMode(joyStickPinA, INPUT);
  pinMode(joyStickPinB, INPUT);

  pinMode(switchPinInA, INPUT_PULLUP);
  pinMode(switchPinInB, INPUT_PULLUP);

  servoA.attach(servoPinA);
  servoB.attach(servoPinB);
  servoC.attach(servoPinC);
}

void loop() {
	joyStickPositionA = analogRead(joyStickPinA) / (1023/180);
	joyStickPositionB = analogRead(joyStickPinB) / (1023/180);

	servoA.write(joyStickPositionA);
	servoB.write(joyStickPositionB);

	bool switchStateA=digitalRead(switchPinA);
	bool switchStateB=digitalRead(switchPinB);
	
	if(switchStateA==1 && switchStateB==1){
		servoC.write(90);
	}
	else if(switchStateA==0 && switchStateB==1){
		servoC.write(0);
	}
	else if(switchStateA==1 && switchStateB==0){
		servoC.write(180);
	}
	delay(100);
}
