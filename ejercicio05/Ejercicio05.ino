#define boton 12

int posicion=0;

void setup(){
  pinMode(boton, INPUT);
  for(byte i=0;i<8;i++){
    pinMode(i, OUTPUT);
  }
}

void loop(){

  digitalWrite(posicion,HIGH);
  delay(250);
  digitalWrite(posicion,LOW);
  posicion++;
  if(posicion==8){
    posicion=0;  
  }
}


