/* Taking data and seeing their minimum, maximum and average
 *  
 *  Description: In this sketch we take inppts from the ir array consisting of 5 IR sensors  and take their data for INPUTSIZE rotations and check this data's properties.
 *              This will help differenciading IR data on different colors like gray, brown , red etc.
 * 
 */
#define INPUTSIZE 500
int mx[5], mn[5];
long long int sum[5];
int counter = 0;
char bfr[300];
bool outputted = 0;
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  counter = 0;
  outputted = 0;
  for(int i=0;i<5;i++){
    mn[i] = 9999;
    mx[i] = 0;
    sum[i] = 0;
  }
}

void loop() {
  int data[5];
  data[0] =analogRead(A0); 
  data[1] =analogRead(A1); 
  data[2] =analogRead(A2); 
  data[3] =analogRead(A3); 
  data[4] =analogRead(A4); 
  for(int i =0;i<5;i++){
    sum[i] += data[i];
    mx[i] = max(mx[i], data[i]);
    mn[i] = min(mn[i], data[i]);
  }
  counter++;
  if(outputted == 0 ){
    if(counter >= INPUTSIZE){
        for(int i=0;i<5;i++){
          int avg = sum[i]/counter;
          sprintf (bfr, "Sample data for %d -> Min: %d, Max: %d, Average: %d, Sum: %ld",i,mn[i],mx[i],avg, sum[i]);
          Serial.println (bfr);
        }
        outputted = 1;
      }else{
        sprintf (bfr, "Output %d: %d %d %d %d %d",counter, data[0], data[1], data[2], data[3], data[4]);
        Serial.println (bfr);
      //Serial.println( String(a1) + " "+ String(a2) + " "+ String(a3) + " "+ String(a4) + " "+ String(a5) );
    }
  }
  delay(100);
}
