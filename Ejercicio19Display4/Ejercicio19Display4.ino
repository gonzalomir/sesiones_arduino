#include <TimerOne.h>
const int NUM_DIGITOS=4;

byte indice=0;
int numero=0;

byte pin_display[4]={8,9,10,11}; //pines de control de cada display
byte digito[16];  //Coleccion de caracteres
byte num_descompuesto[4];

void setup(){
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  cargar_digitos();
  DDRD=255;
  Timer1.initialize(1500); // Expresion en microsegundos
  Timer1.attachInterrupt(updateDisplay);

}

void loop(){
  for(int i=0;i<10000;i++){
    writeNumero(i);
    delay(100);
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


void updateDisplay(){
  digitalWrite(pin_display[0],LOW);
  digitalWrite(pin_display[1],LOW);  
  digitalWrite(pin_display[2],LOW);  
  digitalWrite(pin_display[3],LOW);

  digitalWrite(pin_display[indice],HIGH);
  PORTD=digito[num_descompuesto[indice]];
  indice++;
  if(indice==NUM_DIGITOS){
    indice=0;
  }
}

void writeNumero(int num){
  int aux;
  numero=num;
  for(int i=0;i<NUM_DIGITOS;i++){
    aux=numero%10;
    numero=(numero-aux)/10;
    num_descompuesto[i]=aux;
  }
}



