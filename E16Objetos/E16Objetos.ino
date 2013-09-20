#include "MotorPAP.h"

MotorPAP m1;
MotorPAP m2;
MotorPAP m3;

void setup(){
  m1.setPines(0,1,2,3);
  m1.setPasoSimple();
  m2.setPines(4,5,6,7);
  m2.setPasoDoble();
  m3.setPines(8,9,10,11);
  m3.setPasoMedio();
  
}

void loop(){
  m1.avanzar(1,150);
  m2.retroceder(1,150);
  m3.retroceder(1,150);
}






