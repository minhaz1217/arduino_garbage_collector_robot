void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);  
}

char c;
void loop(){
  if(Serial.available()){
    c = Serial.read();
    if(c == '1'){
      digitalWrite(LED_BUILTIN, LOW);
    }else{
      digitalWrite(LED_BUILTIN, HIGH);
    }
    Serial.println(c);
  }  
}
