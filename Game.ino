#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include "U8glib.h"
#include <stdio.h>
#include <stdlib.h>
#define SCREEN_WIDHT 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
#define PAUSE 1000
   
Adafruit_SSD1306 display(SCREEN_WIDHT,SCREEN_HEIGHT,&Wire,OLED_RESET);
 //U8GLIB_SSD1306_128X64 u8g(13, 11, 8, 9, 10);
 struct yap{
 
int y=0;
int x2=17;
int y2=0;
int control=0;
int shipX=32;
int shipY=120;
int control2=0;
int control3=0;
int prevX=0;
int prevY=0;
 };






 
 int potValue=0;
 int potMovement=0;
 int v=0;
int h=0; 
 int fark=0;
 
yap a;
boolean buttonStateDown=false;
boolean buttonStateUp=false;
boolean buttonStateSelect=false;
boolean buttonStateRight=false;
boolean buttonStateLeft=false;
boolean LDR=false;
boolean POT=false;
boolean attack=false;
// '1086091', 24x12px
const unsigned char spaceShip [] PROGMEM = {
	0xff, 0xe7, 0xe7, 0xe7, 0xe7, 0xc3, 0x81, 0xef, 0xff, 0xff
};



// 'kalkan', 8x8px
const unsigned char kalkan [] PROGMEM = {
	0xff, 0x81, 0x81, 0x81, 0xc1, 0xc3, 0xe3, 0xff
};
const unsigned char odul [] PROGMEM = {
	0xff, 0xe7, 0x81, 0xc3, 0xc3, 0xdb, 0xff, 0xff
};
unsigned long previousMillis = 0;  // Önceki millis değeri
long interval = 100; 








int LDR2=0;
int LDR3=0;

  void setup() {
  
 // Serial.begin(9600);
 
 display.begin(SSD1306_SWITCHCAPVCC,0x3C);
display.fillScreen(0);
display.display();
pinMode(13,INPUT);//AŞAĞI
pinMode(12,INPUT);//YUKARI
pinMode(11,INPUT);//SEÇİM
pinMode(10,INPUT);
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(1,INPUT);
pinMode(9,OUTPUT);//SİLAH HAKKI
pinMode(8,OUTPUT);//SİLAH HAKKI
pinMode(7,OUTPUT);//SİLAH HAKKI
pinMode(6,OUTPUT);//CAN HAKKI
pinMode(5,OUTPUT);//CAN HAKKI
pinMode(4,OUTPUT);//CAN HAKKI


//3. 7 SEGMEN DİSPLAY    SOLDAN SAĞA
pinMode(53,OUTPUT);
pinMode(22,OUTPUT);
pinMode(23,OUTPUT);
pinMode(24,OUTPUT);
pinMode(25,OUTPUT);
pinMode(26,OUTPUT);
pinMode(27,OUTPUT);


//2. 7 SEGMENT DİSPLAY
pinMode(52,OUTPUT);
pinMode(51,OUTPUT);
pinMode(50,OUTPUT);
pinMode(49,OUTPUT);
pinMode(48,OUTPUT);
pinMode(47,OUTPUT);
pinMode(46,OUTPUT);


//1. 7 SEGMENT DİSPLAY
pinMode(41,OUTPUT);
pinMode(39,OUTPUT);
pinMode(37,OUTPUT);
pinMode(35,OUTPUT);
pinMode(33,OUTPUT);
pinMode(31,OUTPUT);
pinMode(29,OUTPUT);


pinMode(40,OUTPUT);


//drawBitmap( 4, 2, 16/8, 16,spaceShip[28]);  
LDR2=digitalRead(1);

if(LDR2==0)
{
  LDR3=1;
  
}

if(LDR2==1)
{
  LDR3=0;
  
}




if(LDR2==1)
{
  display.fillScreen(1);

}
if(LDR2==0)
{
  display.fillScreen(0);

}
GenerateObject();

}
void D7Segment_Stop(int a,int b,int c,int d,int e,int f,int g)
{
digitalWrite(a,0);
digitalWrite(b,0);
digitalWrite(c,0);
digitalWrite(d,0);
digitalWrite(e,0);
digitalWrite(f,0);
digitalWrite(g,0);


}
void D7Segment_1(int a,int b,int c,int d,int e,int f,int g)
{
digitalWrite(a,0);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,0);
digitalWrite(e,0);
digitalWrite(f,0);
digitalWrite(g,0);


}

