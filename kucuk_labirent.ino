#include "deneyap.h"
#include "ServoESP32.h"

#define servopin D0
#define servopin2 D1
Servo servo1;
Servo servo2;   
 
int ykonum;  
int y2konum;
int servoderece=90;
int servoderece2=90;

void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  servo1.attach(servopin);
  servo2.attach(servopin2);
  servo1.write(servoderece);  
  servo2.write(servoderece2);                                    
}

void loop() {
  ykonum = analogRead(A0);
  y2konum = analogRead(A1);
  if(ykonum<1000 && servoderece>0){
    servoderece = servoderece-1;
  } else if (ykonum>3500 && servoderece<180){
    servoderece = servoderece+1;
  } else if(y2konum<1000 && servoderece2>0){
    servoderece2 = servoderece2-1;
  } else if (y2konum>3500 && servoderece2<180){
    servoderece2 = servoderece2+1;
  }
  servo1.write(servoderece);
  servo2.write(servoderece2);
  delay(10);
}
