#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(11,10);
DFRobotDFPlayerMini myDFPlayer;
bool musica = false; 

void setup(){
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  pinMode(8,INPUT);
  pinMode(7,INPUT);

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use serial to communicate with mp3.
    Serial.println("Ojo aka prrx");
    while(true);
}
  Serial.println("Todo al trillon pariente");

  myDFPlayer.volume(30);
}

void loop(){
 bool busy;
 bool touch = digitalRead(7);

 if(musica == true)
 {
  busy = digitalRead(8); 
  if (busy == true)
  {
   myDFPlayer.randomAll();
  }
 }

 if (touch == true)
 {
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
   while (touch == true)
   {
     touch = digitalRead(7);
     delay(10);
   }
 }
 delay (50);
}