int arrObjectsRows[16][8];
char arrObjectTypesRows[16][8];
void GenerateObject()
{
  char arrTypeRow[5];
arrTypeRow[0]='M';
arrTypeRow[1]='U';
arrTypeRow[2]='D';
arrTypeRow[3]='O';
arrTypeRow[4]='S';




  int arrRow[8];
  arrRow[0]=0;
  arrRow[1]=8;
  arrRow[2]=16;
  arrRow[3]=24;
  arrRow[4]=32;
  arrRow[5]=40;
  arrRow[6]=48;
  arrRow[7]=56;


  int y=0;
  int ky=0;
  //o-meteor
//1-uzay çöpü
  //2-dokunulmazlık
  //3-ödül
  //4-silah
  int r1=rand()%3;//0,1,2 verir
  for(int p=0;p<16;p++)
  {

  
int r2=rand()%4+1;//1,2,3,4;


if(r2==1)//1 satıra koy
{

int r3=rand()%8;
for(int h=0;h<8;h++)
{
arrObjectsRows[y][h]=-5;//-5 ise boştur

arrObjectsRows[y][r3]=arrRow[r3];//buradaki bilgi 1 tane nesne oluştuğunda ki o nesnenin x bilgisidir

}

y++;
int rt1=rand()%5;//0,1,2,3,4;
int rt2=rand()%3;//0,1,2
for(int h=0;h<8;h++)
{

arrObjectTypesRows[ky][h]=NULL;//null ise boşluktur

arrObjectTypesRows[ky][r3]=arrTypeRow[rt2];  
}
ky++;

}
if(r2==2)// 2 satıra koy
{
  int r3=rand()%8;
int r4=rand()%8;
while(1)
{



if(r3==r4||abs(r3-r4)==1)
{
 r3=rand()%8;
 r4=rand()%8;
}
else
{
  break;
}

}
for(int h=0;h<8;h++)
{
arrObjectsRows[y][h]=-5;//-5 ise boştur

arrObjectsRows[y][r3]=arrRow[r3];//buradaki bilgi 2 tane nesne oluştuğunda ki o nesnenin x bilgisidir
arrObjectsRows[y][r4]=arrRow[r4];//buradaki bilgi 2 tane nesne oluştuğunda ki o nesnenin x bilgisidir
}

y++;
int rt1=rand()%5;//0,1,2,3,4;
int rt2=rand()%3;//0,1,2
int rt3=rand()%3;

for(int h=0;h<8;h++)
{

arrObjectTypesRows[ky][h]=NULL;  //null ise boştur

arrObjectTypesRows[ky][r3]=arrTypeRow[rt2];  
arrObjectTypesRows[ky][r4]=arrTypeRow[rt3];  
}
ky++;


}
if(r2==3)//3 satıra koy
{

int r3=rand()%8;
int r4=rand()%8;
int r5=rand()%8;
while(1)
{



if(r3==r4||abs(r3-r4)==1||r4==r5||abs(r4-r5)==1||r3==r5||abs(r3-r5)==1)
{
 r3=rand()%8;
 r4=rand()%8;
 r5=rand()%8;
}
else
{
  break;
}

}
for(int h=0;h<8;h++)
{
arrObjectsRows[y][h]=-5;//-5 ise boştur

arrObjectsRows[y][r3]=arrRow[r3];//buradaki bilgi 2 tane nesne oluştuğunda ki o nesnenin x bilgisidir
arrObjectsRows[y][r4]=arrRow[r4];//buradaki bilgi 2 tane nesne oluştuğunda ki o nesnenin x bilgisidir
arrObjectsRows[y][r5]=arrRow[r5];//buradaki bilgi 2 tane nesne oluştuğunda ki o nesnenin x bilgisidir
}

y++;
int rt1=rand()%5;//0,1,2,3,4;
int rt2=rand()%3;//0,1,2
int rt3=rand()%3;
int rt4=rand()%3;

for(int h=0;h<8;h++)
{

arrObjectTypesRows[ky][h]=NULL;  //null ise boştur

arrObjectTypesRows[ky][r3]=arrTypeRow[rt2];  
arrObjectTypesRows[ky][r4]=arrTypeRow[rt3];  
arrObjectTypesRows[ky][r5]=arrTypeRow[rt4]; 
}
ky++;

}
if(r2==4)//4 satıra koy
{
int r3=rand()%8;
int r4=rand()%8;
int r5=rand()%8;
int r6=rand()%8;
while(1)
{



if(r3==r4||abs(r3-r4)==1||r4==r5||abs(r4-r5)==1||r3==r5||abs(r3-r5)==1||r3==r6||abs(r3-r6)==1||r6==r4||abs(r6-r4)==1||r5==r6||abs(r5-r6)==1)
{
 r3=rand()%8;
 r4=rand()%8;
 r5=rand()%8;
 r6=rand()%8;
}
else
{
  break;
}

}
for(int h=0;h<8;h++)
{
arrObjectsRows[y][h]=-5;//-5 ise boştur

arrObjectsRows[y][r3]=arrRow[r3];//buradaki bilgi 2 tane nesne oluştuğunda ki o nesnenin x bilgisidir
arrObjectsRows[y][r4]=arrRow[r4];//buradaki bilgi 2 tane nesne oluştuğunda ki o nesnenin x bilgisidir
arrObjectsRows[y][r5]=arrRow[r5];//buradaki bilgi 2 tane nesne oluştuğunda ki o nesnenin x bilgisidir
arrObjectsRows[y][r6]=arrRow[r6];//buradaki bilgi 2 tane nesne oluştuğunda ki o nesnenin x bilgisidir
}

y++;
int rt1=rand()%5;//0,1,2,3,4;
int rt2=rand()%3;//0,1,2
int rt3=rand()%3;
int rt4=rand()%3;
int rt5=rand()%3;

for(int h=0;h<8;h++)
{

arrObjectTypesRows[ky][h]=NULL;  //null ise boştur

arrObjectTypesRows[ky][r3]=arrTypeRow[rt2];  
arrObjectTypesRows[ky][r4]=arrTypeRow[rt3];  
arrObjectTypesRows[ky][r5]=arrTypeRow[rt4]; 
arrObjectTypesRows[ky][r6]=arrTypeRow[rt5]; 
}
ky++;
}
  }
}
void D7Segment_2(int a,int b,int c,int d,int e,int f,int g)
{
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,0);
digitalWrite(d,1);
digitalWrite(e,1);
digitalWrite(f,0);
digitalWrite(g,1);


}

void D7Segment_0(int a,int b,int c,int d,int e,int f,int g)
{
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,1);
digitalWrite(f,1);
digitalWrite(g,0);


}

int arrTemp[16][8];
char arrCharTemp[16][8];
int NmbrLifeRight = 3;       // global değişken
int *p_NmbrLifeRight = &NmbrLifeRight;  // global pointer

int NmbrBulletRight = 3;       // global değişken
int *p_NmbrBulletRight = &NmbrBulletRight;  // global pointer

int Immunity=0;
int *p_Immunity=&Immunity;

