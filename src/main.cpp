#include <Arduino.h>
#include <OneWire.h> // libreria"OneWire"para el sensor digital
#include <DallasTemperature.h> // libreria "Dallas Temperature" para converción de la señal 
#define mn   2
#define ent  3   // funcionnamiento manual o app
#define bos  5   //Bosina 
#define ret  6   //Rele resistencia
#define dis  7   //Rele disipador 
OneWire ourWire(4);   //Sensor de temperatura
DallasTemperature sensors(&ourWire);float mx = 32.9;
float temp; //temperatra real 
float mx = 34;
int fn = 0;
;

void setup() {
Serial.begin (9600);
sensors.begin();
delay (1000);
pinMode  (mn   , INPUT );
pinMode  (ent  , INPUT );
pinMode  (sen  , INPUT );
pinMode  (bos  , OUTPUT );
pinMode  (ret  , OUTPUT );
pinMode  (dis  , OUTPUT );
Serial.print ("Ensendido:");
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
sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
temp= sensors.getTempCByIndex(0); // se almacena la temperaura
switch (fn){
 case 1 : // Funcionamiento manual 
  while (sen < mx )   //funciona hasta que la sen no supere la temperatura 
  { Serial.print("Temperatura= ")
    Serial.print(temp);
    Serial.println(" C");
    digitalWrite ( ret , HIGH );
    delay (3500);
    digitalWrite ( ret , LOW );
    delay (1500);
    Serial.println("Claentando...");
  }
  while(sen > mx ) //estado de espera 
  { Serial.print("Temperatura= ");
    Serial.print(temp);
    Serial.println(" C");
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
}
