void lorauart(){
  if(UART.available() > 0){              //當UART有接受到大於0的資料時
    String input = UART.readString();  //設定String input為接受到的東西
    Serial.println(input);             //列印出input的東西
    input.toCharArray(copy,30);        //分解input字串變成一個字元單獨放到copy的陣列裡面
    if(input.length()>8){              //當input總長度大於7的時候
       for(int x=0;x<=7;x++){              //從第0個位置開始
      in=in +copy[x];                  //把相對應的字元放到in
      Serial.println(copy[x]);         
               } 
    Serial.println(in);                //列印出in的東西
    lcd.setCursor(4,1);
    lcd.print(in);                    //在LCD上面顯示
    lcd.setCursor(12,1);              //清空後面的亂碼
    lcd.print("        "); 
    digitalWrite(led,255);           //讓LED燈亮
    }
   }
  }
