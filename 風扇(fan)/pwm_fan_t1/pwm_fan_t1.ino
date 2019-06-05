const int fan = 6; //設定 Arduino 風扇腳位在 9 pin
int in ; 
void setup() {
 // 初始化傳輸速率設定為9600
 Serial.begin(9600);
 pinMode(fan, OUTPUT); //定義 pinmode 為 pin 9 OUTPUT 輸出
 pinMode(in , INPUT); 
}
void loop() {
 // 讀取輸入 on analog pin 0:
 in=analogRead(A0);//設定A0 值為讀取類比訊號
  analogWrite(fan,in);//我們設定 9 pin 為 pwm 風扇速度輸出
 Serial.println(in); //利用 Serial.println函數可以在序列監控視窗中輸出風扇速度的值
 delay(100); // 我希望每秒鐘可以延遲印出值int fan = 9; //設定 Arduino 風扇腳位在 9 pin
}