int Immunity3=0;
int *p_Immunity3=&Immunity3;

int ImmunityLIFE=0;
int *p_ImmunityLIFE=&ImmunityLIFE;

int ImmunityLIFE3=0;
int *p_ImmunityLIFE3=&ImmunityLIFE3;
void MovementObjects2(int Row,int Column)
{
   

for(int g=0;g<8;g++)
    {

             

//if(arrTemp[Row][g]!=-5)
  //    {
            
            if(arrCharTemp[Row][g]=='Y')
            {
display.setCursor(arrObjectsRows[Row][g]+8,Column);

display.setTextColor(LDR3);
display.setTextSize(1);
display.print("*");
            }
            if(arrCharTemp[Row][g]=='S')
            {
display.setCursor(arrObjectsRows[Row][g]+8,Column);

display.setTextColor(LDR3);
display.setTextSize(1);
display.print("+");
            }
            if(arrCharTemp[Row][g]=='K')
            {
display.fillCircle(arrObjectsRows[Row][g]+8,Column+3, 3,LDR3);
            }
            if(arrCharTemp[Row][g]=='M')
            {
              display.drawBitmap(arrTemp[Row][g],Column,kalkan,8,8,LDR3);
              
            

            }
            if(arrCharTemp[Row][g]=='U')
            {
              display.drawBitmap(arrTemp[Row][g], Column, odul,8,8,LDR3);

              
              
            }
            if(arrCharTemp[Row][g]=='D')
            {
             // display.fillCircle(arrTemp[Row][g]+3, Column+3, 3,1);
              
              
            }   
            
if(a.shipX==arrTemp[Row][g]&&(arrCharTemp[Row][g]=='U'||arrCharTemp[Row][g]=='M'))
{
if(Column==112)
{
  if((*p_NmbrLifeRight)!=0)
  {

  (*p_ImmunityLIFE)++;

tone(40, 1000); // Send 1KHz sound signal
    
  (*p_NmbrLifeRight)--;
if(Immunity3==1||Immunity3==2||Immunity3==3)
  {
     (*p_NmbrLifeRight)++;
     noTone(40);
  }

  if(ImmunityLIFE3==1||ImmunityLIFE3==2||ImmunityLIFE3==3)
  {
     (*p_NmbrLifeRight)++;
     noTone(40);
  }
  }
 // digitalWrite(5,LOW);
}
}
//*******************************
if(a.shipX-8==(arrTemp[Row][g])&&arrCharTemp[Row][g]=='Y')
{
if(Column==112)
{
  (*p_NmbrLifeRight)++;
  
 // digitalWrite(5,HIGH);
}
}

if(a.shipX==(arrTemp[Row][g]+8)&&arrCharTemp[Row][g]=='S')
{
if(Column==112)
{
  (*p_NmbrBulletRight)++;
  //digitalWrite(9,LOW);
}
}

if(a.shipX==(arrTemp[Row][g]+8)&&arrCharTemp[Row][g]=='K')
{
if(Column==112)
{
  //digitalWrite(5,LOW);//kalkan
 (*p_Immunity)++;
}
}     

                           
      }

             
  //  }

}


void D7Segment_3(int a,int b,int c,int d,int e,int f,int g)
{
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,0);
digitalWrite(f,0);
digitalWrite(g,1);


}
void D7Segment_4(int a,int b,int c,int d,int e,int f,int g)
{
digitalWrite(a,0);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,0);
digitalWrite(e,0);
digitalWrite(f,1);
digitalWrite(g,1);


}






void MovementObjects(int Row,int Column)
{
   


for(int g=0;g<8;g++)
    {
if(a.shipX==arrObjectsRows[Row][g]&&(arrObjectTypesRows[Row][g]=='U'||arrObjectTypesRows[Row][g]=='M'))
{
if(Column==112)
{
  if((*p_NmbrLifeRight)!=0)
{
  
  (*p_ImmunityLIFE)++;
    
  tone(40, 1000); // Send 1KHz sound signal

   (*p_NmbrLifeRight)--;
  
  if(Immunity3==1||Immunity3==2||Immunity3==3)
  {
    noTone(40);
     (*p_NmbrLifeRight)++;
  }

  if(ImmunityLIFE3==1||ImmunityLIFE3==2||ImmunityLIFE3==3)
  {
     (*p_NmbrLifeRight)++;
     noTone(40);
  }
}
  //digitalWrite(4,LOW);
}
}
//*******************************
if(a.shipX-8==(arrObjectsRows[Row][g])&&arrObjectTypesRows[Row][g]=='Y')
{
if(Column==112)
{
   (*p_NmbrLifeRight)++;
 // digitalWrite(5,HIGH);
}
}

if(a.shipX==(arrObjectsRows[Row][g]+8)&&arrObjectTypesRows[Row][g]=='S')
{
if(Column==112)
{
  (*p_NmbrBulletRight)++;
 // digitalWrite(9,LOW);
}
}      

if(a.shipX==(arrObjectsRows[Row][g]+8)&&arrObjectTypesRows[Row][g]=='K')
{
if(Column==112)
{

 // digitalWrite(5,LOW);//kalkan
  (*p_Immunity)++;
}
}     


//if(arrObjectsRows[Row][g]!=-5)
  //    {
            if(arrObjectTypesRows[Row][g]=='Y')
            {
display.setCursor(arrObjectsRows[Row][g]+8,Column);

display.setTextColor(LDR3);
display.setTextSize(1);
display.print("*");



            }
            if(arrObjectTypesRows[Row][g]=='S')
            {
display.setCursor(arrObjectsRows[Row][g]+8,Column);

display.setTextColor(LDR3);//1
display.setTextSize(1);
display.print("+");
            }
            if(arrObjectTypesRows[Row][g]=='K')
            {
display.fillCircle(arrObjectsRows[Row][g]+8,Column+3, 3,LDR3);
            }
            
            if(arrObjectTypesRows[Row][g]=='M')
            {
              
              display.drawBitmap( arrObjectsRows[Row][g],Column,kalkan,8,8,LDR3);
              
            

            }
            if(arrObjectTypesRows[Row][g]=='U')
            {
              display.drawBitmap( arrObjectsRows[Row][g], Column, odul,8,8,LDR3);

              
              
            }
            if(arrObjectTypesRows[Row][g]=='D')
            {
             // display.fillCircle(arrObjectsRows[Row][g]+3, Column+3, 3,1);
                      
              
            }   

                           
      }

             
   // }

}

