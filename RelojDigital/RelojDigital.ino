#include <Time.h>
#include <TimeAlarms.h>

char aDigitos[10] = {
  B00111111,  //0
  B00000110,  //1
  B01011011,  //2
  B01001111,  //3
  B01100110,  //4
  B01101101,  //5
  B01111101,  //6
  B00000111,  //7
  B01111111,  //8
  B01100111}; //9

byte horas;
byte minutos;
byte segundos;

void setup() {
  DDRD=255;  //B11111111;
  DDRB=B111111;
  setTime(10,30,0,20,9,14);
}

void loop() {
  refrescarPantalla();
}

void refrescarPantalla(){
  horas=hour();
  minutos=minute();
  segundos=second();
  
  PORTB=0;
  PORTD=aDigitos[getDecenas(horas)];
  digitalWrite(8,HIGH);
  delay(2);
  PORTB=0;
  PORTD=aDigitos[getUnidades(horas)];
  digitalWrite(9,HIGH);
  delay(2);  
  PORTB=0;
  PORTD=aDigitos[getDecenas(minutos)];
  digitalWrite(10,HIGH);
  delay(2);
  PORTB=0;
  PORTD=aDigitos[getUnidades(minutos)];
  digitalWrite(11,HIGH);
  delay(2);
  PORTB=0;
  PORTD=aDigitos[getDecenas(segundos)];
  digitalWrite(12,HIGH);
  delay(2);
  PORTB=0;
  PORTD=aDigitos[getUnidades(segundos)];
  digitalWrite(13,HIGH);
  delay(2);
}

byte getUnidades(byte num){
  byte num2=(num/10)*10;
  return (num-num2);
}

byte getDecenas(byte num){
  return (num/10);
}


