
#include "../include/Dice.h"


// Randomization woes explained:
// After using a specific number as a seed, you'll always get the same sequence of random #s
// srand(1) is called if you never call srand(something) yourself
// so without calling srand() you will get the same sequence of random #s every time you run the program
// if you use srand(time(NULL)) then you get some other sequence of #s
// if you REPEATEDLY call srand(time(NULL)) in the same ... second? milisecond? then the time value is the SAME!!!
// and you are basically getting on the same sequence of numbers, just starting over
// so you just call srand() once, in the constructor of the Dice

   // class Dice;

  Dice::Dice(){
      randomize();
      roll();
  }

  void Dice::roll(){
   values.first = getRandomDieRoll();
   values.second = getRandomDieRoll();
  }

  uint8_t Dice::left(){
      return values.first;
  }
  uint8_t Dice::right(){
      return values.second;
  }


 uint8_t Dice::getRandomDieRoll(){
   uint8_t dieVal = (uint8_t)( ( rand() % 6 ) + 1 ); 
   return dieVal;
 }

 void Dice::randomize(){
   srand((unsigned)time(NULL));
 }
