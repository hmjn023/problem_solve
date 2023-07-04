#include <Servo.h>

// Arduino入門編⑦ ジョイスティックからの入力値を読み取る
// https://burariweb.info
Servo servo;

const int xPin = A0; // X軸方向の入力をアナログピンA0に
// const int yPin = A1;  // Y軸方向の入力をアナログピンA1に
// const int switchPin = 2;  // センタースイッチの入力をデジタルピンD2に

int xPosition; // X軸方向の読み取り値の変数を整数型に
// int yPosition ;   // Y軸方向の読み取り値の変数を整数型に
// int switchPosition ;  // センタースイッチの読み取り値の変数を整数型に

void setup() {
  pinMode(xPin, INPUT); // A0ピンを入力に(省略可)
  // pinMode(YPin, INPUT);          // A1ピンを入力に(省略可)
  // pinMode(switchPosition, INPUT_PULLUP);  // D2ピンをプルアップして入力に
  // pinMode(5,INPUT_PULLUP);
  pinMode(13, OUTPUT);

  servo.attach(11);
  // シリアル通信の開始
  Serial.begin(9600);
}

void loop() {
  xPosition = analogRead(xPin) / 5.7; // X軸方向のアナログ値を読み取る
  // yPosition = analogRead(Y_PIN);     // Y軸方向のアナログ値を読み取る
  // swPosition = digitalRead(SW_PIN);  // センタースイッチの状態を読み取る
  servo.write(xPosition);
  /*
  Serial.print("X: ");           // シリアルモニタにそれぞれの値を出力
  Serial.println(xPosition);
  Serial.print("  Y: ");
  Serial.print(yPosition);
  Serial.print("  SW: ");
  Serial.println(switchPosition);
  */

  delay(100);
}
