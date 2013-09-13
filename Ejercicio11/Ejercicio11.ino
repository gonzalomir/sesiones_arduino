const byte motorP1=6;
const byte motorP2=7;

void setup(){
  pinMode(motorP1,OUTPUT);
  pinMode(motorP2,OUTPUT);
}

void loop(){
  avanzar(1500);
  parar();
  retroceder(2500);
}

void avanzar(int tiempo){
  digitalWrite(motorP1,HIGH);
  digitalWrite(motorP2,LOW);
  delay(tiempo);
}

void retroceder(int tiempo){
  digitalWrite(motorP1,LOW);
  digitalWrite(motorP2,HIGH);
  delay(tiempo);
}

void parar(){
  digitalWrite(motorP1,LOW);
  digitalWrite(motorP2,LOW);
}

