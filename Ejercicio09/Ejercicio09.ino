const byte motor=2;

void setup(){
  pinMode(motor,OUTPUT);
}

void loop(){
  analogWrite(motor,0);
  delay(3000);
  analogWrite(motor,127);
  delay(1000);
  analogWrite(motor,255);
  delay(1000);  
  analogWrite(motor,63);
  delay(3000);  
  
}

