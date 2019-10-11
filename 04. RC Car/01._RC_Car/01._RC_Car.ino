
int ENA = 2;
int ENB = 7;
int IN1 = 3;
int IN2 = 4;
int IN3 = 5;
int IN4 = 6;
int del = 5;
char c;
bool lightOn = 0;
void setup() {
  Serial.begin(9600);
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
  if(Serial.available()){
    c = Serial.read();
    if(c == 'F'){
      goFront();
      delay(del);
    }else if(c == 'B'){
      goBack();
      delay(del);
    }else if(c == 'R'){
      goRight();
      delay(del);
    }else if(c == 'L'){
      goLeft();
      delay(del);
    }else if(c == 'W'){
      if(lightOn){
        digitalWrite(13, LOW);
        lightOn = 0;
      }else{
        digitalWrite(13, HIGH);
        lightOn = 1;
      }
    }else{
      goStop();
    }
  }else{
    goStop();
  }
  
}
