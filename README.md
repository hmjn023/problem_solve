# ServoTest

問題解決技法で作成したサーボモータの制御プログラム

アナログスティックで情報読み取りをして、角度変化をつけている

```Mermaid
flowchart LR
A[Switch A] -- LOW --> B[LED ON]
A -- HIGH --> C[LED OFF]

D[Switch B] -- LOW --> E[Servo B 180 degree]
D -- HIGH --> F[Servo B 90 degree]

G[Joystick] -- x degree --> H[Servo A x degree]
```
