void pm(){
    if(mySerial.available()){
    delay(100);
    unsigned char i=0;
    while(mySerial.available()){
      gucRxBuf[i] = mySerial.read();
      i++;
    }
    if (((gucRxBuf[0]==0x42)&&(gucRxBuf[1]==0x4d))&&(i>=12)){
      int chksum=0;
      unsigned char DTL=(gucRxBuf[2]<<8)+gucRxBuf[3];
      for(unsigned char i=0;i<(DTL+2);i++){chksum += gucRxBuf[i];}
      unsigned char csH = (chksum>>8);
      unsigned char csL = (chksum&0xFF);
      if((csH==gucRxBuf[DTL+2])&&(csL==gucRxBuf[DTL+3])){
        pmcount25=gucRxBuf[22]*256+gucRxBuf[23];
        temp=(float)(gucRxBuf[24]*256+gucRxBuf[25])/10;  
        humi=(float)(gucRxBuf[26]*256+gucRxBuf[27])/10; 
      }
      else{
        mySerial.flush();
      }
    }
    else{
      mySerial.flush();
      }
    }
  }
