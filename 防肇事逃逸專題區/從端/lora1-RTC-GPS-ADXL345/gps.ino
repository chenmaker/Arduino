void gps(){
  gpsRead();       //獲取GPS数据
  parseGpsBuffer();//解析GPS数据
  printGpsBuffer();//输出解析后的数据
  lcd.setCursor(4,3);
  lcd.print("N:"); 
  lcd.setCursor(6,3);
//南北緯  請參考 公式.txt
for(int i=0;i<5;i++){
  if(i>1 && i == 2){
    lcd.print('.');
    }else if(i>1){
    lcd.print(Save_Data.latitude[i-1]);
    }else{
      lcd.print(Save_Data.latitude[i]);
         }
  }
//東西經   
  lcd.print(" E:");
for(int i=0;i<6;i++){
  if(i>2 && i == 3){
    lcd.print('.');
    }else if(i>2){
    lcd.print(Save_Data.longitude[i-1]);
    }else{
      lcd.print(Save_Data.longitude[i]);
         }
      } 
  }
