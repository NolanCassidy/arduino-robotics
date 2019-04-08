#include<SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); // RX | TX

int val = 0;
int ad = 0;

void setup() 
{
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  
//    Serial.begin(9600);
//    Serial.println("Arduino with HC-06 is ready");
 
    // HC-06 default baud rate is 9600
    BTSerial.begin(9600);  
//    Serial.println("BTserial started at 9600");
}
 
void loop()
{
  char address[] = {' ',' ',' '};
  char value[] = {' ',' ',' ',' ',' '};
  while(!BTSerial.available());
  
  if (BTSerial.available()) {
    BTSerial.readBytesUntil(':', address, 3);
    BTSerial.readBytesUntil('\n', value, 5);
    //Serial.println(atoi(buffer));
    //Serial.println(val);
  }

  ad = atoi(address);
  val = map(atoi(value),0,1024,0,255);

  //Serial.println(ad+4);
  //Serial.print(':');
  //Serial.println(val);
  analogWrite(ad+4,val);
}
