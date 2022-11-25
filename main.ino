#define EN0 3
#define L1 4 
#define L2 5 

#define EN1 11
#define L3 12
#define L4 13

#define S1 6
#define S2 7
#define S3 8
#define S4 9
#define S5 10
void setup(){
  Serial.begin(9600);
  //Primeiro motor
  pinMode(EN0, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);

  //Segundo motor
  pinMode(EN1, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);

  //SENSORES
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
}

void andarReto(){
  analogWrite(EN1, 90);
  digitalWrite(L3, LOW);
  digitalWrite(L4, HIGH);
  
  analogWrite(EN0, 90);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  }

void andarDireita(){
  analogWrite(EN1, 88);
  digitalWrite(L3, LOW);
  digitalWrite(L4, HIGH);
  
  analogWrite(EN0, HIGH);
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  }

  
void andarEsquerda(){
  analogWrite(EN1, HIGH);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);
  
  analogWrite(EN0, 88);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  }
void parar(){
  digitalWrite(EN1, HIGH);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);
  
  digitalWrite(EN0, HIGH);
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  
}

void loop(){
  int sensor_1 = digitalRead(S1);
  int sensor_2 = digitalRead(S2);
  int sensor_3 = digitalRead(S3);
  int sensor_4 = digitalRead(S4);
  int sensor_5 = digitalRead(S5);

  if(sensor_1 == 0 and sensor_2 == 0 and sensor_3 == 1 and sensor_4 == 0 and sensor_5 == 0){
    andarReto();}
    
  else if(sensor_1 == 0 and sensor_2 == 1 and sensor_3 == 0 and sensor_4 == 0 and sensor_5 == 0){
    andarEsquerda();}

  else if(sensor_1 == 1 and sensor_2 == 0 and sensor_3 == 0 and sensor_4 == 0 and sensor_5 == 0){
      andarEsquerda();}

  else if(sensor_1 == 0 and sensor_2 == 1 and sensor_3 == 1 and sensor_4 == 0 and sensor_5 == 0){
      andarEsquerda();}

  else if(sensor_1 == 1 and sensor_2 == 1 and sensor_3 == 0 and sensor_4 == 0 and sensor_5 == 0){
      andarEsquerda();}
  
  else if(sensor_1 == 0 and sensor_2 == 0 and sensor_3 == 0 and sensor_4 == 1 and sensor_5 == 0){
    andarDireita();}

  else if(sensor_1 == 0 and sensor_2 == 0 and sensor_3 == 0 and sensor_4 == 0 and sensor_5 == 1){
      andarDireita();}

  else if(sensor_1 == 0 and sensor_2 == 0 and sensor_3 == 1 and sensor_4 == 1 and sensor_5 == 0){
      andarDireita();}

  else if(sensor_1 == 0 and sensor_2 == 0 and sensor_3 == 0 and sensor_4 == 1 and sensor_5 == 1){
      andarDireita();}
  
  else if(sensor_1 == 1 and sensor_2 == 1 and sensor_3 == 1 and sensor_4 == 1 and sensor_5 == 1){
    parar();}
}
