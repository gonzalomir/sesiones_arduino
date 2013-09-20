#include "Arduino.h"
#include "MotorPAP.h"

MotorPAP::MotorPAP(){
  indice=0;
}

void MotorPAP::setPines(byte a, byte b, byte c, byte d){
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pines[0]=a;
  pines[1]=b;
  pines[2]=c;
  pines[3]=d;
}

void MotorPAP::setPasoSimple(){
  pasos[0]=1;
  pasos[1]=2;
  pasos[2]=4;
  pasos[3]=8;
  tope=4;
  /*-----------------
   Primer paso  1=0001
   Segundo paso 2=0010
   Tercer paso  4=0100
   Cuarto paso  8=1000
   -----------------*/
}

void MotorPAP::setPasoDoble(){
  pasos[0]=3;
  pasos[1]=6;
  pasos[2]=12;
  pasos[3]=9; 
  tope=4;  
  /*-----------------
  Primer paso  3=0011
  Segundo paso 6=0110
  Tercer paso 12=1100
  Cuarto paso  9=1001
  -----------------*/
}

void MotorPAP::setPasoMedio(){
  pasos[0]=1;
  pasos[1]=3;
  pasos[2]=2;
  pasos[3]=6;
  pasos[4]=4;
  pasos[5]=12;
  pasos[6]=8;
  pasos[7]=9;
  tope=8;  
  /*-----------------
  Primer paso  1=0001
  Segundo paso 3=0011
  Tercer paso  2=0010
  Cuarto paso  6=0110
  Quinto paso  4=0100
  Sexto paso  12=1100
  Septimo paso 8=1000
  Octavo paso  9=1001
  -----------------*/
}

void MotorPAP::avanzar(int num_pasos,int delay_paso){
  for(int i=0;i<num_pasos;i++){
    writeMotor();
    delay(delay_paso);
    indice++;
    if(indice>=tope){
      indice=0;
    }
  }
}

void MotorPAP::retroceder(int num_pasos,int delay_paso){
  for(int i=0;i<num_pasos;i++){    
    writeMotor();
    delay(delay_paso);
    indice--;
    if(indice<0){
      indice=tope-1;
    }
  }
}

void MotorPAP::writeMotor(){
  boolean aux=false;
  for(int i=0;i<4;i++){
    aux=bitRead(pasos[indice],i); //lee un bit del vector pasos
    digitalWrite(pines[i],aux);   //escribe ese bit en un pin del motor
  }
}
