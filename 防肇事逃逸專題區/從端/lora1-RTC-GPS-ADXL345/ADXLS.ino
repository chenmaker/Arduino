void ADXLS(){
  adxl.powerOn(); 
  adxl.setRangeSetting(4); 
  adxl.setSpiBit(0);                  
  adxl.setActivityXYZ(1, 0, 0);       
  adxl.setActivityThreshold(250);      
  adxl.setInactivityXYZ(1, 0, 0);     
  adxl.setInactivityThreshold(75);    
  adxl.setTimeInactivity(2);         
  adxl.setTapDetectionOnXYZ(0, 0, 1); 
  adxl.setTapThreshold(50);           
  adxl.setTapDuration(15);          
  adxl.setDoubleTapLatency(80);       
  adxl.setDoubleTapWindow(200);       
  adxl.InactivityINT(1);
  adxl.ActivityINT(1); 
  }
