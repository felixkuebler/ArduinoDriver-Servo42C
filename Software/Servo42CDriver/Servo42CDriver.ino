#include <stdint.h>

#include <SoftwareSerial.h>

#include "Servo42CDriver.hpp"

SoftwareSerial mySerial(11, 12); // RX, TX
//Servo42CDriver servo(mySerial);
Servo42CDriver servo(mySerial, 0xE0, &Serial);

bool toggle = false;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  mySerial.begin(9600);

  Serial.println("StartupFinished");



}


void loop() { // run over and over

  //servo.moveSpeed(-100);
/*
  while(true) {
    double angle = 0;
    servo.readAngleEncoder(angle);
    Serial.print("Shaft Angle: ");
    Serial.println(angle);
  }
*/

  if (Serial.available()) {
    Serial.read();
    if (toggle) {
      servo.moveAngleRelative(-90, 50);
      /*
      delay(100);
      int32_t angle = 0;
      servo.readAngle(angle);
      */
    }
    else {
      servo.moveAngleRelative(90, -50);
      /*
      delay(100);
      double angle = 0;
      servo.readAngleEncoder(angle);
      Serial.print("Shaft Angle: ");
      Serial.println(angle); 
      */
      /*
      double angle = 0;
      servo.readAngleShaft(angle);
      Serial.print("Shaft Angle: ");
      Serial.println(angle);
      */
    }
    toggle = !toggle;
  }
  
  int32_t angle = 0;
  //servo.readAngle(angle);
  delay(100);
}
