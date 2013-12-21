const int led=13;
boolean estado=false;

void setup(){
  pinMode(led,OUTPUT);
  attachInterrupt(0,iniciar_parpadeo, FALLING);
  attachInterrupt(1,parar_parpadeo, RISING);
}

void loop(){
  if(estado){
    parpadear();
  }
}

void iniciar_parpadeo(){
  estado=true;
}

void parar_parpadeo(){
  estado=false;
}

void parpadear(){
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
  delay(500);
}






