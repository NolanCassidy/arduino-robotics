#include<Servo.h>

Servo leftServoForward;
Servo leftServoBackward;
Servo rightServoForward;
Servo rightServoBackward;
  
   void setup() {
  // put your setup code here, to run once:
leftServoForward.attach(10);
leftServoBackward.attach(11);
rightServoForward.attach(8);
rightServoBackward.attach(9);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  double dist = 1.0/analogRead(0) * 100;
  Serial.print("Distance to wall: ");
  Serial.println(dist);
  
leftServoForward.writeMicroseconds(2000);
leftServoBackward.writeMicroseconds(1000);
rightServoForward.writeMicroseconds(2000);
rightServoBackward.writeMicroseconds(1000);

}                                                                                          
    
