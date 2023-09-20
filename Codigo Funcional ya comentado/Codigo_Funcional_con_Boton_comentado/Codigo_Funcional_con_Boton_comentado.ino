#include "Arduino.h" //Esta libreria generalmente se usa para programar librerias para Arduino
#include "SoftwareSerial.h" // Esta libreria sirve para crear una comunicación serial entre el Arduino y el Modulo DFPlayer Mini
#include "DFRobotDFPlayerMini.h" //Esta libreria es para controlar al Modulo de Audio MP3
#include "CapacitiveSensor.h" //LIBRERIA PARA USAR EL SENSOR CAPACITIVO TACTIL CON ALUMINIO

SoftwareSerial mySoftwareSerial(11,10); //Acá llamando a la libreria de la linea 2 estamos declarando que pines crearán la comunicación con Arduino
DFRobotDFPlayerMini myDFPlayer; //Conexión de la libreria con este codigo
CapacitiveSensor   sensor = CapacitiveSensor(4,3); /*Para la libreria es necesario indicar en que pines esta conectado el sensor capacitivo, en este caso se
necesitan usar dos pines para este sensor, el Desender (4) que es quien envia la señal y el pin de Receiver (3) que detecta si estamos tocando o no el sensor*/
bool musica = false; // Esta variable es el indicador de que indique si se está reproduciendo música o no. 

void setup(){
  mySoftwareSerial.begin(9600); //Acá (9600) es el codigo de comunicación entre el Arduino y el Modulo de Audio MP3
  Serial.begin(115200); // Comunicación entre Arduino y la PC
  pinMode(8,INPUT); //Se declara que estoy usando el pin Busy del Modulo MP3 como entrada (linea 32)
  pinMode(7,INPUT);// Se declara que estoy usando este pin de Arduino para conectar el Sensor Touch digital (NO CAPACITIVO)

  if (!myDFPlayer.begin(mySoftwareSerial)) {  // Este if verifica errores, que este bien conectado el modulo a través de los pines (11,10)
    Serial.println("Ojo aka prrx"); //En caso de que no se logre lo anterior se imprime este mensaje en el monitor
    while(true); //Gracias a este "while" si no los corregimos, nunca podremos pasar de este "if"
}
  Serial.println("Todo al trillon pariente"); //Si se establece la comunicación y no se presentan errores, entonces arrojará este mensaje en el monitor

  myDFPlayer.volume(30); //Esta linea se configura el volumen, este va de 0-30. Aqui está al máximo
}

void loop(){
 bool busy; //Se crea una variable booleana para leer al pin "Busy" del Modulo Mp3, este pin establece si se reproduce musica o no, si emite musica nos muestra 5v y si no lo hace, nos arroja 0v
 bool touch = digitalRead(7); //Se crea variable booleana para leer la lectura del sensor Touch digital.

 if(musica == true) //Esto quiere decir que hay musica en el modulo y solamente en caso de hacerlo se ejecuta lo del siguiente "if" lineas 31-37
 {
  busy = digitalRead(8);  //Se indica en que pin se conecta el pin Busy del Modulo y se lee. 
  if (busy == true) //CUando el pin busy arroje 5v, entonces esto hará que no exista algun track reproduciendose
  {
   myDFPlayer.next(); //Si no existe track reproduciendose entonces acá la reproduzco. Para reproducirlo de manera continua ".next" es una función de la misma libreria del Modulo para hacerlo en orden. 
  }
 }

 if (touch == true) //Cuando se toque el sensor touch toca algun track
 {
   if(musica == false) //Indica que no hay tracks en el sensor reproduciendose 
   {
     Serial.println("play"); //Cuando no haya tracks reproduciendose después de recibir la lectura de que el sensor fue tocado entonces se imprime "play"
     myDFPlayer.start(); //Después de imprimirlo en el monitor, reproduce la secuencia del track que estaba sonando
     musica = true;
   }
   else
   {
     Serial.println("pausa"); //Cuando no haya tracks reproduciendose después de recibir la lectura de que el sensor fue tocado entonces se imprime "pausa"
     myDFPlayer.pause(); //Después de imprimirlo en el monitor, reproduce el track que estaba sonando
     musica = false; 
   }
   while (touch == true) //Mientras mantenga el dedo en el sensor y no lo retire (linea 55)...
   {
     touch = digitalRead(7); //"touch" será igual a la lectura en el pin 7 que es donde esta el botón
   }
 }
 delay (1000);
}