#include <Servo.h>
char INBYTE;
int FrontLeftServoPin = 7;
int FrontRightServoPin = 6;
int BackLeftServoPin = 5;
int BackRightServoPin = 4;

Servo FrontLeftServo;
Servo FrontRightServo;
Servo BackLeftServo;
Servo BackRightServo;

void setup() {

Serial.begin(9600);
FrontLeftServo.attach(FrontLeftServoPin);
FrontRightServo.attach(FrontRightServoPin);
BackLeftServo.attach(BackLeftServoPin);
BackRightServo.attach(BackRightServoPin);
}
void loop() {
Serial.println("W = Go Forward, A = Turn Left, D = Turn Right, S = Go Backwards, ");
 while (!Serial.available());
 INBYTE = Serial.read();
   if(INBYTE == 'w') {
      FrontLeftServo.writeMicroseconds(2000);
      FrontRightServo.writeMicroseconds(1000);
      BackLeftServo.writeMicroseconds(2000);
      BackRightServo.writeMicroseconds(1000);              
    }
    if(INBYTE == 's') {
      FrontLeftServo.writeMicroseconds(1000);
      FrontRightServo.writeMicroseconds(2000);
      BackLeftServo.writeMicroseconds(1000);
      BackRightServo.writeMicroseconds(2000);
    }
      if(INBYTE == 'd') {
      FrontLeftServo.writeMicroseconds(2000);
      FrontRightServo.writeMicroseconds(2000);
      BackLeftServo.writeMicroseconds(2000);
      BackRightServo.writeMicroseconds(2000);
    }
      if(INBYTE == 'a') {
      FrontLeftServo.writeMicroseconds(1000);
      FrontRightServo.writeMicroseconds(1000);
      BackLeftServo.writeMicroseconds(1000);
      BackRightServo.writeMicroseconds(1000);               
    }
      if(INBYTE == ' ') {
      FrontLeftServo.writeMicroseconds(1500);
      FrontRightServo.writeMicroseconds(1500);
      BackLeftServo.writeMicroseconds(1500);
      BackRightServo.writeMicroseconds(1500);
    }
}
//int val = 180;
///Servo1.write(val);
//int val1 = -180;
//Servo2.write(val1);


