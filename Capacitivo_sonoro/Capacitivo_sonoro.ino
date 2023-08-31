#include <CapacitiveSensor.h>
#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440l
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
#define aH 880
int altavoz = 11;
CapacitiveSensor   ca = CapacitiveSensor(4,3);
//CapacitiveSensor   cf = CapacitiveSensor(5,3);
void setup(){
pinMode(altavoz, OUTPUT);
}
void loop(){
long ba = ca.capacitiveSensor(30);
//long bf = cf.capacitiveSensor(20);
if(ba > 10)
tone(altavoz, a, 10);
/*else if(bf > 10)
tone(altavoz, aH, 10);*/
}
