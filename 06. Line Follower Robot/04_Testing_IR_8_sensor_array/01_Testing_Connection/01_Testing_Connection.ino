


void setup() {
  Serial.begin(9600);
  pinMode(A1, INPUT);  
}

void loop() {
  Serial.println(String(analogRead(A1)));
}