void D7Segment_5(int a,int b,int c,int d,int e,int f,int g)
{
digitalWrite(a,1);
digitalWrite(b,0);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,0);
digitalWrite(f,1);
digitalWrite(g,1);


}

void D7Segment_6(int a,int b,int c,int d,int e,int f,int g)
{
digitalWrite(a,1);
digitalWrite(b,0);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,1);
digitalWrite(f,1);
digitalWrite(g,1);


}

void ConfigureArr(int Row2,int Column2)
{
int o=0;

  while(o!=3)
  {
    if(arrObjectTypesRows[Row2][Column2]=='U'||arrObjectTypesRows[Row2][Column2]=='M')
    {

o++;
if(o==1)
{
arrObjectTypesRows[Row2][Column2]='Y';
}
if(o==2)
{
arrObjectTypesRows[Row2][Column2]='K';
}
if(o==3)
{
arrObjectTypesRows[Row2][Column2]='S';
break;
}


    }
    if(Column2==0)
    {
      Row2--;
      Column2=7;
    }
    Column2--;
  }
  
}



void D7Segment_7(int a,int b,int c,int d,int e,int f,int g)
{
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,0);
digitalWrite(e,0);
digitalWrite(f,0);
digitalWrite(g,0);


}


void D7SegmentNUMBER(int Result)
{
  if(Result==0)
{
D7Segment_0(53,22,23,24,25,26,27);
}
if(Result==1)
{
D7Segment_Stop(53,22,23,24,25,26,27);
D7Segment_1(53,22,23,24,25,26,27);
}

if(Result==2)
{
D7Segment_Stop(53,22,23,24,25,26,27);
D7Segment_2(53,22,23,24,25,26,27);
}
if(Result==3)
{
D7Segment_Stop(53,22,23,24,25,26,27);
D7Segment_3(53,22,23,24,25,26,27);
}
if(Result==4)
{
D7Segment_Stop(53,22,23,24,25,26,27);
D7Segment_4(53,22,23,24,25,26,27);
}

if(Result==5)
{
D7Segment_Stop(53,22,23,24,25,26,27);
D7Segment_5(53,22,23,24,25,26,27);
}
if(Result==6)
{
D7Segment_Stop(53,22,23,24,25,26,27);
D7Segment_6(53,22,23,24,25,26,27);
}

if(Result==7)
{
D7Segment_Stop(53,22,23,24,25,26,27);
D7Segment_7(53,22,23,24,25,26,27);
}

if(Result==8)
{
D7Segment_Stop(53,22,23,24,25,26,27);
D7Segment_8(53,22,23,24,25,26,27);
}

if(Result==9)
{
D7Segment_Stop(53,22,23,24,25,26,27);
D7Segment_9(53,22,23,24,25,26,27);
}
}


//*********************************************

void D7SegmentNUMBER2(int Result)
{
  if(Result==0)
{
D7Segment_0(52,51,50,49,48,47,46);
}
if(Result==1)
{
D7Segment_Stop(52,51,50,49,48,47,46);
D7Segment_1(52,51,50,49,48,47,46);
}

if(Result==2)
{
D7Segment_Stop(52,51,50,49,48,47,46);
D7Segment_2(52,51,50,49,48,47,46);
}
if(Result==3)
{
D7Segment_Stop(52,51,50,49,48,47,46);
D7Segment_3(52,51,50,49,48,47,46);
}
if(Result==4)
{
D7Segment_Stop(52,51,50,49,48,47,46);
D7Segment_4(52,51,50,49,48,47,46);
}

if(Result==5)
{
D7Segment_Stop(52,51,50,49,48,47,46);
D7Segment_5(52,51,50,49,48,47,46);
}
if(Result==6)
{
D7Segment_Stop(52,51,50,49,48,47,46);
D7Segment_6(52,51,50,49,48,47,46);
}

if(Result==7)
{
D7Segment_Stop(52,51,50,49,48,47,46);
D7Segment_7(52,51,50,49,48,47,46);
}

if(Result==8)
{
D7Segment_Stop(52,51,50,49,48,47,46);
D7Segment_8(52,51,50,49,48,47,46);
}

if(Result==9)
{
D7Segment_Stop(52,51,50,49,48,47,46);
D7Segment_9(52,51,50,49,48,47,46);
}
}
//**********************************************************

