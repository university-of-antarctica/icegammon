
#include "../include/Dice.h"
#include <locale> //printing fun symbols
#include <string>
#include <iostream> // cout


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

  // const char* Dice::left_(){
  //   return "\xE2\x9A\x80";
  // }



 uint8_t Dice::getRandomDieRoll(){
   uint8_t dieVal = (uint8_t)( ( rand() % 6 ) + 1 ); 
   return dieVal;
 }

 void Dice::randomize(){
   srand((unsigned)time(NULL));
 }

// an array of wide characters (>8 bits each)
// note the L before each character to denote that it's longer than a normal char
// the first die can be arrived at with the following keys: [Ctrl Shift U][2][6][8][0]
// in a terminal.
const wchar_t Dice::symbols[] = {L'⚀',L'⚁',0x2682,L'⚃',L'⚄',L'⚅'};

void Dice::prettyPrint(){
  std::locale::global(std::locale(""));
  //FUN EXPERIMENTAL THING TO TRY TO PRINT UNICODE DICE
  // stdout only likes to be a 'narrow' (8 bit) character stream or a 'wide' character stream (more than 8 bits)
  // got to reopen stdout to allow it to change modes to wide, then back to narrow
  freopen(NULL, "w", stdout); 
  // wcout for printing wide-character strings
  // use Classname::property to access static members
  std::wcout << Dice::symbols[this->left()-1] << " and " << Dice::symbols[this->right()-1] << std::endl;
  freopen(NULL, "w", stdout); 
}

  