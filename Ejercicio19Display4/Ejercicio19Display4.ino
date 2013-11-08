#include <TimerOne.h>

byte digito[16];
char indice;
int numero=0;
int pin_display[4]={11,10,9,8};

void setup(){
  cargar_digitos();
  Timer1.initialize(10000); // Expresion en microsegundos
  Timer1.attachInterrupt(setNumero);
  DDRD=255;
}

void loop(){

  numero=random();
  delay(500);
}

void setNumero(){
  int aux;
  for(int i=0;i<4;i++){
    digitalWrite(pin_display[i],HIGH);
    aux=numero%10;
    PORTD=aux;
    numero=(numero-aux)/10;
    delay(16);
    digitalWrite(pin_display[i],LOW);
  }
  

}

void cargar_digitos(){
  digito[0]=B0111111;  //0
  digito[1]=B0000110;  //1
  digito[2]=B1011011;  //2
  digito[3]=B1001111;  //3
  digito[4]=B1100110;  //4
  digito[5]=B1101101;  //5
  digito[6]=B1111101;  //6
  digito[7]=B0000111;  //7
  digito[8]=B1111111;  //8
  digito[9]=B1101111;  //9
  digito[10]=B1110111; //A
  digito[11]=B1111100; //B
  digito[12]=B0111001; //C
  digito[13]=B1011110; //D
  digito[14]=B1111001; //E
  digito[15]=B1110001; //F
}
