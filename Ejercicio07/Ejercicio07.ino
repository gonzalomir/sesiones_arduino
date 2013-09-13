#define pinLDR 0

int valLDR=0;  //int 16 bits
byte salida=0;

void setup(){
  DDRD=255;  //B11111111
}

void loop(){
  valLDR=analogRead(pinLDR);
  salida=map(valLDR,0,1023,0,255);
  PORTD=salida;
}


