#include <MaxMatrix.h>
#include <Keypad.h>

const byte FILAS = 4; //Filas
const byte COLUMNAS = 4; //Columnas

int data = 11;
int load = 12;
int clock = 13;
int maxInUse = 1; //Establece el numero de MAX7219 usas
MaxMatrix m(data, load, clock, maxInUse);
int posx=4;
int posy=4;
byte CAJA []  =  { 
  3 ,  8 , B110 , B011 , B110 }; 

//Definir los simbolos en los botones del keypad(Teclado 4x4)
char hexaKeys[FILAS][COLUMNAS] = {
  {  '1','2','3','A'  },
  {  '4','5','6','B'  },
  {  '7','8','9','C'  },  
  {  '*','0','#','D'  }
};
byte pinesFila[FILAS] = {
  9, 8, 7, 6 }; //connect to the row pinouts of the keypad
byte pinesColumna[COLUMNAS] = {
  5, 4, 3, 2 }; //connect to the column pinouts of the keypad

Keypad k = Keypad(makeKeymap(hexaKeys), pinesFila, pinesColumna, FILAS, COLUMNAS); 

boolean flag=true;

void setup()
{
  m.init();
  m.setIntensity(12);
  Serial.begin(9600);
}

void loop()
{
  m.clear();
  char aux=k.getKey();
  
  switch(aux){
    case '2':
      posy--;
      detectar_limite();
      break;
    case '8':
      posy++;
      detectar_limite();
      break;
    case '4':
      posx--;
      detectar_limite();
      break;
    case '6':
      posx++;
      detectar_limite();
      break;  
  }
  m.writeSprite(posx,posy,CAJA);
}

void detectar_limite(){
  if(posx>5){
    posx=5;
    return;
  }
  if(posx<0){
    posx=0;
    return;
  }
  if(posy>5){
    posy=5;
    return;
  }
  if(posy<0){
    posy=0;
    return;
  }
}

void mostrar_cambio(){
  Serial.print("pos x=");
  Serial.print(posx);
  Serial.print(":");
  Serial.print("pos y=");
  Serial.println(posy);
}



