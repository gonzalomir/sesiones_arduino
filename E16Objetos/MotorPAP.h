#ifndef MotorPAP_h
#define MotorPAP_h
#include "Arduino.h"

class MotorPAP{
private:
  byte pines[4];
  byte pasos[8];
  char indice;
  byte tope;
  void writeMotor();
public:
  MotorPAP();
  void setPines(byte a, byte b, byte c, byte d);
  void setPasoSimple();
  void setPasoDoble();
  void setPasoMedio();
  void avanzar(int num_pasos,int delay_paso);
  void retroceder(int num_pasos,int delay_paso);
};
#endif





