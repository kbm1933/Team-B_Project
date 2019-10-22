#include <Servo.h>
Servo servo;
int angle = 0;
int sw = 5;
void setup(){
  servo.attach(9);
  Serial.begin(9600);
  pinMode(sw,INPUT_PULLUP);
}

void loop(){
  if(digitalRead(sw) == LOW){
    angle +=30;
    if(angle >= 210){
      angle = 0;
      }
      servo.write(angle);
      delay(500);
    }
}
