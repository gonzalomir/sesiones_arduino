const int NUM_74LS595=3;
const int PIN_CLOCK=13;  //Pin reloj
const int PIN_DATA=11;   //Pin de datos
const int PIN_LATCH=2;   //Pin latch

byte puerto[NUM_74LS595];

void setup(){
  pinMode(PIN_CLOCK,OUTPUT);
  pinMode(PIN_DATA,OUTPUT);
  pinMode(PIN_LATCH,OUTPUT);
  puerto[0]=0;
  puerto[2]=0;
}

void loop(){
  actualizar595();
  delay(1000);
  puerto[0]++;
  puerto[1]=random(0,255);
  puerto[2]++;
}

void actualizar595(){
  digitalWrite(PIN_LATCH,HIGH);
  for(int i=0;i<NUM_74LS595;i++){
    shiftOut(PIN_DATA,PIN_CLOCK,MSBFIRST,puerto[i]);
  }
  digitalWrite(PIN_LATCH,LOW);
}


