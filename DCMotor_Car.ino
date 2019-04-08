// pin 9 = BENBL
// pin 10 = BPHASE
// pin 11 = AENBL
// pin 12 = APHASE
// pin 13 = MODE

// Phase is a digital pin. Set it to LOW to go FORWARD. Set it to HIGH to go back

#include <Servo.h>
char INBYTE;
int servoPin = 5;
int servoPin2 = 8;
int modePin = 13;
int bEnable = 9;
int bPhase = 10;
int aEnable = 11;
int aPhase = 12;

void setup() {

Serial.begin(9600);
pinMode(modePin, OUTPUT);
pinMode(bEnable, OUTPUT);
pinMode(bPhase, OUTPUT);
pinMode(aPhase, OUTPUT);
pinMode(aEnable, OUTPUT);

}
void loop() {
  digitalWrite(modePin, HIGH);
Serial.println("W = Go Forward, A = Turn Left, D = Turn Right, S = Go Backwards, ");
 while (!Serial.available());
 INBYTE = Serial.read();
   if(INBYTE == 'w') {
      analogWrite(bEnable, 255);
      digitalWrite(bPhase, LOW);
      analogWrite(aEnable, 255);
      digitalWrite(aPhase, HIGH);
    }
    if(INBYTE == 's') {
    analogWrite(bEnable, 255);
      digitalWrite(bPhase, HIGH);
      analogWrite(aEnable, 255);
      digitalWrite(aPhase, LOW);
    }
      if(INBYTE == 'a') {
      analogWrite(bEnable, 255);
      digitalWrite(bPhase, HIGH);
      analogWrite(aEnable, 255);
      digitalWrite(aPhase, HIGH);
    }
      if(INBYTE == 'd') {
      analogWrite(bEnable, 255);
      digitalWrite(bPhase, LOW);
      analogWrite(aEnable, 255);
      digitalWrite(aPhase, LOW);
    }
      if(INBYTE == ' ') {
      analogWrite(bEnable, 0);
      digitalWrite(bPhase, LOW);
      analogWrite(aEnable, 0);
      digitalWrite(aPhase, LOW);
    }
}



