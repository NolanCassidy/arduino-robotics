#include <Servo.h>
char INBYTE;
int servoPin = 4;
int servoPin2 = 3;
Servo Servo1;
Servo Servo2;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Servo1.attach(servoPin);
Servo2.attach(servoPin2);

}
void loop() {
Serial.println("W = Go Forward A = Turn Left D = Turn Right S = Go Backwards");
 while (!Serial.available());
 INBYTE = Serial.read();
 if(INBYTE == 'w') {
    Servo1.writeMicroseconds(2000);
   Servo2.writeMicroseconds(1000);
  }
   if(INBYTE == 'a') {
    Servo1.writeMicroseconds(2000);
   Servo2.writeMicroseconds(1000);
  }
   if(INBYTE == 'd') {
    Servo1.writeMicroseconds(2000);
   Servo2.writeMicroseconds(1000);
  }
   if(INBYTE == 's') {
    Servo1.writeMicroseconds(2000);
   Servo2.writeMicroseconds(1000);
  }
  if(INBYTE == ' ') {
    Servo1.writeMicroseconds(1500);
   Servo2.writeMicroseconds(1500);
  }
}



