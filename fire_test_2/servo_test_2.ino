
void spin(){
  for(angle = 0; angle <= 180; angle += 1){
      servo.write(angle);
      delay(15);
  }

  for(angle = 180; angle >= 0; angle -= 1){
    servo.write(angle);
    delay(15);
  }
}
