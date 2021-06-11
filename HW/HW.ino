//SoftwareSerial BTSerial (10,11);
const int motorIn1=4;
const int motorIn2=5;
const int motorIn3=6;
const int motorIn4=7;
const int EnableA=2;
const int EnableB=3;
const int A_ledpin=8;
const int B_ledpin=9;
char F,L,B,R;
void setup() {
  // put your setup code here, to run once:
  pinMode(motorIn1,OUTPUT);
  pinMode(motorIn2,OUTPUT);
  pinMode(motorIn3,OUTPUT);
  pinMode(motorIn4,OUTPUT);
  pinMode(EnableB,OUTPUT);
  pinMode(EnableA,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0)
  {unsigned char charreceived=Serial.read();
    switch(charreceived)
    {
      case'F':
        Serial.println("Forward");
        analogWrite(EnableA,250);
        analogWrite(EnableB,250);
        digitalWrite(motorIn1,HIGH);
        digitalWrite(motorIn2,LOW);
        digitalWrite(motorIn3,HIGH);
        digitalWrite(motorIn4,LOW);
        delay(2000);
        break;
      case'L':
        Serial.println("Turn left");
        analogWrite(EnableA,250);
        digitalWrite(motorIn1,HIGH);
        digitalWrite(motorIn2,LOW);
        digitalWrite(motorIn3,LOW);
        digitalWrite(motorIn4,LOW);
        digitalWrite(A_ledpin,HIGH);
        delay(2000);
        break;
      case'R':
        Serial.println("Turn right");
        analogWrite(EnableA,250);
        digitalWrite(motorIn1,LOW);
        digitalWrite(motorIn2,LOW);
        digitalWrite(motorIn3,HIGH);
        digitalWrite(motorIn4,LOW);
        digitalWrite(B_ledpin,HIGH);
        delay(2000);
        break;
      case'B':
        Serial.println("Backward");
        analogWrite(EnableA,250);
        analogWrite(EnableB,250);
        digitalWrite(motorIn1,LOW);
        digitalWrite(motorIn2,HIGH);
        digitalWrite(motorIn3,LOW);
        digitalWrite(motorIn4,HIGH);
        digitalWrite(A_ledpin,HIGH);
        digitalWrite(B_ledpin,HIGH);
        delay(2000);
        break;
      
      default:
        break;
    }
Serial.flush();
delay(10);

}
}
