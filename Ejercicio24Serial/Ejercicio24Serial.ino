const int LED0=2;
int datoEntrante=0;

void setup(){
  Serial.begin(9600);
  Serial.println("Hola Mundo");
  pinMode(LED0,OUTPUT);
}

void loop(){
  if(Serial.available()>0){
    datoEntrante=Serial.read();
    if(datoEntrante==49){
      digitalWrite(LED0,HIGH);
    }  
    if(datoEntrante==50){
      digitalWrite(LED0,LOW);
    }  
  }
}

