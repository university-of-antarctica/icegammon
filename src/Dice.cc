#include <time.h> /* Needed just for srand seed */
#include <stdlib.h>
#include <stdio.h>

class Dice{

public:
  
 std::pair<uint8_t,uint8_t> rollDice(){
   //randomize();
   std::pair<uint8_t,uint8_t> pairOfRolls;
   pairOfRolls.first = getRandomDieRoll();
   //randomize();
   pairOfRolls.second = getRandomDieRoll();
   return pairOfRolls;

 }

private:

 uint8_t getRandomDieRoll(){
   uint8_t dieVal;
   dieVal = (uint8_t)( ( rand() % 6 ) + 1 ); 
   int dieValInt = (int)dieVal;
   std::cout << "die val: " <<  dieValInt << std::endl;
   return dieVal;
 }

 void randomize(){
   srand((unsigned)time(NULL));
 }

};
