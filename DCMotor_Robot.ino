int pin1 = 6;
int pin2 = 7;
int pin3 = 8;
int pin4 = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("Test");
  String readString = "";
  while (Serial.available()) {
    char c = Serial.read();  //gets one byte from serial buffer
    readString += c; //makes the string readString
    delay(2);  //slow looping to allow buffer to fill with next character
  }

  if (readString.length() > 0) {
   
    int n = readString.toInt();
     Serial.println(n); 
    if (n < 0) {
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, HIGH);
      analogWrite(pin1, -n);
      analogWrite(pin4, -n);
    } else {
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, HIGH);
      analogWrite(pin1, n);
      analogWrite(pin4, n);
    }
  }
}
