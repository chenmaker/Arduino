/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* 项目名称: 陀螺仪平台水平模拟大车驾驶系统
* 功能描述: 1、采集9轴加速计的数据
*          2、分析数据
*          3、根据数据控制4个舵机带动水平台来模拟大车驾驶效果
* 版本信息: Version 2.0
* 创建日期: 2019年5月25日
* 修改说明: 加入9轴加速计的倾斜角参数做控制修正（主要修正倾斜角对三轴加速度的影响）
* 创建作者:
* 
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*--------------Header File Inclusion and Object Creation.-------------*/
#include <Servo.h>
#include <Wire.h>
#include <JY901.h>
Servo MyServo1;  // create servo object to control a servo
Servo MyServo2;
Servo MyServo3;
Servo MyServo4;


/*--------------MCU Pins Definnition.-------------*/
/*
Test on Uno R3.
JY901    UnoR3
SDA <---> SDA
SCL <---> SCL
*/

/*--------------Definition and initialization of variables.-------------*/
float Acc_ax = 0;
float Acc_ay = 0;
float Acc_az = 0;
float Angle_x = 0;
float Angle_y = 0;
float Angle_z = 0;
int angle1 = 0;
int angle2 = 0;
int angle3 = 0;
int angle4 = 0;

int Ftime = 10;           
int Height = 30;         
float Acc_max = 0.6;      

void setup() 
{
  Serial.begin(9600);
  JY901.StartIIC();
  MyServo1.attach(9);  // attaches the servo on pin 9 to the servo object
  MyServo2.attach(10);
  MyServo3.attach(11);
  MyServo4.attach(12);
  Initialize();
} 

void loop() 
{
  
  JY901.GetAcc();
  Acc_ax = (float)JY901.stcAcc.a[0]/32768*16;
  Acc_ay = (float)JY901.stcAcc.a[1]/32768*16;
  Acc_az = (float)JY901.stcAcc.a[2]/32768*16 - 1.04;  //-1.04调零修正
  JY901.GetAngle();
  Angle_y = (float)JY901.stcAngle.Angle[0]/32768*180;
  Angle_x = (float)JY901.stcAngle.Angle[1]/32768*180;
  Angle_z = (float)JY901.stcAngle.Angle[2]/32768*180;

  Acc_ax = Acc_ax + Angle_x/60.0;
  Acc_ay = Acc_ay - Angle_y/60.0;
  //Serial.print(Angle_x);
  //Serial.print(',');
  //Serial.println(Acc_ax);
  //Serial.print(Angle_y);
  //Serial.print(',');
  //Serial.println(Acc_ay);
  //Serial.println(Acc_az);
  
  if(Acc_ax > 0.16)  Forward(Acc_ax);
  if(Acc_ax < -0.16)  Backwards(Acc_ax);
  if(Acc_ay < -0.16)  Left(Acc_ay);
  if(Acc_ay > 0.16)  Right(Acc_ay);
  if(Acc_az > 0.16)  Downward(Acc_az);
  /*
  //if((abs(Acc_ax) > 0.5) || (abs(Acc_ay) > 0.5) || (abs(Acc_az) > 0.5))
  {
  Serial.print(Acc_ax);
  Serial.print(',');
  Serial.print(Acc_ay);
  Serial.print(',');
  Serial.println(Acc_az);
    }
  */
  //delay(2000);
}


/*************************系统和设备初始化函数
*函数名称：Initialize
*功能说明：对系统和外围设备进行初始化
*输入参数：无
*输出参数：无
********************************************/
void Initialize(void)
{
  /*
  //平台压到最低程度（高度为舵机的厚度）
  MyServo1.write(15);
  MyServo2.write(110);
  MyServo3.write(15);
  MyServo4.write(100);  
  */
  //平台上升到最高程度
  MyServo1.write(65);
  MyServo2.write(50);
  MyServo3.write(65);
  MyServo4.write(50);  
  }

void Forward(float axValue)
{
  if(axValue > Acc_max + 1)  axValue = Acc_max + 1;
  int Hx = abs((Height*axValue)/Acc_max);
  angle1 = 15 + Height - Hx;
  angle2 = 110 - Height + Hx;
  MyServo1.write(angle1);
  MyServo2.write(angle2);
  delay(100);
  for(int i = 0;i < Hx;i++){
    angle1++;
    angle2--;
    MyServo1.write(angle1);
    MyServo2.write(angle2);
    delay(Ftime);
    }
  }

void Backwards(float axValue)
{
  if(axValue > Acc_max)  axValue = Acc_max;
  int Hx = abs((Height*axValue)/Acc_max);
  angle3 = 15 + Height - Hx;
  angle4 = 95 - Height + Hx;
  MyServo3.write(angle3);
  MyServo4.write(angle4);
  delay(100);
  for(int i = 0;i < Hx;i++){
    angle3++;
    angle4--;
    MyServo3.write(angle3);
    MyServo4.write(angle4);
    delay(Ftime);
    }
  }

void Left(float ayValue)
{
  if(ayValue > Acc_max)  ayValue = Acc_max;
  int Hy = abs((Height*ayValue)/Acc_max);
  angle1 = 15 + Height - Hy;
  angle4 = 110 - Height + Hy;
  MyServo1.write(angle1);
  MyServo4.write(angle4);
  delay(100);
  for(int i = 0;i < Hy;i++){
    angle1++;
    angle4--;
    MyServo1.write(angle1);
    MyServo4.write(angle4);
    delay(Ftime);
    }
  }

void Right(float ayValue)
{
  if(ayValue > Acc_max)  ayValue = Acc_max;
  int Hy = abs((Height*ayValue)/Acc_max);
  angle2 = 110 - Height + Hy;
  angle3 = 15 + Height - Hy;
  MyServo2.write(angle2);
  MyServo3.write(angle3);
  delay(100);
  for(int i = 0;i < Hy;i++){
    angle3++;
    angle2--;
    MyServo2.write(angle2);
    MyServo3.write(angle3);
    delay(Ftime);
    }
  }

void Downward(float azValue)
{
  if(azValue > Acc_max)  azValue = Acc_max;
  int Hz = abs((Height*azValue)/Acc_max);
  angle1 = 15 + Height - Hz;
  angle2 = 110 - Height + Hz;
  angle3 = 20 + Height - Hz;
  angle4 = 100 - Height + Hz;
  MyServo1.write(angle1);
  MyServo2.write(angle2);
  MyServo3.write(angle3);
  MyServo4.write(angle4);
  delay(100);
  for(int i = 0;i < Hz;i++){
    angle1++;
    angle2--;
    angle3++;
    angle4--;
    MyServo1.write(angle1);
    MyServo2.write(angle2);
    MyServo3.write(angle3);
    MyServo4.write(angle4);
    delay(Ftime);
    }
  }
