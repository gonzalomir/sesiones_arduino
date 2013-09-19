const byte pines[4]={
  2,3,4,5};
const byte pasos[4]={
  1,2,4,8};
char indice=0;
/*
 Primer paso  1=0001
 Segundo paso 2=0010
 Tercer paso  4=0100
 Cuarto paso  8=1000
 */

void setup(){
  for(int i=0;i<4;i++){
    pinMode(pines[i],OUTPUT);
  }
}

void loop(){
  avanzar(12, 100);
  delay(1000);
  retroceder(6,180);
  delay(2500);
}

void avanzar(int num_pasos,int delay_paso){
  for(int i=0;i<num_pasos;i++){
    writeMotor();
    delay(delay_paso);
    indice++;
    if(indice>3){
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
      indice=3;
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

