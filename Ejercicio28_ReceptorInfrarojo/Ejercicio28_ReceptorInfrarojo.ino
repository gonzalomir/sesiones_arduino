#include <IRremote.h>

const int PIN_RECEPTOR = 11;

IRrecv irrecv(PIN_RECEPTOR);

decode_results results;

void setup()
{
  pinMode(10,OUTPUT);
  digitalWrite(10,LOW);
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);

  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
}

