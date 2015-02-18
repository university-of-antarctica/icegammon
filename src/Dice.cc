#include <time.h> /* Needed just for srand seed */
#include <stdlib.h>
#include <stdio.h>

class Dice{
// Randomization woes explained:
// After using a specific number as a seed, you'll always get the same sequence of random #s
// srand(1) is called if you never call srand(something) yourself
// so without calling srand() you will get the same sequence of random #s every time you run the program
// if you use srand(time(NULL)) then you get some other sequence of #s
// if you REPEATEDLY call srand(time(NULL)) in the same ... second? milisecond? then the time value is the same
// and you are basically getting on the same sequence of numbers, just starting over
// so you just call srand() once, in the constructor of the Dice

public:
  Dice(){
      randomize();
  }

 std::pair<uint8_t,uint8_t> rollDice(){
   std::pair<uint8_t,uint8_t> pairOfRolls;
   pairOfRolls.first = getRandomDieRoll();
   pairOfRolls.second = getRandomDieRoll();
   return pairOfRolls;

 }

private:

 uint8_t getRandomDieRoll(){
   uint8_t dieVal = (uint8_t)( ( rand() % 6 ) + 1 ); 
   return dieVal;
 }

 void randomize(){
   srand((unsigned)time(NULL));
 }

};
