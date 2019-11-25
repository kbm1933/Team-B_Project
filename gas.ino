#include <Servo.h>
Servo servo;
int g_pin = A0;
int trig = 8;
int echo = 9;
int led = 6;
int angle = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(g_pin, INPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  servo.attach(7);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  digitalWrite(echo,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  unsigned long duration = pulseln(echo,HIGH);

  float distance = duration /29.0/2.0;

  Serial.print(distance);
  Serial.println("cm");

  if(distance<10){
    digitalWrite(led,HIGH);
    spin();
   }
   else{
    digitalWrite(led,LOW);
    }
  Serial.println(analogRead(g_pin));
  delay(200);

  
}

void spin(){
  for(angle = 0;angle <=180; angle += 1){
    servo.write(angle);
    delay(15);
    }

  for(angle = 180; angle >= 0; angle -=1){
    servo.write(angle);
    delay(15);
  }
}
