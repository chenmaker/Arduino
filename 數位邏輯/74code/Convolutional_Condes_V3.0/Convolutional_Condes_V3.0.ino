 //====== Arduino - (2,1;2 - Convolutional Codes) V2.0 ======
#include <SoftwareSerial.h> 
uint8_t input_data;
const int Array = 9;
int Error_Quantity[8][10];
bool Switch2 = true;

//===========(狀態圖)============
const int S1[2] = {0x00 , 0x00};
const int S2[2] = {0x00 , 0x02};
const int S3[2] = {0x00 , 0x03};
const int S4[2] = {0x00 , 0x01}; 
const int S1_1[2] = {0x01 , 0x03};
const int S2_1[2] = {0x01 , 0x01};
const int S3_1[2] = {0x01 , 0x00};
const int S4_1[2] = {0x01 , 0x02};
//===============================

 void setup() {
  SoftwareSerial UART (A0,A1);
  Serial.begin(115200);
  UART.begin(115200);
  Serial.println("Welcome to Convolutional Codes");
}

void Initial_Display(){
 if(Switch2){
  Serial.println("******************************************");
  Serial.print("請輸入:(演算字元) = "); Switch2 = false;
 } 
}

void loop() { 
int Serial_Read,char_Read;
int ArrayNoise; 
int Subtraction;
int Numbererror;
int ReadData_int;
char ReadData_char;
bool Switch = true; int l=0;

Initial_Display();

// =============={ 2,1;2 : 訊息輸入 }==============// 

 if(Serial_Read = (Serial.available()) != 0){
    input_data = Serial.read();
    ReadData_int = input_data;
    ReadData_char = input_data;
    Serial.println(ReadData_char);
    Serial.println("******************************************");
    Serial.print("請輸入:(雜訊陣列[]位置) = ");    
    
  while(Switch){
   if(Serial_Read = (Serial.available()) != 0){
     l++;
       if(l==1){
        input_data = Serial.read();
        input_data = (input_data-48);
        ArrayNoise = input_data;
        Serial.println(ArrayNoise);
        Serial.println("******************************************");
        Serial.print("請輸入:(雜訊 Bit) = ");        
       } 
       if(l==2){
        input_data = Serial.read();
        Subtraction = input_data;
        Numbererror = (Subtraction-48);
        Serial.println(Numbererror);
        Switch2 = true; break;
       }        
   }        
  }

int Accumulate,Serial_Read ;
int L=9,r=0,i,n,j,S;  
int un_1=0,un_2=0,v[10];
int s1,s1_1,s2,s2_1,s3,s3_1,s4,s4_1;
int Error_s1,Error_s1_1,Error_s2,Error_s2_1,
    Error_s3,Error_s3_1,Error_s4,Error_s4_1;
int M_Error ,M1_Error ,M2_Error , SS0,SS1,SS2,SS3; 
int u_1=0,u_2=0,out_Data=0,path=0,path_1=0,path_2=0;
char char_Read,Decoded_character; 

  
// =============={ 2,1;2 : 編碼 }==============// 
 
    u_1 =ReadData_int;
    u_2 =ReadData_int;
    
    Serial.println("******************************************");
    Serial.print("設定訊息 = ");
    Serial.println(ReadData_char);  
       
    un_1 = u_1*0x01 ^ u_1*0x01<<1 ^ u_1*0x01<<2;
    un_2 = u_2*0x01 ^ u_2*0x00<<1 ^ u_2*0x01<<2; 
    Serial.print("多工器[u_1]輸出 = ");
    Serial.println(un_1,BIN);
    Serial.print("多工器[u_2]輸出 = ");
    Serial.println(un_2,BIN);
    
    Serial.print("編碼訊息:[v] = ");
    for( i=0 ; i<10 ; i++){
       v[i] = ((un_1 & (1 << i)) >> i)<<1 | ((un_2 & (1 << i)) >> i);
       out_Data =(v[i]^(out_Data<<2));
       Serial.print(v[i],BIN);//陣列必須由右至左看 !
       Serial.print(",");
    } 
    Serial.println(";");   
// =============={ 2,1;2 : 雜訊 }==============//
    //ArrayNoise = (rand() % 10);
    v[ArrayNoise] = Numbererror; 
    Serial.print("亂數產生:ArrayNoise = "); 
    Serial.println(ArrayNoise); 
    Serial.print("雜訊攻擊:[v] = ");
    for( i=0 ; i<10 ; i++){
       Serial.print(v[i],BIN);
       Serial.print(".");
    }
    Serial.println("");         
// =============={ 2,1;2 : 解碼 - 錯誤陣列}==============//   
    for( n=0 ; n<10 ; n++){     
     if( n == 0 ){
      s1 = (((S1[1] ^ v[Array-n] ^ 0x02) & 0x01) + (S1[1]>>1 ^ v[Array-n]>>1)); 
      s1_1 = (((S1_1[1] ^ v[Array-n] ^ 0x02) & 0x01) + (S1_1[1]>>1 ^ v[Array-n]>>1));
      Error_s1 = s1 , Error_s1_1 = s1_1;  
      Error_Quantity[0][0] = s1 , Error_Quantity[1][0] = s1_1;
      Error_Quantity[2][0] = 5 , Error_Quantity[3][0] = 5; 
      Error_Quantity[4][0] = 0x01 , Error_Quantity[5][0] = 0x01;
      Error_Quantity[6][0] = 5 , Error_Quantity[7][0] = 5 ;             
     }    
       if( n == 1 ){
        s1 = (((S1[1] ^ v[Array-n] ^ 0x02) & 0x01) + (S1[1]>>1 ^ v[Array-n]>>1)); 
        s1_1 = (((S1_1[1] ^ v[Array-n] ^ 0x02) & 0x01) + (S1_1[1]>>1 ^ v[Array-n]>>1)); 
        s2 = (((S2[1] ^ v[Array-n] ^ 0x02) & 0x01) + (S2[1]>>1 ^ v[Array-n]>>1)); 
        s2_1 = (((S2_1[1] ^ v[Array-n] ^ 0x02) & 0x01) + (S2_1[1]>>1 ^ v[Array-n]>>1));
        s1 =s1+Error_s1,s1_1=s1_1+Error_s1 , s2=s2+Error_s1_1,s2_1=s2_1+Error_s1_1; 
        Error_s1=s1,Error_s1_1=s1_1 , Error_s2=s2,Error_s2_1=s2_1;
        Error_Quantity[0][1] = s1 ,Error_Quantity[1][1] = s1_1 ,Error_Quantity[2][1] = s2 ,Error_Quantity[3][1] = s2_1 ; 
        Error_Quantity[4][1] = 0x01 ,Error_Quantity[5][1] = 0x01 ,Error_Quantity[6][1] = 0x01 ,Error_Quantity[7][1] = 0x01 ;                             
       }  
         if( n >= 2 ){
          s1 = (((S1[1] ^ v[Array-n] ^ 0x02) & 0x01) + (S1[1]>>1 ^ v[Array-n]>>1)); 
          s1_1 = (((S1_1[1] ^ v[Array-n] ^ 0x02) & 0x01) + (S1_1[1]>>1 ^ v[Array-n]>>1)); 
          s2 = (((S2[1] ^ v[Array-n] ^ 0x02) & 0x01) + (S2[1]>>1 ^ v[Array-n]>>1)); 
          s2_1 = (((S2_1[1] ^ v[Array-n] ^ 0x02) & 0x01) + (S2_1[1]>>1 ^ v[Array-n]>>1));       
          s3 = (((S3[1] ^ v[Array-n] ^ 0x02) & 0x01) + (S3[1]>>1 ^ v[Array-n]>>1)); 
          s3_1 = (((S3_1[1] ^ v[Array-n] ^ 0x02) & 0x01) + (S3_1[1]>>1 ^ v[Array-n]>>1)); 
          s4 = (((S4[1] ^ v[Array-n] ^ 0x02) & 0x01) + (S4[1]>>1 ^ v[Array-n]>>1)); 
          s4_1 = (((S4_1[1] ^ v[Array-n] ^ 0x02) & 0x01) + (S4_1[1]>>1 ^ v[Array-n]>>1));                                              
          s1 =s1+Error_s1,s1_1=s1_1+Error_s1 , s2=s2+Error_s1_1,s2_1=s2_1+Error_s1_1,
          s3 =s3+Error_s2,s3_1=s3_1+Error_s2 , s4=s4+Error_s2_1,s4_1=s4_1+Error_s2_1;                    
          if(s1<s3) Error_s1=s1,Error_Quantity[4][n] = 0x01; else if(s1>s3) Error_s1=s3,Error_Quantity[4][n] = 0x00;
          if(s1_1<s3_1) Error_s1_1=s1_1,Error_Quantity[5][n] = 0x01; else if(s1_1>s3_1) Error_s1_1=s3_1,Error_Quantity[5][n] = 0x00; 
          if(s2<s4) Error_s2=s2,Error_Quantity[6][n] = 0x01; else if(s2>s4) Error_s2=s4,Error_Quantity[6][n] = 0x00;
          if(s2_1<s4_1) Error_s2_1=s2_1,Error_Quantity[7][n] = 0x01; else if(s2_1>s4_1) Error_s2_1=s4_1,Error_Quantity[7][n] = 0x00;          
          if(s1==s3) Error_s1=s1,Error_Quantity[4][n] = 0x02; if(s1_1==s3_1) Error_s1_1=s1_1,Error_Quantity[5][n] = 0x02;
          if(s2==s4) Error_s2=s2,Error_Quantity[6][n] = 0x02; if(s2_1==s4_1) Error_s2_1=s2_1,Error_Quantity[7][n] = 0x02;            
          Error_Quantity[0][n] = Error_s1 ,Error_Quantity[1][n] = Error_s1_1 ,Error_Quantity[2][n] = Error_s2 ,Error_Quantity[3][n] = Error_s2_1;    
          Error_Quantity[1][8] = 5,Error_Quantity[3][8] = 5,Error_Quantity[1][9] = 5,Error_Quantity[2][9] = 5,Error_Quantity[3][9] = 5; 
          Error_Quantity[5][8] = 5,Error_Quantity[7][8] = 5,Error_Quantity[5][9] = 5,Error_Quantity[6][9] = 5,Error_Quantity[7][9] = 5;                                                    
         }  
           if( n == 9 ){
              Serial.println("錯誤陣列 = -------------------------------");
                  for( i = 0; i < 8; i++) {
                    for( j = 0; j < 10; j++) {
                          Serial.print(Error_Quantity[i][j]);
                          Serial.print(" . ");
                    }
                     Serial.println("");
                    if(i==3)Serial.println("路徑陣列 = -------------------------------");
                  }
              Serial.println("------------------------------------------");  
           }                               
    }

// =============={ 2,1;2 : 解碼 - 最佳路徑解}==============//
    if(Error_Quantity[0][9] < Error_Quantity[1][9]) M1_Error=Error_Quantity[0][9],path_1=Error_Quantity[4][9];
    else M1_Error=Error_Quantity[1][9],path_1=Error_Quantity[5][9];
    if(Error_Quantity[2][9] < Error_Quantity[3][9]) M2_Error=Error_Quantity[2][9],path_2=Error_Quantity[6][9];
    else M2_Error=Error_Quantity[3][9],path_2=Error_Quantity[7][9];
    
    SS0=Error_Quantity[0][9] , SS1=Error_Quantity[1][9] , SS2=Error_Quantity[2][9] , SS3=Error_Quantity[3][9];
    if(M1_Error < M2_Error) M_Error = M1_Error; else M_Error = M2_Error; 
    if(path_1 < path_2) path = path_1; else path = path_2;     
    Serial.println("******************************************");    
    Serial.print("矩陣最小錯誤量 = ") ,  Serial.println(M_Error);
    Serial.print("紀錄路徑陣列數 = ") ,  Serial.println(path);      
 
    if(M_Error == SS0) M_Error = 0; if(M_Error == SS1) M_Error = 1;
    if(M_Error == SS2) M_Error = 2; if(M_Error == SS3) M_Error = 3;  

        Serial.print("最佳路徑 = ");
        for( S = 0 ; S < 10 ; S++){
            if(M_Error == 0){                                    
              if (Error_Quantity[4][L]==1) r = r+(Accumulate ^ (0x00<<S)), M_Error =0;
              if (Error_Quantity[4][L]==0) r = r+(Accumulate ^ (0x00<<S)), M_Error =2;
              Serial.print(Error_Quantity[0][L]);goto Rest;
            } 
            if(M_Error == 1){
              if (Error_Quantity[5][L]==1) r = r+(Accumulate ^ (0x01<<S)), M_Error =0;
              if (Error_Quantity[5][L]==0) r = r+(Accumulate ^ (0x01<<S)), M_Error =2;
              Serial.print(Error_Quantity[1][L]);goto Rest;
            }
            if(M_Error == 2){
              if (Error_Quantity[6][L]==1) r = r+(Accumulate ^ (0x00<<S)), M_Error =1;
              if (Error_Quantity[6][L]==0) r = r+(Accumulate ^ (0x00<<S)), M_Error =3;
              Serial.print(Error_Quantity[2][L]);goto Rest;
            }
            if(M_Error == 3){
              if (Error_Quantity[7][L]==1) r = r+(Accumulate ^ (0x01<<S)), M_Error =1;
              if (Error_Quantity[7][L]==0) r = r+(Accumulate ^ (0x01<<S)), M_Error =3;
              Serial.print(Error_Quantity[3][L]);goto Rest;
            }
          Rest:                          
         L--;
        //if (L == 0) L = 1;  
        Serial.print(".");
        }
    Serial.println("");    
// =============={ 2,1;2 : 解碼 - 訊息合併}==============//
    r = r >> 2;
    Serial.print("解碼訊息 DEC = ");
    Serial.println(r);    
    Serial.print("解碼訊息 BIN = ");
    Serial.println(r,BIN);
    Decoded_character = r;
    Serial.print("解碼訊息 char = ");      
    Serial.println(Decoded_character);
    Serial.println("******************************************");              
 }
}
