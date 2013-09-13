const byte boton=9;

byte estado=1;

int posicion=0;

void setup(){
  pinMode(boton, INPUT);
  DDRD=255;
  /*for(byte i=0;i<8;i++){
   pinMode(i, OUTPUT);
   }*/
  digitalWrite(posicion,HIGH);
}

void loop(){
  estado=digitalRead(boton);
  if(!estado){
    digitalWrite(posicion,LOW);
    posicion++;
    if(posicion>7){
      posicion=0;
    }
    digitalWrite(posicion,HIGH);
    delay(20);
    while(!digitalRead(boton));
  }
}



