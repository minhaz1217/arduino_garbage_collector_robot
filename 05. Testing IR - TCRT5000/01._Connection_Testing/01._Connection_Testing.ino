void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("ANALOG READ: " + analogRead(A0));
  int a1 = analogRead(A0);
  int a2 = analogRead(A1);
  int a3 = analogRead(A2);
  int a4 = analogRead(A3);
  int a5 = analogRead(A4);
  Serial.println( String(a1) + " "+ String(a2) + " "+ String(a3) + " "+ String(a4) + " "+ String(a5) );
  delay(200);
}
