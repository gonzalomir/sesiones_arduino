import processing.serial.*;

Serial miPuerto;  // Create object from Serial class
int val;  
int x=127;
int y=127;
int z=127;

void setup()
{
  size(250, 250);
  String portName = Serial.list()[0];
  miPuerto = new Serial(this, portName, 9600);
  println("Conectando con Arduino al puerto"+miPuerto);
}

void draw()
{
  background(x, y, z);
  if (miPuerto.available() > 0) {  // If data is available,
    val = miPuerto.read();         // read it and store it in val
    if (val>32) {
      val=val-48;
      println(val);
      switch(val) {
      case 1:
        x=x+10;
        break;
      case 4:
        x=127;
        break;
      case 7:
        x=x-10;
        break;
      case 2:
        y=y+10;
        break;
      case 5:
        y=127;
        break;
      case 8:
        y=y-10;
        break;
      case 3:
        z=z+10;
        break;
      case 6:
        z=127;
        break;
      case 9:
        z=z-10;
        break;
      }
    }
  }
  //Fin  
}


