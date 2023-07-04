#include <Servo.h>

// Arduino入門編⑦ ジョイスティックからの入力値を読み取る
// https://burariweb.info
Servo servoA;
Servo servoB;

const int xPin = A0; // X軸方向の入力をアナログピンA0に
const int switchPinInA = 2;  // センタースイッチの入力をデジタルピンD2に
const int switchPinInB = 3;  // センタースイッチの入力をデジタルピンD2に
const int LEDPin = 13;  // センタースイッチの入力をデジタルピンD2に

int xPosition; // X軸方向の読み取り値の変数を整数型に

void setup() {
  pinMode(xPin, INPUT); // A0ピンを入力に(省略可)
  pinMode(switchPinInA, INPUT_PULLUP);
  pinMode(switchPinInB, INPUT_PULLUP);

  pinMode(LEDPin, OUTPUT);

  servoA.attach(10);
  servoB.attach(9);
}

void loop() {
  xPosition = analogRead(xPin) / (1023/180);
  servoA.write(xPosition);
  
  bool swStateA=digitalRead(switchPinInA);
  bool swStateB=digitalRead(switchPinInB);
  if(swStateA==0){
    digitalWrite(LEDPin,HIGH);
    //servoB.write(0);
  }
  else{
    digitalWrite(LEDPin,LOW);
    //servoB.write(90);
  }
  
  if(swStateB==0){
    //digitalWrite(LEDPin,HIGH);
    servoB.write(180);
  } 
  else{
    //digitalWrite(LEDPin,LOW);
    servoB.write(90);
  }
  
  delay(100);
}