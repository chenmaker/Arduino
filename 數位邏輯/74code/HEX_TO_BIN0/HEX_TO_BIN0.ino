int x;
void setup(){
Serial.begin(9600);
}
void loop(){
if(Serial.available()){
x= Serial.read();
Serial.write(x);
int gh[]={0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xa,0xb,0xc,0xd,0xe,0xf};
for(int u=0;u<16;u++){
String myText=String(gh[u],BIN);
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
        Serial.println(myText);       
       }else if(myText.length()!=4)
                 {
           myText="0"+myText;      
                  }        
          }
        
      }
    }
  }
}
