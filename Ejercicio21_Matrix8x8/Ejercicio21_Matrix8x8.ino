#include <MaxMatrix.h>

int data = 2;
int load = 3;
int clock = 4;
int maxInUse = 1; //Establece el numero de MAX7219 usas
MaxMatrix m(data, load, clock, maxInUse);
boolean flag=true;

void setup()
{
  m.init();
  m.setIntensity(10);
}

void loop()
{
  for(int j=0;j<8;j++){
    for(int i=0;i<8;i++){
      m.setDot(i,j,flag);
      delay(100);
    }
  }
  flag=!flag;
}




