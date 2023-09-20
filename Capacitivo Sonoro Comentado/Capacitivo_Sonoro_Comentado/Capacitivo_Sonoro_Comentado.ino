#include <CapacitiveSensor.h> /*Se incluye libreria convierte dos o más pines Arduino en un sensor tactil que puede sentir la capacitancia
 eléctrica del cuerpo humano */
#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880 // Este es un La a esta frecuencia
int altavoz = 11; //Indico en que pin del Arduino se conecta el speaker
CapacitiveSensor   ca = CapacitiveSensor(4,3); /*Para la libreria es necesario indicar en que pines esta conectado el sensor capacitivo, en este caso se
necesitan usar dos pines para este sensor, el Desender (4) que es quien envia la señal y el pin de Receiver (3) que detecta si estamos tocando o no el sensor*/
void setup(){
pinMode(altavoz, OUTPUT); //Aca solo se indica la salida
}
void loop(){
long ba = ca.capacitiveSensor(30); //Se crea esta variable de lectura (ba) y se iguala a la lectura que obtenemos del valor de nuestro sensor 
if(ba > 10) //Lo que hace esta funcion no es más que comparar el valor de la lectura (ba) y si esta es mayor a 10 (funciona con 1 incluso) entonces...
tone(altavoz, aH, 10); //Reproduce desde el altavoz lo que anteriormente se definió en aH que son los 880 Hz.

