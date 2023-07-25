#include <Servo.h>

Servo servoA;
Servo servoB;
Servo servoC;

const int joyStickPinA = A0;
const int joyStickPinB = A2;

const int switchPinA = 2;
const int switchPinB = 3;

const int servoPinA = 9;
const int servoPinB = 11;
const int servoPinC = 13;

int joyStickPositionA;
int joyStickPositionB;

void setup()
{
	pinMode(joyStickPinA, INPUT);
	pinMode(joyStickPinB, INPUT);

	pinMode(switchPinA, INPUT_PULLUP);
	pinMode(switchPinB, INPUT_PULLUP);

	servoA.attach(servoPinA);
	servoB.attach(servoPinB);
	servoC.attach(servoPinC);

	Serial.begin(9600);
}

void loop()
{
	joyStickPositionA = analogRead(joyStickPinA) / (1023 / 180);
	joyStickPositionB = analogRead(joyStickPinB) / (1023 / 180);

	// joyStickPositionA = analogRead(joyStickPinA);
	// joyStickPositionB = analogRead(joyStickPinB);

	servoA.write(joyStickPositionA);
	servoB.write(joyStickPositionB);

	bool switchStateA = digitalRead(switchPinA);
	bool switchStateB = digitalRead(switchPinB);

	// Serial.println(switchStateA);
	// Serial.println(switchStateB);

	// Serial.println(joyStickPositionA);
	// Serial.println(joyStickPositionB);

	if (switchStateA == 1 && switchStateB == 1)
	{
		servoC.write(90);
	}
	else if (switchStateA == 0 && switchStateB == 1)
	{
		servoC.write(0);
	}
	else if (switchStateA == 1 && switchStateB == 0)
	{
		servoC.write(180);
	}
	delay(100);
}
