#include <Arduino.h>

#define mn   2
#define ent  3   // funcionnamiento manual o app
#define sen  4   //Sensor de Temperatura
#define bos  5   //Bosina 
#define ret  6   //Rele resistencia
#define dis  7   //Rele disipador 
float mx = 34;
int fn = 0;
int pinLed=2;
int n=2,c,d,i ;

void setup() {
Serial.begin (9600);
pinMode  (mn   , INPUT );
pinMode  (ent  , INPUT );
pinMode  (sen  , INPUT );
pinMode  (bos  , OUTPUT );
pinMode  (ret  , OUTPUT );
pinMode  (dis  , OUTPUT );
pinMode  (pinLed, OUTPUT);
Serial.print ("Ensendido:");
c=5;
}
void loop() {
 if (digitalRead( ent) == HIGH ) //Definir como va a funcionar manual o app
  { 
    fn = 1 ;
  }
 else if (digitalRead(mn)== HIGH )
  {
    fn = 2 ;
  }
switch (fn){
 case 1 : // Funcionamiento manual 
  while (sen < mx )   //funciona hasta que la sen no supere la temperatura 
  { digitalWrite ( ret , HIGH );
    delay (3500);
    digitalWrite ( ret , LOW );
    delay (1500);
    Serial.println("Claentando...");
  }
  while(sen > mx ) //estado de espera 
  {
    digitalWrite ( dis , HIGH );
    delay (2500);
    digitalWrite ( dis , LOW );
    Serial.println("Listo.");
  }
  break;
 case 2 :  // Fucinamiento Remoto 
  Serial.print("Remoto");
  break;
 default: // Error de funcionamiento 
 Serial.print("Error");
 
 return;// salir del  selector 
 break;
}
  n += 3;
  c += 2,

  digitalWrite (pinLed, HIGH);
   Serial.print ("ON, ");
   delay (1000);
  
  digitalWrite (pinLed, LOW);
   Serial.println ("OFF");
   delay(1000);
}