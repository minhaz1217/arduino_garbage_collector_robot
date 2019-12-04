#include<Servo.h>

/*  Micro Servo 9g, only good for 180 degree rotation.
 *  brown -> ground
 *  red -> +5
 *  orange -> 8
 */
 #define SERVO_PORT 8

Servo servo;
void setup() {
  servo.attach(SERVO_PORT);
  servo.write(0);
}

void loop() {
  int del = 1000;
  servo.write(0);
  delay(del);
  servo.write(180);
  delay(del);
}
