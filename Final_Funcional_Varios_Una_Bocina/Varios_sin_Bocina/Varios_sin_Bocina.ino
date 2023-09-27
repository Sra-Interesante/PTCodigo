#include "Arduino.h" 
#include "SoftwareSerial.h" 
#include "DFRobotDFPlayerMini.h" 
#include "CapacitiveSensor.h" 

SoftwareSerial mySoftwareSerial(11,10); 
DFRobotDFPlayerMini myDFPlayer; 
CapacitiveSensor   sensor = CapacitiveSensor(3,4); 
CapacitiveSensor   sensorl = CapacitiveSensor(3,5);
CapacitiveSensor   sensorll = CapacitiveSensor(3,6);
CapacitiveSensor   sensorlll = CapacitiveSensor(3,7);
bool musica = false;  

void setup(){
  mySoftwareSerial.begin(9600); 
  Serial.begin(115200); 
  pinMode(9,INPUT); 

  if (!myDFPlayer.begin(mySoftwareSerial)) { 
    Serial.println("Ojo aka prrx"); 
    while(true); 
}
  Serial.println("Todo al trillon pariente"); 

  myDFPlayer.volume(30); 
}

void loop(){
 long tocar = sensor.capacitiveSensor(30);
 long tocarl = sensorl.capacitiveSensor(30);
 long tocarll = sensorll.capacitiveSensor(30);
 long tocarlll = sensorlll.capacitiveSensor(30);
 bool busy; 

 if(musica == true) 
 {
  busy = digitalRead(8); 
  if (busy == true) 
  {
   myDFPlayer.next(); 
  }
 }

//Acá va el primer sensor capacitivo.

if ( tocar > 10 ) {
   if(musica == false)  
   {
     Serial.println("play");
     myDFPlayer.start(); 
     musica = true;
   }
   else
   {
     Serial.println("pausa"); 
     myDFPlayer.pause(); 
     musica = false; 
   }
   while ( tocar > 10 )
   {
     tocar = sensor.capacitiveSensor(30);
   }
 }

if ( tocarl > 10 ) {
   if(musica == false)  
   {
     Serial.println("play");
     myDFPlayer.start(); 
     musica = true;
   }
   else
   {
     Serial.println("pausa"); 
     myDFPlayer.pause(); 
     musica = false; 
   }
   while ( tocarl > 10 )
   {
     tocarl = sensorl.capacitiveSensor(30);
   }
 }

 if ( tocarll > 10 ) {
   if(musica == false)  
   {
     Serial.println("play");
     myDFPlayer.start(); 
     musica = true;
   }
   else
   {
     Serial.println("pausa"); 
     myDFPlayer.pause(); 
     musica = false; 
   }
   while ( tocarll > 10 )
   {
     tocarll = sensorll.capacitiveSensor(30);
   }
 }

 if ( tocarlll > 10 ) {
   if(musica == false)  
   {
     Serial.println("play");
     myDFPlayer.start(); 
     musica = true;
   }
   else
   {
     Serial.println("pausa"); 
     myDFPlayer.pause(); 
     musica = false; 
   }
   while ( tocarlll > 10 )
   {
     tocarlll = sensorlll.capacitiveSensor(30);
   }
 }

 delay (1000);
}