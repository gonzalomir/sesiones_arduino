const byte motor=9;
const byte sensor=3;
int valor=0;
byte valor_map=0;

void setup(){
  //pinMode(motor,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  valor=analogRead(sensor);  
  valor_map=map(valor,0,600,0,255);
  Serial.println(valor);
  analogWrite(motor,valor_map);
  delay(50);
}