void D7SegmentNUMBER3(int Result)
{
  if(Result==0)
{
D7Segment_0(41,39,37,35,33,31,29);
}
if(Result==1)
{
D7Segment_Stop(41,39,37,35,33,31,29);
D7Segment_1(41,39,37,35,33,31,29);
}

if(Result==2)
{
D7Segment_Stop(41,39,37,35,33,31,29);
D7Segment_2(41,39,37,35,33,31,29);
}
if(Result==3)
{
D7Segment_Stop(41,39,37,35,33,31,29);
D7Segment_3(41,39,37,35,33,31,29);
}
if(Result==4)
{
D7Segment_Stop(41,39,37,35,33,31,29);
D7Segment_4(41,39,37,35,33,31,29);
}

if(Result==5)
{
D7Segment_Stop(41,39,37,35,33,31,29);
D7Segment_5(41,39,37,35,33,31,29);
}
if(Result==6)
{
D7Segment_Stop(41,39,37,35,33,31,29);
D7Segment_6(41,39,37,35,33,31,29);
}

if(Result==7)
{
D7Segment_Stop(41,39,37,35,33,31,29);
D7Segment_7(41,39,37,35,33,31,29);
}

if(Result==8)
{
D7Segment_Stop(41,39,37,35,33,31,29);
D7Segment_8(41,39,37,35,33,31,29);
}

if(Result==9)
{
D7Segment_Stop(41,39,37,35,33,31,29);
D7Segment_9(41,39,37,35,33,31,29);
}
}

int Result=0;
int CtrlCounter=0;
int Counter14=0;
int counter=0;
int ChangeBulletY=a.shipY;
int AttackControl1=0;
int AttackControl2=0;

