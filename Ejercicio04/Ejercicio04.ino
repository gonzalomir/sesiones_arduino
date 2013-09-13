const int boton1=9;
const int boton2=10;

boolean estado_boton1=0;
boolean estado_boton2=0;

int posicion=0;

void setup(){
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  DDRD=255;
  digitalWrite(posicion,HIGH);
}

void loop(){
  estado_boton1=digitalRead(boton1);
  estado_boton2=digitalRead(boton2);
  //Boton 1
  if(!estado_boton1 || !estado_boton2){
    digitalWrite(posicion,LOW);
    if(!estado_boton1){
      posicion++;
    }
    else{
      posicion--;
    }
    if(posicion>7){
      posicion=0;
    }
    if(posicion<0){
      posicion=7;
    }
    digitalWrite(posicion,HIGH);
    delay(20);
    while(!digitalRead(estado_boton1) || !digitalRead(estado_boton2));
  }
}


