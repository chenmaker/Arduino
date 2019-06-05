void tBIN(){
int iu=myText.length();
int lh=4;//控制補幾個零
lh=lh-iu;
//Serial.println(iu);
//Serial.println(lh);
for(int i=0;i<=lh; i++){
  //Serial.print("i=");
  //Serial.println(i);
  if(i>=0){ 
      if(myText.length()==4){
        String m="C"+String(r)+"二進位==>";
        Serial.print(m); 
        Serial.println(myText);       
       }else if(myText.length()!=4)
                 {
           myText="0"+myText;      
                 }        
          }
      }
   /*myText=myText+"000";
   Serial.print("移高三位==>"); 
   Serial.println(myText);   */
  }
