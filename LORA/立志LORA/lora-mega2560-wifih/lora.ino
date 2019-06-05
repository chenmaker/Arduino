 /*void lora(){
 if(Serial3.available() > 0){  
          c=Serial3.readString();
          Serial.println(c);
          Serial.println(c.length());
          c.toCharArray(copy, 60);
      if(c.length()>7){ 
          for(x=0;x<=25;x++){
              a= a+copy[x];
              b= b+copy[x+26];
                            }    
              Serial.println(a);
              Serial.println(b);
              if(a==b){
                  Serial.println("車牌重複");
                  c="";
                  a="";
                  b="";
              }else{
                  WiFi_Connect();
                  delay(3000);  
                  c="";
                  a="";
                  b="";    }
               
     }else{
         Serial.println("車牌錯誤");
         }   
    } 

 }*/
