int ledPin = 11; // 第13隻接腳請連接到 LED，以便控制 LED 明滅。
int ledPin1 = 12;
// setup() 函數只會於電源啟動時執行1次
void setup() 
{
  // 設定第 13 支腳為輸出模式
  pinMode(ledPin, OUTPUT);
   pinMode(ledPin1, OUTPUT); 
}

// loop() 函數會不斷的被重複執行
void loop()
{
  digitalWrite(ledPin, HIGH); // 設定PIN13腳位為高電位= 0V ，LED 處於發亮狀態!!
    digitalWrite(ledPin1, HIGH); // 設定PIN13腳位為高電位= 0V ，LED 處於發亮狀態!!
  delay(1000); 
   digitalWrite(ledPin, LOW); // 設定PIN13腳位為高電位= 0V ，LED 處於發亮狀態!!
   digitalWrite(ledPin1, LOW); // 設定PIN13腳位為高電位= 0V ，LED 處於發亮狀態!!
  delay(1000); 
}
