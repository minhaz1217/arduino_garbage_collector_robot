/* Trig -> 9
 *  Ekko -> 10
 * 
 * 
 */

#define TRIG 9
#define ECHO 10

int duration, distance;
void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delay(2);
  digitalWrite(TRIG, HIGH);
  delay(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = duration * .034/ 2; /// Converting the distance from Meter to CM. 340m/s air velocity.
  Serial.println(distance);

}