void loop() {


if(Result>=0&&Result<10)
{
D7SegmentNUMBER(Result);
}
if(Result>=10&&Result<100)
{int remainder=0;
int secondDigit=0;
remainder=Result%10;
secondDigit=Result/10;
D7SegmentNUMBER(remainder);
D7SegmentNUMBER2(secondDigit);

}
if(Result>=100)
{
int remainder=0;
int secondDigit=0;
int thirdDigit=0;
int tempzx=0;
remainder=Result%10;
secondDigit=Result%100;
tempzx=secondDigit/10;
thirdDigit=Result/100;
D7SegmentNUMBER(remainder);
D7SegmentNUMBER2(tempzx);
D7SegmentNUMBER3(thirdDigit);

}





LDR2=digitalRead(1);

if(LDR2==0)
{
  LDR3=1;
  
}

if(LDR2==1)
{
  LDR3=0;
  
}




if(a.control==1)
{


if(counter==0)
{

GenerateObject();
 

for(int zx=0;zx<16;zx++)
{
      for(int gh=0;gh<8;gh++)
      {
          if(arrObjectTypesRows[zx][gh]=='M'||arrObjectTypesRows[zx][gh]=='U') 
          {
 Counter14++;
 if(Counter14==17)
 {

 ConfigureArr(zx+2,gh);
 Counter14=0;
          }
      }  
}

}
}
}
//sağ mı sol mu
display.setRotation(3);
if(a.control==1)
{
  
  attack=digitalRead(10);
  
 
  
  
  
if(attack==1)
{
 

  if((*p_NmbrBulletRight)!=0)
{

  
   (*p_NmbrBulletRight)--;
}
}
  

  

  
  //---------------------------------------------------

if(CtrlCounter==1)
{



if(attack==1)
{
 
  display.drawLine(a.shipX+4,a.shipY-4,a.shipX+4,a.shipY-6,LDR3);
ChangeBulletY=a.shipX;
for(int f=0;f<16;f++)
{
  int pk=0;
for(pk=0;pk<8;pk++)
{
if(arrTemp[f][pk]==a.shipX&&(arrCharTemp[f][pk]=='U'||arrCharTemp[f][pk]=='M'))  
{
  if(arrCharTemp[f][pk]=='M')
  {
     (*p_NmbrBulletRight)--;
      if(NmbrBulletRight<0)
     {
       NmbrBulletRight=0;

     }
  }
  arrCharTemp[f][pk]='P';
  break;
}

}  

if(arrCharTemp[f][pk]=='P')
{

  break;
}
} 

}



}

//***************************
if(attack==1)
{
  display.drawLine(a.shipX+4,a.shipY-4,a.shipX+4,a.shipY-6,LDR3);
ChangeBulletY=a.shipX;
for(int f=0;f<16;f++)
{
  int pk=0;
for(pk=0;pk<8;pk++)
{
if(arrObjectsRows[f][pk]==a.shipX&&(arrObjectTypesRows[f][pk]=='U'||arrObjectTypesRows[f][pk]=='M'))  
{

if(arrObjectTypesRows[f][pk]=='M')
  {
     (*p_NmbrBulletRight)--;
     if(NmbrBulletRight<0)
     {
       NmbrBulletRight=0;
       
     }
  }
  
  arrObjectTypesRows[f][pk]='Q';
  break;
}

}  

if(arrObjectTypesRows[f][pk]=='Q')
{
  
  break;
}
} 

}




AttackControl1=0;
AttackControl2=0;



unsigned long currentMillis = millis();  // Geçen süreyi hesapla
  
  if (currentMillis - previousMillis >= interval) {  // Belirli bir süre geçti mi?
    previousMillis = currentMillis;  // Değeri güncelle
    
   
  

if(Immunity>0)
{
  
  
  (*p_Immunity3)++;
  
  
}
if(Immunity3==4)
{
  //digitalWrite(6,LOW);
  (*p_Immunity)=0;
  (*p_Immunity3)=0;
  
}
//-----------------------------
if(ImmunityLIFE>0)
{
  
  
  (*p_ImmunityLIFE3)++;
  
  
}
if(ImmunityLIFE3==4)
{
  //digitalWrite(6,LOW);
  (*p_ImmunityLIFE)=0;
  (*p_ImmunityLIFE3)=0;
  
}





 Result++;


  
if(counter==0)
{
  display.fillScreen(LDR2);
  MovementObjects(0,0);

}
if(counter==1)
{
  display.clearDisplay();
  display.fillScreen(LDR2);
 MovementObjects(0,8);
 MovementObjects(1,0);

}
if(counter==2)
{
  display.clearDisplay();
  display.fillScreen(LDR2);
MovementObjects(0,16);
 MovementObjects(1,8);
 MovementObjects(2,0);
 
}
if(counter==3)
{
  display.clearDisplay();
  display.fillScreen(LDR2);
  MovementObjects(0,24);
 MovementObjects(1,16);
 MovementObjects(2,8);
 MovementObjects(3,0);
}
if(counter==4)
{
  display.clearDisplay();
  display.fillScreen(LDR2);
  MovementObjects(0,32);
 MovementObjects(1,24);
 MovementObjects(2,16);
 MovementObjects(3,8);
 MovementObjects(4,0);
}
if(counter==5)
{
  display.clearDisplay();
  display.fillScreen(LDR2);
  MovementObjects(0,40);
 MovementObjects(1,32);
 MovementObjects(2,24);
 MovementObjects(3,16);
 MovementObjects(4,8);
 MovementObjects(5,0);
}
if(counter==6)
{
  display.clearDisplay();
  display.fillScreen(LDR2);
  MovementObjects(0,48);
 MovementObjects(1,40);
 MovementObjects(2,32);
 MovementObjects(3,24);
 MovementObjects(4,16);
 MovementObjects(5,8);
 MovementObjects(6,0);
}
if(counter==7)
{
  display.clearDisplay();
  display.fillScreen(LDR2);
  MovementObjects(0,56);
 MovementObjects(1,48);
 MovementObjects(2,40);
 MovementObjects(3,32);
 MovementObjects(4,24);
 MovementObjects(5,16);
 MovementObjects(6,8);
 MovementObjects(7,0);
}
if(counter==8)
{
  display.clearDisplay();
  display.fillScreen(LDR2);
  MovementObjects(0,64);
 MovementObjects(1,56);
 MovementObjects(2,48);
 MovementObjects(3,40);
 MovementObjects(4,32);
 MovementObjects(5,24);
 MovementObjects(6,16);
 MovementObjects(7,8);
 MovementObjects(8,0);
}
if(counter==9)
{
  display.clearDisplay();
  display.fillScreen(LDR2);
  MovementObjects(0,72);
 MovementObjects(1,64);
 MovementObjects(2,56);
 MovementObjects(3,48);
 MovementObjects(4,40);
 MovementObjects(5,32);
 MovementObjects(6,24);
 MovementObjects(7,16);
 MovementObjects(8,8);
 MovementObjects(9,0);
}
if(counter==10)
{
  display.clearDisplay();
  display.fillScreen(LDR2);
  MovementObjects(0,80);
 MovementObjects(1,72);
 MovementObjects(2,64);
 MovementObjects(3,56);
 MovementObjects(4,48);
 MovementObjects(5,40);
 MovementObjects(6,32);
 MovementObjects(7,24);
 MovementObjects(8,16);
 MovementObjects(9,8);
 MovementObjects(10,0);
}
if(counter==11)
{
  display.clearDisplay();
  display.fillScreen(LDR2);
  MovementObjects(0,88);
 MovementObjects(1,80);
 MovementObjects(2,72);
 MovementObjects(3,64);
 MovementObjects(4,56);
 MovementObjects(5,48);
 MovementObjects(6,40);
 MovementObjects(7,32);
 MovementObjects(8,24);
 MovementObjects(9,16);
 MovementObjects(10,8);
 MovementObjects(11,0);
}
if(counter==12)
{
  display.clearDisplay();
  display.fillScreen(LDR2);
   MovementObjects(0,96);
 MovementObjects(1,88);
 MovementObjects(2,80);
 MovementObjects(3,72);
 MovementObjects(4,64);
 MovementObjects(5,56);
 MovementObjects(6,48);
 MovementObjects(7,40);
 MovementObjects(8,32);
 MovementObjects(9,24);
 MovementObjects(10,16);
 MovementObjects(11,8);
 MovementObjects(12,0);
}
if(counter==13)
{
  
  
  
  display.clearDisplay();
  display.fillScreen(LDR2);
   MovementObjects(0,104);




  
 MovementObjects(1,96);
 MovementObjects(2,88);
 MovementObjects(3,80);
 MovementObjects(4,72);
 MovementObjects(5,64);
 MovementObjects(6,56);
 MovementObjects(7,48);
 MovementObjects(8,40);
 MovementObjects(9,32);
 MovementObjects(10,24);
 MovementObjects(11,16);
 MovementObjects(12,8);
 MovementObjects(13,0);
}
if(counter==14)
{





  display.clearDisplay();
display.fillScreen(LDR2);
  
  MovementObjects(0,112);
 MovementObjects(1,104);
 MovementObjects(2,96);
 MovementObjects(3,88);
 MovementObjects(4,80);
 MovementObjects(5,72);
 MovementObjects(6,64);
 MovementObjects(7,56);
 MovementObjects(8,48);
 MovementObjects(9,40);
 MovementObjects(10,32);
 MovementObjects(11,24);
 MovementObjects(12,16);
 MovementObjects(13,8);
 MovementObjects(14,0);
}
if(counter==15)
{
  display.clearDisplay();
  display.fillScreen(LDR2);
  MovementObjects(0,120);
 MovementObjects(1,112);
 MovementObjects(2,104);
 MovementObjects(3,96);
 MovementObjects(4,88);
 MovementObjects(5,80);
 MovementObjects(6,72);
 MovementObjects(7,64);
 MovementObjects(8,56);
 MovementObjects(9,48);
 MovementObjects(10,40);
 MovementObjects(11,32);
 MovementObjects(12,24);
 MovementObjects(13,16);
 MovementObjects(14,8);
 MovementObjects(15,0);






for(int ik = 0; ik < 16; ik++) {
      for(int jl = 0; jl < 8; jl++) {
         arrTemp[ik][jl] = arrObjectsRows[ik][jl];
      }
   }

   for(int iz = 0; iz < 16; iz++) {
      for(int jz = 0; jz < 8; jz++) {
         arrCharTemp[iz][jz] = arrObjectTypesRows[iz][jz];
      }
   }
CtrlCounter=1;


      /*
      if(arrObjectsRows[counter][g]!=-5)
      {
            
            if(arrObjectTypesRows[counter][g]=='M')
            {
              display.drawBitmap( arrObjectsRows[counter][g],h,kalkan,8,8,1);
              
              if(counter!=0)
              {
                    
              
              display.fillRect(arrObjectsRows[counter-1][g], h-8, 8, 8,0);
              }

            }
            if(arrObjectTypesRows[counter][g]=='U')
            {
              display.drawBitmap( arrObjectsRows[counter][g], h, odul,8,8,1);

              if(counter!=0)
              {

              
              display.fillRect(arrObjectsRows[counter-1][g], h-8, 8, 8,0);
              }
            }
            if(arrObjectTypesRows[counter][g]=='D')
            {
              display.fillCircle(arrObjectsRows[counter][g], h, 4,1);

              if(counter!=0)
              {

              
              display.fillRect(arrObjectsRows[counter-1][g], h-8, 8, 8,0);
              }
            }                
      }
      */
    }
    counter++;
   if(counter==16)
   {
     counter=0;
   }
    //0-meteor
    //1-uzay çöpü
//    2-dokunulmazlık


h=h+8;
if(h==128)//128 olduğunda artık görünmüyordur
{
h=0;  

}
if(CtrlCounter==1)
{
 
  
if(counter==1)
{

 
  display.clearDisplay();
  display.fillScreen(LDR2);
 MovementObjects2(1,120);
 MovementObjects2(2,112);
 MovementObjects2(3,104);
 MovementObjects2(4,96);
 MovementObjects2(5,88);
 MovementObjects2(6,80);
 MovementObjects2(7,72);
 MovementObjects2(8,64);
 MovementObjects2(9,56);
 MovementObjects2(10,48);
 MovementObjects2(11,40);
 MovementObjects2(12,32);
 MovementObjects2(13,24);
 MovementObjects2(14,16);
 MovementObjects2(15,8);

}
if(counter==2)
{
  
 MovementObjects2(2,120);
 MovementObjects2(3,112);
 MovementObjects2(4,104);
 MovementObjects2(5,96);
 MovementObjects2(6,88);
 MovementObjects2(7,80);
 MovementObjects2(8,72);
 MovementObjects2(9,64);
 MovementObjects2(10,56);
 MovementObjects2(11,48);
 MovementObjects2(12,40);
 MovementObjects2(13,32);
 MovementObjects2(14,24);
 MovementObjects2(15,16);
 
}
if(counter==3)
{
  
 MovementObjects2(3,120);
 MovementObjects2(4,112);
 MovementObjects2(5,104);
 MovementObjects2(6,96);
 MovementObjects2(7,88);
 MovementObjects2(8,80);
 MovementObjects2(9,72);
 MovementObjects2(10,64);
 MovementObjects2(11,56);
 MovementObjects2(12,48);
 MovementObjects2(13,40);
 MovementObjects2(14,32);
 MovementObjects2(15,24);
}
if(counter==4)
{
  
 MovementObjects2(4,120);
 MovementObjects2(5,112);
 MovementObjects2(6,104);
 MovementObjects2(7,96);
 MovementObjects2(8,88);
 MovementObjects2(9,80);
 MovementObjects2(10,72);
 MovementObjects2(11,64);
 MovementObjects2(12,56);
 MovementObjects2(13,48);
 MovementObjects2(14,40);
 MovementObjects2(15,32);
}
if(counter==5)
{
  
 MovementObjects2(5,120);
 MovementObjects2(6,112);
 MovementObjects2(7,104);
 MovementObjects2(8,96);
 MovementObjects2(9,88);
 MovementObjects2(10,80);
 MovementObjects2(11,72);
 MovementObjects2(12,64);
 MovementObjects2(13,56);
 MovementObjects2(14,48);
 MovementObjects2(15,40);
}
if(counter==6)
{
  
 MovementObjects2(6,120);
 MovementObjects2(7,112);
 MovementObjects2(8,104);
 MovementObjects2(9,96);
 MovementObjects2(10,88);
 MovementObjects2(11,80);
 MovementObjects2(12,72);
 MovementObjects2(13,64);
 MovementObjects2(14,56);
 MovementObjects2(15,48);
}
if(counter==7)
{
 
 MovementObjects2(7,120);
 MovementObjects2(8,112);
 MovementObjects2(9,104);
 MovementObjects2(10,96);
 MovementObjects2(11,88);
 MovementObjects2(12,80);
 MovementObjects2(13,72);
 MovementObjects2(14,64);
 MovementObjects2(15,56);
}
if(counter==8)
{
  
 MovementObjects2(8,120);
 MovementObjects2(9,112);
 MovementObjects2(10,104);
 MovementObjects2(11,96);
 MovementObjects2(12,88);
 MovementObjects2(13,80);
 MovementObjects2(14,72);
 MovementObjects2(15,64);
}
if(counter==9)
{
  
 MovementObjects2(9,120);
 MovementObjects2(10,112);
 MovementObjects2(11,104);
 MovementObjects2(12,96);
 MovementObjects2(13,88);
 MovementObjects2(14,80);
 MovementObjects2(15,72);
}
if(counter==10)
{
 
 MovementObjects2(10,120);
 MovementObjects2(11,112);
 MovementObjects2(12,104);
 MovementObjects2(13,96);
 MovementObjects2(14,88);
 MovementObjects2(15,80);
}
if(counter==11)
{
  
 MovementObjects2(11,120);
 MovementObjects2(12,112);
 MovementObjects2(13,104);
 MovementObjects2(14,96);
 MovementObjects2(15,88);
}
if(counter==12)
{
  
 MovementObjects2(12,120);
 MovementObjects2(13,112);
 MovementObjects2(14,104);
 MovementObjects2(15,96);
}
if(counter==13)
{
  
 MovementObjects2(13,120);
 MovementObjects2(14,112);
 MovementObjects2(15,104);
}
if(counter==14)
{
  
 MovementObjects2(14,120);
 MovementObjects2(15,112);
}
if(counter==15)
{
  
 MovementObjects2(15,120);
}

}
  }
  delay(5);
  noTone(40);

}
display.setRotation(0);
//display.drawBitmap(0, 120, spaceShip,8,10,1);  

 buttonStateRight=digitalRead(3);
 buttonStateLeft=digitalRead(2);
 
 
 //attack=digitalRead(10);
if(a.control==1)
{
display.setRotation(3);//**********************************************

 
if(buttonStateRight==1)
{
   a.control2=1;
   a.prevX=a.shipX;
  a.shipX=a.shipX+8;
  if(a.shipX==64)
  {
    a.shipX=a.shipX-8;
  }
  
  display.drawBitmap(a.shipX,a.shipY, spaceShip,8,10,LDR3);//1 
 // a.shipX=a.shipX+8;
 
}

if(buttonStateLeft==1)
{
  
a.control3=1;
a.prevX=a.shipX;
  a.shipX=a.shipX-8;
  if(a.shipX<0)
  {
  
     a.shipX=a.shipX+8;
  }
  
  display.drawBitmap(a.shipX,a.shipY, spaceShip,8,10,LDR3);//1 
  
}


display.drawBitmap(a.shipX,a.shipY, spaceShip,8,10,LDR3);//1 

if(a.control2==1||a.control3==1)
{

  display.fillRect(a.prevX, a.shipY, 8, 10,LDR2);//0



}



if(NmbrBulletRight==3)
{
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);

}
if(NmbrBulletRight==2)
{
digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(7,LOW);
}
if(NmbrBulletRight==1)
{
digitalWrite(9,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
}
if(NmbrBulletRight==0)
{
digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
}



if(NmbrLifeRight==3)
{
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);

}
if(NmbrLifeRight==2)
{
digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
}
if(NmbrLifeRight==1)
{
digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
}
if(NmbrLifeRight==0)
{
digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  a.control=0;
  Result=0;
  
  a.y=0;
counter=0;  
NmbrLifeRight=3;
NmbrBulletRight=3;
a.shipX=32;
a.shipY=120;
CtrlCounter=0;
display.clearDisplay();
display.fillScreen(LDR2);//0
}




  
  









//***************************

 






a.control2=0;
a.control3=0;

//display.clearDisplay();

display.setRotation(0);//****************************************************************

}






