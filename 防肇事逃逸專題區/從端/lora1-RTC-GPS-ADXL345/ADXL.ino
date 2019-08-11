void ADXL(){
   int x,y,z; 
   adxl.readAccel(&x, &y, &z); 
   byte interrupts = adxl.getInterruptSource();  
//判斷是否撞擊力大於10G
  if(adxl.triggered(interrupts, ADXL345_ACTIVITY)){
    Serial.println("*** ACTIVITY ***"); 
    adxl.readAccel(&x, &y, &z);   
    Serial.print(x);
    Serial.print(", ");
    Serial.print(y);
    Serial.print(", ");
    Serial.println(z); 
    delay(300); 
    UART.print(car);                   //透UART把car的資訊傳出去
  //UART.print(any);                   //透UART把any的資訊傳出去
    }
  }
