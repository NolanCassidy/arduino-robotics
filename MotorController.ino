
#include<Servo.h>

Servo myServo;
Servo wristServo;
int vals[10];
int wrist[10];
int average = 0;
int wristAvg = 0;

int MAXVAL = 2300;
int MINVAL = 800;

int res = 10;

void setup() {
  myServo.attach(9);
  wristServo.attach(10);
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int i = 0; i < 10; i++) {
    vals[i] = 0;
    wrist[i] = 0;
  }
}

void loop() {

  for (int i = 9; i > 0; i--) {
    vals[i] = vals[i-1];
    wrist[i] = wrist[i-1];
  }
  vals[0] = analogRead(0);
  wrist[0] = analogRead(1);

  for (int i = 0; i < 10; i++) {
    average += vals[i];
    wristAvg += wrist[i];
  }

  average /= 40;
  wristAvg /= 40;
  
  //Serial.println(average - 5);

  int serVal = map((int)(average/res)*res,0,255,MINVAL,MAXVAL);
  serVal = min(max(serVal,MINVAL),MAXVAL);
  Serial.print((int)(serVal/res)*res);
  Serial.print("   |    ");
  int wristVal = map(wristAvg,0,255,MINVAL,MAXVAL);
  wristVal = min(max(wristVal,MINVAL),MAXVAL);
  Serial.println(wristVal);
  wristServo.writeMicroseconds(wristVal);
  myServo.writeMicroseconds(serVal);
}
