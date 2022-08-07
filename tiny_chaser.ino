
#include <EEPROM.h>
int dly,a,b,c,d,f;
bool st;

void setup() {
dly=120;
 f=EEPROM.read(0);
 if(f>13)f=0;
 pinMode(0,OUTPUT);  // CLOCK OUT
pinMode(1,OUTPUT); // LATCH
  pinMode(2,OUTPUT); // DATA OUT
  pinMode(4,INPUT_PULLUP);
 }

void loop() {
  dly=analogRead(A3);
  dly=map(dly,0,1023,0,200);
  while(!digitalRead(4)){
     DataWrite(0);
     if(!st){f++;
     st=1;
     EEPROM.update(0, f);
     if(f>13)f=0;
     }
    }
    st=0;
  switch(f){
    case 0:
  a=1;


 for(int i=0;i<8;i++){
  
    DataWrite(a);
    a=a*2;
     delay(dly);
 }
     return;
   case 1:
    a=128;
 
 for(int i=0;i<8;i++){
   
    DataWrite(a);
   a=a/2;
     delay(dly);}
     return;
      case 2:
    a=b=1;
 
 for(int i=0;i<8;i++){
   
    DataWrite(b);
   a=a*2;
   b=b+a;
     delay(dly);}
     DataWrite(0);
     delay(dly);
     return;
     case 3:
    a=b=128;
 
 for(int i=0;i<8;i++){
   
    DataWrite(b);
   a=a/2;
   b=b+a;
     delay(dly);}
      DataWrite(0);
     delay(dly);
     return;
    case 4:
    //a=255;
    a=b=1;
 
 for(int i=0;i<8;i++){
   
    DataWrite(b);
   a=a*2;
   b=b+a;
     delay(dly);}
     
 for(int i=0;i<8;i++){
  b=b/2;
    DataWrite(b);
   
   
     delay(dly);}
     DataWrite(0);
     delay(dly);
     return;
     case 5:
    a=b=128;
 
 for(int i=0;i<8;i++){
   
    DataWrite(b);
   a=a/2;
   b=b+a;
     delay(dly);}
a=1;
     for(int i=0;i<8;i++){
  b=b-a;
    DataWrite(b);
   a=a*2;
     delay(dly);}
      DataWrite(0);
     delay(dly);
     return;
 case 6:
    //a=255;
    a=b=1;
 
 for(int i=0;i<8;i++){
   
    DataWrite(b);
   a=a*2;
   b=b+a;
     delay(dly);}
     a=1;
     for(int i=0;i<8;i++){
  b=b-a;
    DataWrite(b);
   a=a*2;
     delay(dly);}
      DataWrite(0);
     delay(dly);
 
     return;
     case 7:
    a=b=128;
 
 for(int i=0;i<8;i++){
   
    DataWrite(b);
   a=a/2;
   b=b+a;
     delay(dly);}

for(int i=0;i<8;i++){
  b=b/2;
    DataWrite(b);
   
   
     delay(dly);}
     DataWrite(0);
     delay(dly);
     return;
    case 8:
  a=1;
b=128;

 for(int i=0;i<4;i++){
  c=a+b;
    DataWrite(c);
    a=a*2;
b=b/2;
     delay(dly);
 }
  
     return;
   case 9:
    a=16;
 b=8;
 for(int i=0;i<4;i++){
   c=a+b;
    DataWrite(c);
      a=a*2;
b=b/2;
     delay(dly);}
      
     return;
    case 10:
  a=1;
b=128;

 for(int i=0;i<7;i++){
  c=a+b;
    DataWrite(c);
    a=a*2;
b=b/2;
if(i==3){  a=a*2;
b=b/2;}
     delay(dly);
 }
  
     return;
    case 11:
  a=1;
b=128;

 for(int i=0;i<8;i++){
  c=a+b;
    DataWrite(c);
    a=a*2;
b=b/2;
if(i>3){ 
  DataWrite(0);
   delay(dly/10); 
   DataWrite(c);
   delay(dly/10); 
   DataWrite(0);
    delay(dly/10); 
   DataWrite(c);
}
     delay(dly);
 }
  DataWrite(0);
    delay(dly);
     return;
  case 12:
  

 for(int j=8;j>0;j--){
  a=1;
 for(int i=0;i<j;i++){
  c=a+b;
    DataWrite(c);
    a=a*2;
     delay(dly);
 }
b=c;
}
a=b=c=0;
DataWrite(0);
     delay(dly);
     return;
       case 13:
  

 for(int j=8;j>0;j--){
  a=128;
 for(int i=0;i<j;i++){
  c=a+b;
    DataWrite(c);
    a=a/2;
     delay(dly);
 }
b=c;
}
a=b=c=0;
DataWrite(0);
     delay(dly);
     return;
     //-----------
     }
 }
   
    
   
 



void DataWrite(int value){
  
   digitalWrite(1,LOW); //latch pin low
 
    delay(1);
shiftOut(2,0,MSBFIRST,value); 

digitalWrite(1,HIGH); //latch pin low
}
