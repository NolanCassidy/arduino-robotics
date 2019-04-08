//#include <Servo.h>
//
//Servo leftServo;
//Servo rightServo;
//
//
//void setup() {
//  // put your setup code here, to run once:
//leftServo.attach(10);
//rightServo.attach(9);
//
//Serial.begin(9600);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//int val = analogRead(0);
//Serial.println(val);
//
//
//leftServo.writeMicroseconds(1000);
//rightServo.writeMicroseconds(2000);
//delay(50);

#include<Servo.h>

Servo leftServoForward;
Servo leftServoBackward;

Servo rightServoForward;
Servo rightServoBackward;

void setup() {
  leftServoForward.attach(3);
  //leftServoBackward.attach(4);

  rightServoForward.attach(4);
  //rightServoBackward.attach(6);

  Serial.begin(9600);

  go_forward();
}

void loop() { 
/*
  leftServoForward.writeMicroseconds(1000);
  leftServoBackward.writeMicroseconds(2000);

  rightServoForward.writeMicroseconds(2000);
  rightServoBackward.writeMicroseconds(1000);
*/
  int dist1 = analogRead(4);
  Serial.print("Distance Reading: ");
  Serial.print(dist1);

  int dist2 = analogRead(5);
  Serial.print("    |     Distance2 reading: ");
  Serial.println(dist2);

  if (dist1 > 240) {
    delay(20);
     if (dist2 > 120) {         
      go_right();
    } else {
      go_left();
    }
  } else {
    go_forward();
  }
}
void go_forward() {
  leftServoForward.writeMicroseconds(2000);
  rightServoForward.writeMicroseconds(1000);
}

void go_right(){
  leftServoForward.writeMicroseconds(2000);
  rightServoForward.writeMicroseconds(2000);
  delay(500);
}

void go_left() {
  leftServoForward.writeMicroseconds(1000);
  rightServoForward.writeMicroseconds(1000);
  delay(500);

}

//}
