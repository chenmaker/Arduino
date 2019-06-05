void coding(){
   String ko;
   byte ry[]={1,1,0,0,0,1,0}; 
   byte cw[]={0,0,0,1,0,1,1};
   String df="B"+myText;
   //Serial.println(df); 
   // int we;
   // we=(df.toInt());//C0C1
   byte we=B1100000;//6543210
   byte yw=B0001011;//造碼多項式  6543210
   Serial.println(we,BIN);
    ko=String(we,BIN);
int gh[]={0,0,0,0};    
if(ry[0]==1){
    gh[0]=cw[3]^ry[0];
    gh[1]=cw[4]^ry[1]; 
    gh[2]=cw[5]^ry[2];
    gh[3]=cw[6]^ry[3];
    for(int fg=0;fg<=3;fg++){
    Serial.print(fg);
    Serial.print("=");
    Serial.println(gh[fg]);
    }
    if(gh[0]==1){
            }else if(gh[1]==1){
    gh[0]=cw[3]^gh[1];
    gh[1]=cw[4]^gh[2]; 
    gh[2]=cw[5]^gh[3];
    gh[3]=cw[6]^ry[4];
    for(int fg=0;fg<=3;fg++){
    Serial.print(fg);
    Serial.print("=");
    Serial.println(gh[fg]);
                  }
            if(gh[1]==1){
      gh[0]=cw[3]^gh[1];
      gh[1]=cw[4]^gh[2]; 
      gh[2]=cw[5]^gh[3];
      gh[3]=cw[6]^ry[5];
      for(int fg=0;fg<=3;fg++){
      Serial.print(fg);
      Serial.print("=");
      Serial.println(gh[fg]);
                }
            }
      if(gh[1]==1){
      gh[0]=cw[3]^gh[1];
      gh[1]=cw[4]^gh[2]; 
      gh[2]=cw[5]^gh[3];
      gh[3]=cw[6]^ry[6];
      for(int fg=0;fg<=3;fg++){
      Serial.print(fg);
      Serial.print("=");
      Serial.println(gh[fg]);
                }
            }
      }
  }
      
      Serial.println(); 
   int iu=ko.length();
   int lh=2;//控制補幾個零
   lh=lh-iu;
for(int i=0;i<=lh; i++){
  if(i>=0){ 
      if(ko.length()==3){
        Serial.print("ko=");  
        Serial.println(ko);       
       }else if(ko.length()!=3)
                 {
           ko="0"+ko;      
                 }        
          }
      }
    ko=myText+ko;
    Serial.print("ko1="); 
    Serial.println(ko);
    
  }
