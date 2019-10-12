/* Taking data and seeing their minimum, maximum and average
 *  
 *  Description: In this sketch we take inppts from the ir array consisting of 5 IR sensors  and take their data for INPUTSIZE rotations and check this data's properties.
 *              This will help differenciading IR data on different colors like gray, brown , red etc.
 * 
 */
#define INPUTSIZE 500

#define ENA 2
#define ENB 7
#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
#define del 300

int mx[5], mn[5];
long long int sum[5];
int counter = 0;
char bfr[300];
bool outputted = 0,lightOn;
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(13, LOW);
  lightOn = 0;
  counter = 0;
  outputted = 0;
  for(int i=0;i<5;i++){
    mn[i] = 9999;
    mx[i] = 0;
    sum[i] = 0;
  }
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
void goOff(){
  offA();
  offB();
}
void goFront(){
  CWA();
  CWB();
}
void goBack(){
  CCWA();
  CCWB();
}

void goRight(){
  offA();
  CWB();
  CCWA();
}
void goLeft(){
  offB();
  CWA();
  CCWB();
}
void goStop(){
  offA();
  offB();
}

void loop() {
  int data[5];
  data[0] =analogRead(A0); 
  data[1] =analogRead(A1); 
  data[2] =analogRead(A2); 
  data[3] =analogRead(A3); 
  data[4] =analogRead(A4); 
  
  sprintf (bfr, "Output %d: %d %d %d %d %d",counter, data[0], data[1], data[2], data[3], data[4]);
  Serial.println (bfr);
  goStop();
  goFront();
  delay(del);
  goStop();
  goBack();
  delay(del);
  goStop();
  delay(del);
  delay(100);
}
