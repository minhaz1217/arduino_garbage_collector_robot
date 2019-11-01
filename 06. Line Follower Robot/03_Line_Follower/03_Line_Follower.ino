/* Building the main line follower robot 
 *  A1 -> A5 = IR from car's RIGHT side to car's LEFT side
 *  A0 = Pottntiommter to control the IR's Threshhold
 *  LD298 connection 
 *  ENA
 */
#define INPUTSIZE 500
#define ENA 5
#define ENB 6
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 7
#define POTENTIOMETER A0
#define del 300
int mx[5], mn[5],poten, TH = 500;
long long int sum[5];
int counter = 0;
char bfr[300];
bool outputted = 0,lightOn;
int BT[5] = {TH, TH, TH, TH, TH}; // black threashhold for the IR sensors, greater than this value means the ir is on black line
int data[5], myStep, correction=1;


void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(POTENTIOMETER, INPUT);
  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(13, OUTPUT);
  analogWrite(ENA,120);
  analogWrite(ENB,120);
  digitalWrite(13, LOW);
  lightOn = 0;
  counter = 0;
  outputted = 0;
  myStep = 1;
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
bool detected(int pos){
  return data[pos-1]>= TH;
}
void currentStep(){
  if(myStep == 1){
    goBack();
  }else if(myStep == 2){
    goRight();
  }else if(myStep == 3){
    goLeft();
  }else{
    myStep = 1;
  }
}
void loop() {
  poten = analogRead(POTENTIOMETER);  
  TH = map(poten, 0,1000, 100, 1200);
  data[0] =analogRead(A5); 
  data[1] =analogRead(A4); 
  data[2] =analogRead(A3); 
  data[3] =analogRead(A2); 
  data[4] =analogRead(A1); 
  delay(10);
  counter++;
  sprintf (bfr, "Output %d: %d %d %d %d %d",counter, data[0], data[1], data[2], data[3], data[4]);
  Serial.println (bfr);
  Serial.println("Potentiometer: " + String(TH));
  goRight();
  if(detected(1) &&detected(2) &&detected(3) &&detected(4) &&detected(5) ){
    digitalWrite(LED_BUILTIN, LOW);
    goStop();
  }else if(detected(2) || detected(3) || detected(4)){
    digitalWrite(LED_BUILTIN, HIGH);
    goFront();
  }else if(detected(1) || detected(2)){
    digitalWrite(LED_BUILTIN, LOW);
    goStop();
    goLeft();
  }else if(detected(4) || detected(5)){
    digitalWrite(LED_BUILTIN, LOW);
    goStop();
    goRight();
  } else{
    digitalWrite(LED_BUILTIN, LOW);
    delay(10);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(10);
    correction++;
    if(correction%100){
      correction = 0;
      myStep++;
    }
    currentStep();
  }
}
