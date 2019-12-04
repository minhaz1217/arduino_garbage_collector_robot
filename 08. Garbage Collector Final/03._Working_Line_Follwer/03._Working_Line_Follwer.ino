/* Building the main line follower robot 
 *  
 *  
 */
#define INPUTSIZE 500

#define ENA 5
#define ENB 6
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 7
#define del 300
int mx[5], mn[5], TH = 900;
long long int sum[5];
int counter = 0;
char bfr[300];
bool outputted = 0,lightOn;
int BT[5] = {TH, TH, TH, TH, TH}; // black threashhold for the IR sensors, greater than this value means the ir is on black line
int data[5], myStep, correction;
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
  analogWrite(ENA,500);
  analogWrite(ENB,500);
  digitalWrite(13, LOW);
  TH = 930;
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
bool detected(int pos){
  return data[pos-1]>= BT[pos-1];
}
void currentStep(){
  if(myStep == 1){
    goLeft();
  }else if(myStep == 2){
    goRight();
  }else if(myStep == 3){
    goBack();
  }else{
    myStep = 1;
  }
}
void loop() {
  data[0] =analogRead(A0);
  analogWrite(ENA, data[0]);
  analogWrite(ENB, data[0]); 
  data[1] =analogRead(A1); 
  data[2] =analogRead(A2); 
  data[3] =analogRead(A3); 
  data[4] =analogRead(A4); 
  delay(10);
  sprintf (bfr, "Output %d: %d %d %d %d %d",counter, data[0], data[1], data[2], data[3], data[4]);
  Serial.println (bfr);
  if(data[3] > TH || data[2] > TH){
    goFront();
    digitalWrite(13, LOW);
    Serial.println ("FRONT");
  }else if(data[4] > TH){
    goLeft();
    digitalWrite(13, LOW);
    
    Serial.println ("Left");
  }else if(data[1] > TH){
    goRight();
    digitalWrite(13, LOW);
    Serial.println ("Right");
  }else{
    goBack``````````````````````````````````````````();
    digitalWrite(13, HIGH);
    Serial.println ("STOP");
  }
  delay(50);
}
