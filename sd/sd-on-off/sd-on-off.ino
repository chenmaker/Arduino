//cs-->pin4
//sck-->pin13
//mosi-->pin11
//miso-->pin12
#include <SPI.h>
#include <SD.h>
File myFile;
int a;
int d;
int x;
int y;
void setup() {
Serial.begin(9600);
 while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
   Serial.print("Initializing SD card...");
   if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  } 
if (SD.exists("1.txt")) {
    Serial.println("1.txt exists.");
  } else {
  Serial.println("1.txt doesn't exist.");
  Serial.println("NEW 1.txt...");
  myFile = SD.open("1.txt", FILE_WRITE);
  myFile.close();
  Serial.println("1.txt exists.");  
  } 
}
void w(){
  myFile = SD.open("1.txt");
  if (myFile) {
    Serial.println("1.txt:");
    while (myFile.available()) {
      y = myFile.parseInt();
       Serial.print("y1=");
       Serial.println(y);
       delay(100); 
    if(x>=0&&x<=40){
      for(x=y;x<42;x++){ 
       Serial.print("x=");
       Serial.println(x); 
       delay(100);       
File myFile = SD.open("1.txt",FILE_WRITE);
             if (myFile){
               myFile.println(String(x));
               myFile.close();
                 }else{
             Serial.println("error opening1 1.txt");
                 }
              }
        }else if(y>=41){
         Serial.println("Removing 1.txt...");
         SD.remove("1.txt");
          File myFile = SD.open("1.txt",FILE_WRITE);
             if (myFile){
              d=0;
              x=0;
               myFile.println(String(d));
               myFile.close(); 
                } 
         Serial.println("ok");
               }
        }   
      for(a;a<42;a++){
         Serial.print("a=");
         Serial.println(a);
           delay(200);
        File myFile = SD.open("1.txt",FILE_WRITE);
             if (myFile){
               myFile.println(String(a));
               myFile.close(); 
                } else {
             Serial.println("error opening2 1.txt");
                      }}}else {
    Serial.println("error opening3 1.txt");
   }
}  
void loop(){
  w();
}
