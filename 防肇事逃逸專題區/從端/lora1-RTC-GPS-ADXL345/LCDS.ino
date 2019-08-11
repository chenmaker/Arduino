void LCDS(){
  lcd.begin(20,4);         //LCD規格
  lcd.noBacklight();       //LCD關閉背光
      delay(250);
  lcd.backlight();         //LCD開啟背光
  lcd.setCursor(0,0);      //顯示開始位置
  lcd.print("ME:RBO-2266");//顯示我方車牌
  lcd.setCursor(0,1);      //第一排
  lcd.print("YOU:");       //顯示對方車牌  
  lcd.setCursor(0,2);      //第三排
  lcd.print("Time:");      //時間
  lcd.setCursor(0,3);      //第四排
  lcd.print("GPS:");       //座標       
  delay(100);
  }
