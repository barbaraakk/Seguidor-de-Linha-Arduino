//Ponte H:
//Motor 1
#define EN0 3
#define L1 4 
#define L2 5 

//Motor 2
#define EN1 11
#define L3 12
#define L4 13

//Sensores
#define S1 6
#define S2 7
#define S3 8
#define S4 9
#define S5 10

void setup(){
  Serial.begin(9600);
  
  //Motor 1
  pinMode(EN0, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);

  //Motor 2
  pinMode(EN1, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);

  //Sensores
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
}

//Anda para frente
void andarReto(){
  //Motor 1
  analogWrite(EN0, 90);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  
  //Motor 2
  analogWrite(EN1, 90);
  digitalWrite(L3, LOW);
  digitalWrite(L4, HIGH);
  }

//Anda para a direita
void andarDireita(){
  //Motor 1
  analogWrite(EN0, HIGH);
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  
  //Motor 2
  analogWrite(EN1, 88);
  digitalWrite(L3, LOW);
  digitalWrite(L4, HIGH);
  }

//Anda para a esquerda
void andarEsquerda(){
  //Motor 1
  analogWrite(EN0, 88);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  
  //Motor 2
  analogWrite(EN1, HIGH);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);
  }

//Parado
void parar(){
  //Motor 1
  digitalWrite(EN0, HIGH);
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  
  //Motor 2
  digitalWrite(EN1, HIGH);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);
}

void loop(){
  int sensor_1 = digitalRead(S1);
  int sensor_2 = digitalRead(S2);
  int sensor_3 = digitalRead(S3);
  int sensor_4 = digitalRead(S4);
  int sensor_5 = digitalRead(S5);

  //Anda para frente
  if(sensor_1 == 0 and sensor_2 == 0 and sensor_3 == 1 and sensor_4 == 0 and sensor_5 == 0){
    andarReto();}
    
  //Anda para a esquerda
  else if(sensor_1 == 0 and sensor_2 == 1 and sensor_3 == 0 and sensor_4 == 0 and sensor_5 == 0){
    andarEsquerda();}

  else if(sensor_1 == 1 and sensor_2 == 0 and sensor_3 == 0 and sensor_4 == 0 and sensor_5 == 0){
      andarEsquerda();}

  else if(sensor_1 == 0 and sensor_2 == 1 and sensor_3 == 1 and sensor_4 == 0 and sensor_5 == 0){
      andarEsquerda();}

  else if(sensor_1 == 1 and sensor_2 == 1 and sensor_3 == 0 and sensor_4 == 0 and sensor_5 == 0){
      andarEsquerda();}
  
  //Anda para a direita
  else if(sensor_1 == 0 and sensor_2 == 0 and sensor_3 == 0 and sensor_4 == 1 and sensor_5 == 0){
    andarDireita();}

  else if(sensor_1 == 0 and sensor_2 == 0 and sensor_3 == 0 and sensor_4 == 0 and sensor_5 == 1){
      andarDireita();}

  else if(sensor_1 == 0 and sensor_2 == 0 and sensor_3 == 1 and sensor_4 == 1 and sensor_5 == 0){
      andarDireita();}

  else if(sensor_1 == 0 and sensor_2 == 0 and sensor_3 == 0 and sensor_4 == 1 and sensor_5 == 1){
      andarDireita();}
  
  //Para
  else if(sensor_1 == 1 and sensor_2 == 1 and sensor_3 == 1 and sensor_4 == 1 and sensor_5 == 1){
    parar();}
}
