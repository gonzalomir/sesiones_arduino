/*
 d .gfedcba
 0 00111111
 1 00000110
 2 01011011
 3 01001111
 4 01100110
 5 01101101
 6 01111101
 7 00000111
 8 01111111
 9 01100111
 */

char digito[10]={
  B00111111,B00000110,B01011011,B01001111,B01100110,B01101101,B01111101,B00000111,B01111111,B01100111};
int btnArriba=9;
int btnAbajo=8;
int numero=0;

void setup(){
  DDRD=B11111111;
  pinMode(btnArriba,INPUT);
  pinMode(btnAbajo,INPUT);
}

void loop(){
  PORTD=digito[numero];
  if(digitalRead(btnArriba)){
    arriba();   
    while(digitalRead(btnArriba));
  }
  if(digitalRead(btnAbajo)){
    abajo();   
    while(digitalRead(btnAbajo));
  }
}

void arriba(){
  numero++;
  if(numero==10)
    numero=0;
}

void abajo(){
  numero--;
  if(numero==-1)
    numero=9;
}
