#include <Servo.h>
#include <SimpleTimer.h>
Servo servo;
SimpleTimer timer;
int angle = 0;
int inputPin = 2;
int inputPin2 = 3;
int val = 0;
int val2 = 0;
int pinState = LOW;
int pinState2 = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT);
  pinMode(inputPin2,INPUT);
  servo.attach(9);
  Serial.begin(9600);
  timer.setInterval(15000, spin);
}

void loop() {
  // put your main code here, to run repeatedly:

  val = digitalRead(inputPin);
  val2 = digitalRead(inputPin2);
  if (val == HIGH && val2 == HIGH) {
    if (pinState == LOW) {
      Serial.println("No Fire");
      pinState = HIGH;
      
      timer.run();
    }
  } else {
    if (pinState == HIGH) {
      Serial.println("Fire");
      pinState = LOW;
      
    }
  }


  delay(100);
  
  //spin();
}
