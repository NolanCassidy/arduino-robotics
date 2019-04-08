#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX

void setup() 
{
    BTserial.begin(9600);  
}
 
void loop()
{
  //if(BTserial.available()) {
    BTserial.print(1);
    BTserial.print(':');
    BTserial.println(analogRead(0));
    BTserial.print(2);
    BTserial.print(':');
    BTserial.println(analogRead(1));
  //}
}
