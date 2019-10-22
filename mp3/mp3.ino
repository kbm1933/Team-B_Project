#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
//SoftwareSerial mySerial(10,11);//RX, TX
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 // mySerial.begin(9600);
  mp3_set_serial(Serial);
  delay(1);
  mp3_set_volume(30);

}

void loop() {
  // put your main code here, to run repeatedly:
 mp3_play(1);
 delay(60000);
 mp3_next();
 delay(60000);
}
