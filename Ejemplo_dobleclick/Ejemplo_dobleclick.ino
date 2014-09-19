boolean estado;
int clicks;
int tiempoI=0,tiempoF=0;

void setup(){
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  clicks=0;
}

void loop(){
  int aux;
  if(digitalRead(2)){
    if(clicks==0)
      tiempoI=millis();
    if(clicks==1)
      tiempoF=millis();
    clicks++;
    while(digitalRead(2));
  }
  aux=tiempoF-tiempoI;
  if(aux>1000)
    clicks=0;
  if(aux<1000 && clicks==2){
    digitalWrite(3,estado);
    estado=!estado;
    clicks=0;
  }
}
