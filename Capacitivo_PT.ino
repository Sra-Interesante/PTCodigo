#include "Arduino.h" 
#include "SoftwareSerial.h" 
#include "DFRobotDFPlayerMini.h" 
#include "CapacitiveSensor.h" 

SoftwareSerial mySoftwareSerial(11,10); 
DFRobotDFPlayerMini myDFPlayer; 
CapacitiveSensor   sensor = CapacitiveSensor(4,3); 
bool musica = false;  

void setup(){
  mySoftwareSerial.begin(9600); 
  Serial.begin(115200); 
  pinMode(8,INPUT); 

  if (!myDFPlayer.begin(mySoftwareSerial)) { 
    Serial.println("Ojo aka prrx"); 
    while(true); 
}
  Serial.println("Todo al trillon pariente"); 

  myDFPlayer.volume(30); 
}

void loop(){
 long tocar = sensor.capacitiveSensor(30); /
 bool busy; 
 if(musica == true) 
 {
  busy = digitalRead(8); 
  if (busy == true) 
  {
   myDFPlayer.next(); 
  }
 }


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
 delay (1000);
}
