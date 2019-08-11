 void lora(){
 if(lorauart.available() > 0){               //當lorauart有接受到大於0的資料時
          c=lorauart.readString();           //設定String c為接受到的東西
          Serial.println(c);                 //列印出c的東西
          Serial.println(c.length());        //列印出c的長度
          c.toCharArray(copy, 60);           //分解c字串變成一個字元單獨放到copy的陣列裡面
      if(c.length()>30){                     //當c總長度大於7的時候
          for(x=0;x<=25;x++){
              a= a+copy[x];                  //字串a從第0個位置開始相加字元
              b= b+copy[x+26];               //字串b從第26個位置開始相加字元
                            }    
              Serial.println(a);             //列印出a的東西
              Serial.println(b);             //列印出b的東西
              if(a==b){                      //當a字串和b字串相同時
                  Serial.println("車牌重複"); //列印出車牌重複
                  c="";                      //清空abc字串裡面的東西
                  a="";
                  b="";
              }else{                         //否則就把資料上傳然後在清空abc字串裡面的東西
                  WiFi_Connect();
                  delay(3000);  
                  c="";
                  a="";
                  b="";    }
               
     }else{
         Serial.println("車牌錯誤");
         }   
    } 

 }
