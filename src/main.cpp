#include <Arduino.h> //libreria lenguaje del codigo
#include <OneWire.h> // libreria"OneWire"para el sensor digital
#include <DallasTemperature.h> // libreria "Dallas Temperature" para converción de la señal 
#include <BluetoothSerial.h> // libreria "BluetoothSerial" comunicación bluetooth
#define mn   2   //funcionamiento manual 
#define ent  3   //Funcinamiento app
#define bos  5   //Bosina
#define ret  6   //Resistencia
#define dis  7   //Disipador 
OneWire ourWire(4);   //Sensor de temperatura
DallasTemperature sensors(&ourWire);float mx = 32.9;
float temp; //temperatra real 
int fn = 0;
int valor ;
BluetoothSerial SerialBT;

void setup() {
  delay (1000);
  Serial.begin (9600);
  sensors.begin();
  SerialBT.begin("ESP32test"); // Nombre del bluetooth
  pinMode  (mn  , INPUT );
  pinMode  (ent  , INPUT );
  pinMode  (bos  , OUTPUT );
  pinMode  (ret  , OUTPUT );
  pinMode  (dis  , OUTPUT );
  Serial.print ("Ensendido:");
}

void loop() {
 if (digitalRead( ent) == HIGH ) {//Definir como va a funcionar manual o app 
     fn = 2 ;
    }
  else if (digitalRead(mn)== HIGH ){
     fn = 1 ;
    }
  sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
  temp= sensors.getTempCByIndex(0); //se almacena la temperatura
  switch (fn){
  case 1 : // Funcionamiento manual 
   Serial.print("Maual");
    while (temp < mx )   //funciona hasta que la sen no supere la temperatura 
     { Serial.print("Temperatura= ");
       Serial.print(temp);
       Serial.println(" °C");
       digitalWrite ( ret , HIGH );
       delay (1750);
       digitalWrite ( ret , LOW );
       delay (350);
       Serial.print("Calentando");
       Serial.print(". ");
       delay (150);
       Serial.print(". ");
       delay (150);
       Serial.println(". ");
       
     }
    while(temp > mx ) { 
       Serial.print("Temperatura= ");
       Serial.print(temp);
       Serial.println(" °C");
       digitalWrite ( dis , HIGH );
       delay (3000);
       digitalWrite ( dis , LOW );
       Serial.println("Listo.");
      }
    break;
  case 2 :  // Fucinamiento Remoto pendiente confi funciones 
   Serial.print("Remoto");
     while(SerialBT.available()  ) {
     valor = SerialBT.read();
    if (valor == '1' ){
     while (temp < mx ) {  //funciona hasta que la sen no supere la temperatura  
       Serial.print("Temperatura= ");
       Serial.print(temp);
       Serial.println(" °C");
       digitalWrite ( ret , HIGH );
       delay (3500);
       digitalWrite ( ret , LOW );
       delay (5000);
       Serial.print("Calentando");
       Serial.print(". ");
       delay (150);
       Serial.print(". ");
       delay (150);
       Serial.println(". ");
      }
    }
    else if (valor == '2' ){
     while(temp > mx ) {
       Serial.print("Temperatura= ");
       Serial.print(temp);
       Serial.println(" °C");
       digitalWrite ( dis , HIGH );
       delay (3500);
       digitalWrite ( dis , LOW );
       delay (5000);
       Serial.println("Listo.");
       }
    }
delay(1000);
 } 

   break;
  default: // Error de funcionamiento 
   Serial.print("Sistema deshabilitado");
   
   return;// salir del  selector 
   break;
  }
}


