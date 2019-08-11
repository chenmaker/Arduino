#include <SparkFun_ADXL345.h>         // 匯入ADXL345 Library
ADXL345 adxl = ADXL345();             //使用I2C腳位
void ADXL_ISR();
void setup(){
  Serial.begin(9600);
  Serial.println("SparkFun ADXL345 Accelerometer Hook Up Guide Example");
  adxl.powerOn();                     // 打開ADXL345電源
  adxl.setRangeSetting(16);           // 設定撞擊力道，有2g、4g、8g、16g
  adxl.setSpiBit(0);                  // 設置為“0”時，將ADXL345配置為4線SPI模式，設置為1時，將ADXL345配置為3線SPI模式，默認為"1"   
  adxl.setActivityXYZ(1, 0, 0);       // 設置ADXL345為開啟哪個軸(adxl.setActivityXYZ（X，Y，Z);)中的運動檢測（1 == ON，0 == OFF）
  adxl.setActivityThreshold(250);     // 每增量62.5mg會有動作活動//不動作的門檻（0-255）
  adxl.setInactivityXYZ(1, 0, 0);     // 設置為檢測所有軸上的不活動“adxl.setInactivityXYZ（X，Y，Z）;” （1 == ON，0 == OFF）
  adxl.setInactivityThreshold(75);    // 每增量62.5mg會有動作活動//不動作的門檻（0-255）
  adxl.setTimeInactivity(2);          // 當沒有動作時多少秒無效
  adxl.setTapDetectionOnXYZ(0, 0, 1); // 打開並檢測哪個軸的活動“adxl.setTapDetectionOnX（X，Y，Z）;” （1 == ON，0 == OFF）
  //設置被認為是TAP的值以及什麼是DOUBLE TAP（0-255） 待查!!!!!
  adxl.setTapThreshold(50);           // 62.5 mg per increment
  adxl.setTapDuration(15);            // 625 μs per increment
  adxl.setDoubleTapLatency(80);       // 1.25 ms per increment
  adxl.setDoubleTapWindow(200);       // 1.25 ms per increment
  //打開每種模式的中斷（1 == ON，0 == OFF）
  adxl.InactivityINT(1);
  adxl.ActivityINT(1); 
}
void loop(){
  int x,y,z;   
  adxl.readAccel(&x, &y, &z);         // 讀取加速度計值存儲在x，y，z變數中
  ADXL_ISR();
}
void ADXL_ISR() {
  int x,y,z;
  byte interrupts = adxl.getInterruptSource();
  // Inactivity
  if(adxl.triggered(interrupts, ADXL345_INACTIVITY)){//當ADXL345不動作時要做什麼事情
    Serial.println("*** INACTIVITY ***");    
  }
   if(adxl.triggered(interrupts, ADXL345_ACTIVITY)){//當ADXL345動作時要做什麼事情
    Serial.println("*** ACTIVITY ***"); 
    adxl.readAccel(&x, &y, &z);   
    Serial.print(x);
    Serial.print(", ");
    Serial.print(y);
    Serial.print(", ");
    Serial.println(z); 
    }
  }
