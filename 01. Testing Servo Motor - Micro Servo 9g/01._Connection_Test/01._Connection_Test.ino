#include<Servo.h>

/*  Micro Servo 9g, only good for 180 degree rotation.
 *  brown -> ground
 *  red -> +5
 *  orange -> 8
 */

Servo servo;
void setup() {
  servo.attach(8);
  servo.write(0);
}

void loop() {
  int del = 500;
  servo.write(0);
  delay(del);
  servo.write(45);
  delay(del);
  servo.write(90);
  delay(del);
  servo.write(135);
  delay(del);
  servo.write(180);
  delay(del);
}
