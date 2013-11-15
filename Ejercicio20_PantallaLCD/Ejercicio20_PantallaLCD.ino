#include <LiquidCrystal.h>
//  The circuit:
// * LCD RS pin to digital pin 12
// * LCD Enable pin to digital pin 11
// * LCD D4 pin to digital pin 5
// * LCD D5 pin to digital pin 4
// * LCD D6 pin to digital pin 3
// * LCD D7 pin to digital pin 2
// * LCD R/W pin to ground
// * 10K resistor:
// * ends to +5V and ground
// * wiper to LCD VO pin (pin 3)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int LM35=0;

void setup() {
  //analogReference(INTERNAL);
  pinMode(LM35,INPUT);
  lcd.begin(16, 2);
  lcd.print("Sensor LM35:");
}

void loop() {
  lcd.setCursor(13, 1);
  lcd.print("000");
  int temperatura = (5.0 * analogRead(LM35)*100.0)/1023.0; 
  if(temperatura<10)
    lcd.setCursor(15, 1);
  if(temperatura>9)
    lcd.setCursor(14, 1);
  if(temperatura>99)
    lcd.setCursor(13, 1);
  lcd.print(temperatura);
  delay(1500);
}




