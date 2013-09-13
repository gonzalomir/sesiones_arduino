#define boton 9

int direccion=0;
int posicion=0;

void setup(){
  pinMode(boton, INPUT);
  for(byte i=0;i<8;i++){
    pinMode(i, OUTPUT);
  }
}

void loop(){
  direccion=digitalRead(boton);
  if(direccion==0){
    direccion=1-direccion;
  }
  digitalWrite(posicion,HIGH);
  delay(120);
  digitalWrite(posicion,LOW);
  
  if(direccion==1){
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

}


