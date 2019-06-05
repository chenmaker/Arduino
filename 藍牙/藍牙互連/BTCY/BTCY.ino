#include <SoftwareSerial.h>   // 引用程式庫
// 定義連接藍牙模組的序列埠
SoftwareSerial BT(8, 9); // Pin8->TX  Pin9->RX  
char val;  // 儲存接收資料的變數
const byte LED_PIN = 13;  // 定義LED腳位
void setup() {
  //藍牙透傳模式的預設連線速率。
  BT.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}
void loop() {
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  if (BT.available()) {
    val = BT.read();
    if (val == '1') {
      digitalWrite(LED_PIN, HIGH);
      // 回應命令發送端，告知「已開燈」
      BT.println("LED ON");
    } else if (val == '0') {
      digitalWrite(LED_PIN, LOW);
      // 回應命令發送端，告知「已關燈」
      BT.println("LED OFF");
    }
  }
}
