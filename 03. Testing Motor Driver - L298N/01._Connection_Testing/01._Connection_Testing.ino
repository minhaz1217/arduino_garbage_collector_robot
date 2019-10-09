
/* CONNECTION for LD298N
 * battery positive -> 12v
 * battery negative -> arduino ground
 * motor driver ground -> arduino ground
 * motor driver +5v -> arduino Vin
 * motor driver enaA -> arduino 2
 * motor driver in1 -> arduino 3
 * motor driver in2 -> arduino 4
 * motor driver in3 -> arduino 5
 * motor driver in4 -> arduino 6
 * motor driver enaB -> arduino 7
 */

int ENA = 2;
int ENB = 7;
int IN1 = 3;
int IN2 = 4;
int IN3 = 5;
int IN4 = 6;
int del = 500;
void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);

}

void CWA(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}
void CCWA(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void CWB(){
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void CCWB(){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void offA(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
void offB(){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void loop() {
  offA();
  offB();
  CWA();
  delay(del);
  offA();
  offB();
  CCWA();
  delay(del);
  offA();
  offB();
  CWB();
  delay(del);
  offA();
  offB();
  CCWB();
  delay(del);

/*
 * in1 = high, in2 low = clock wise
 * in1 = low, in2 high = counter clock wise
 */
  
}
