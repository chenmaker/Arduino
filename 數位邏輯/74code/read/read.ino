char copy[2];
String c,myText;
int x,r=0;
int gh[]={0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xa,0xb,0xc,0xd,0xe,0xf};
void setup(){
Serial.begin(9600);
}
void loop(){
if(Serial.available()){
x= Serial.read();
Serial.write(x);
Serial.print("=");
Serial.println(x,HEX);
c=String(x,HEX);
c.toCharArray(copy,2);//將文字分解成字元存在陣列裡
for(int y=0;y<=1;y++){//跑C0,C1
  if(r>>1){ r=0;}
  String k="C"+String(r)+"=";
  Serial.print(k);
  Serial.println(c[r]);
  tt();
//Serial.println(myText); 
  tBIN();
  coding();
      r++;   
    }
  }
}