if(a.y==1)//buraya sürekli olarak girer
{
  display.setRotation (0) ;
  buttonStateDown=digitalRead(13);
buttonStateUp=digitalRead(12);
buttonStateSelect=digitalRead(11);



if(a.control==0)
{


//delay(90);
}
if(buttonStateDown==1||buttonStateUp==1||buttonStateSelect==1)
{
  display.clearDisplay();
  display.fillScreen(LDR2);//0
}

//display.drawRect(17,5,27,55,1);
if(buttonStateDown==1)
{
  a.x2=a.x2+30;
  if(a.x2>=17&&a.x2<=77)
  {
    display.drawRect(a.x2,5,27,55,LDR3);//1
  }
  else
  {
  a.x2=a.x2-30;
  display.drawRect(a.x2,5,27,55,LDR3);//1
  }
  
}
if(buttonStateUp==1)
{
 a.x2=a.x2-30;
 if(a.x2>=17&&a.x2<=77)
  {
    display.drawRect(a.x2,5,27,55,LDR3);//1
  }
  else
  {
  a.x2=a.x2+30;
  display.drawRect(a.x2,5,27,55,LDR3);//1
  }
}

if(buttonStateSelect==1&&a.x2!=17)
{
if(a.x2==47)
{
interval = 100;
}
if(a.x2==77)
{
interval = 80;
}
}


if(buttonStateSelect==1&&a.x2==17)
{
  
  a.control=1;
  display.clearDisplay();
  display.setRotation (3) ;
 D7Segment_Stop(53,22,23,24,25,26,27);
  D7Segment_Stop(52,51,50,49,48,47,46);
  D7Segment_Stop(41,39,37,35,33,31,29);
 
  display.fillScreen(LDR2);//0


  




}
  
}


if(a.control==0)
{


display.fillRect(20,7,20,50,LDR3);//1
display.fillRect(50,7,20,50,LDR3);//1
display.fillRect(80,7,20,50,LDR3);//1


display.setCursor(20,5);
display.setRotation (3) ;
display.setTextColor(LDR3);//1
display.setTextSize(1);
display.print("MENU");

display.setCursor(20,25);


  display.setTextColor(LDR2);//0


display.setTextSize(1);
display.print("START");

display.setCursor(12,55);



  display.setTextColor(LDR2);//0


display.setTextSize(1);
display.print("1.LEVEL");
display.setCursor(12,85);


  display.setTextColor(LDR2);//0


display.setTextSize(1);
display.print("2.LEVEL");
a.y=1;
}

display.display();

}

void D7Segment_8(int a,int b,int c,int d,int e,int f,int g)
{
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,1);
digitalWrite(f,1);
digitalWrite(g,1);


}

void D7Segment_9(int a,int b,int c,int d,int e,int f,int g)
{
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,0);
digitalWrite(f,1);
digitalWrite(g,1);


}
