const byte pines[4]={
  6,7,10,11};
const byte pasos[8]={
  1,3,2,6,4,12,8,9};
char indice=0;
/*
 Primer paso  3=0011
 Segundo paso 6=0110
 Tercer paso 12=1100
 Cuarto paso  9=1001
 */

void setup(){
  for(int i=0;i<4;i++){
    pinMode(pines[i],OUTPUT);
  }
}

void loop(){
  avanzar(12, 333);
  delay(1000);
  retroceder(6,333);
  delay(2500);
}

void avanzar(int num_pasos,int delay_paso){
  for(int i=0;i<num_pasos;i++){
    writeMotor();
    delay(delay_paso);
    indice++;
    if(indice>7){
      indice=0;
    }
  }
}

void retroceder(int num_pasos,int delay_paso){
  for(int i=0;i<num_pasos;i++){    
    writeMotor();
    delay(delay_paso);
    indice--;
    if(indice<0){
      indice=7;
    }
  }
}

void writeMotor(){
  boolean aux=false;
  for(int i=0;i<4;i++){
    aux=bitRead(pasos[indice],i); //lee un bit del vector pasos
    digitalWrite(pines[i],aux);   //escribe es bit en un pin del motor
  }
}


