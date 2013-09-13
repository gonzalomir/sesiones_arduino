const byte pinLDR=0;

int valLDR=0;  //int 16 bits
byte valor=0;

void setup(){
  DDRD=255;  //B11111111
}

void loop(){
  valLDR=analogRead(pinLDR);
  valor=map(valLDR,0,1023,0,7);
  for(byte i=0;i<valor;i++){
    digitalWrite(i,HIGH);
  }
  delay(100);
  PORTD=0;
}


