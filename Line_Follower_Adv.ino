
#include<Servo.h>
Servo leftServoForward;
Servo rightServoForward;
int pin = 4;
int pin2 = 5;
int pin3 = 6;
int vccpin = 7;


void setup() {
  // put your setup code here, to run once:
  leftServoForward.attach(10);
  rightServoForward.attach(9);
  Serial.begin(9600);
  pinMode(vccpin, OUTPUT);
  digitalWrite(vccpin, HIGH);
  
}

void loop() {
int left = left_check(); 
Serial.print("Left: ");
Serial.print(left);

int mid = mid_check(); 
Serial.print("  |  Mid: ");
Serial.print(mid);

int right = right_check(); 
Serial.print("  |  Right: ");
Serial.println(right);


if (mid > 100) {
  go_forward();
} else {
  if (left > 200)  {
  go_left();
  }else { 
    if (right < 180 ) {
      go_right();
      
  }  
  }
}

}
int left_check() {
  int timer = 0;
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  delay(20);
  pinMode(pin, INPUT);
  while(digitalRead(pin) !=LOW) {
    timer += 1;
  }
  return timer;
}
int mid_check() {
  int timer = 0;
  pinMode(pin2, OUTPUT);
  digitalWrite(pin2, HIGH);
  delay(20);
  pinMode(pin2, INPUT);
  while(digitalRead(pin2) !=LOW) {
    timer += 1;
  }
  return timer;
}
int right_check() {
  int timer = 0;
  pinMode(pin3, OUTPUT);
  digitalWrite(pin3, HIGH);
  delay(20);
  pinMode(pin3, INPUT);
  while(digitalRead(pin3) !=LOW) {
    timer += 1;
  }
  return timer;
}

void go_forward() {
  leftServoForward.writeMicroseconds(2000);
  rightServoForward.writeMicroseconds(1000);
}

void go_left(){
  leftServoForward.writeMicroseconds(2000);
  rightServoForward.writeMicroseconds(2000);
}

void go_right() {
  leftServoForward.writeMicroseconds(1000);
  rightServoForward.writeMicroseconds(1000);

}
