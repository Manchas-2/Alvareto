#include <Arduino.h>

#define ent 3
int pinLed=2;
int n=2,c,d,i ;

void setup() {
  pinMode  (ent, INPUT);
  pinMode  (pinLed, OUTPUT);
  Serial.begin (9600);
  Serial.print ("Estado:");
  c=5;
  if (n==c)
    {
      Serial.print("n es igual de c");
    }
  else{
    Serial.print ("n es diferente de c");
   }
}

void loop() {
  n += 3;
  c += 2,

  digitalWrite (pinLed, HIGH);
   Serial.print ("ON, ");
   delay (1000);
  
  digitalWrite (pinLed, LOW);
   Serial.println ("OFF");
   delay(1000);

  Serial.println (ent);
  if (n==c)
    {
      i -=1;
      Serial.print ("n es igual de c");
      Serial.println (i);
    }
  else{
    d += 1;
    Serial.print ("n es diferente de c");
    Serial.println (d);
   }
}

