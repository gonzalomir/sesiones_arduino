#include <Servo.h> 

Servo servo1,servo2;

void setup() 
{ 
  servo1.attach(8);
  servo2.attach(9);
  servo1.write(0);
  servo2.write(0);
} 

void loop() {
  int val=analogRead(0);
  int servo_val=map(val,0,1023,1,180);
  servo1.write(servo_val);
  servo2.write(180-servo_val);
} 




