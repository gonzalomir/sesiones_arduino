#define led 13
#define boton 2

boolean estado=0;

void setup(){
  pinMode(led,OUTPUT);
  pinMode(boton,INPUT);
}

void loop(){
  estado = digitalRead(boton);
  if (estado) {     
    digitalWrite(led, HIGH);  
  } 
  else {
    digitalWrite(led, LOW); 
  }
}
