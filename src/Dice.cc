
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

  DieFace Dice::left(){
      return values.first;
  }
  DieFace Dice::right(){
      return values.second;
  }

  //TODO: change all uint8_t to DieVal
  void Dice::set(DieFace left, DieFace right){
    values.first = left;
    values.second = right;
  }

  // const char* Dice::left_(){
  //   return "\xE2\x9A\x80";
  // }



 DieFace Dice::getRandomDieRoll(){
   DieFace retval;
   uint dieVal = ( ( rand() % 6 ) + 1 ); 
   if(dieVal==1)retval=ONE;
   if(dieVal==2)retval=TWO;
   if(dieVal==3)retval=THREE;
   if(dieVal==4)retval=FOUR;
   if(dieVal==5)retval=FIVE;
   if(dieVal==6)retval=SIX;
   
   return retval;
 }

 void Dice::randomize(){
   srand((unsigned)time(NULL));
 }

// an array of wide characters (>8 bits each)
// note the L before each character to denote that it's longer than a normal char
// the first die can be arrived at with the following keys: [Ctrl Shift U][2][6][8][0]
// in a terminal.
const wchar_t Dice::symbols[] = {L'⚀',L'⚁',0x2682,L'⚃',L'⚄',L'⚅'};

wchar_t Dice::getSymbol(DieFace die){
  switch(die){
    case ONE:   return L'⚀';
    case TWO:   return L'⚁';
    case THREE: return 0x2682;
    case FOUR:  return L'⚃';
    case FIVE:  return L'⚄';
    case SIX:   return L'⚅';
    default:    return L'☠'; //0x2620 ( a skull )
  }
}

void Dice::prettyPrint(){
  std::locale::global(std::locale(""));
  //FUN EXPERIMENTAL THING TO TRY TO PRINT UNICODE DICE
  // stdout only likes to be a 'narrow' (8 bit) character stream or a 'wide' character stream (more than 8 bits)
  // got to reopen stdout to allow it to change modes to wide, then back to narrow
  freopen(NULL, "w", stdout); 
  // wcout for printing wide-character strings
  // use Classname::property to access static members
  // std::wcout << Dice::symbols[this->left()-1] << " and " << Dice::symbols[this->right()-1] << std::endl;
  std::wcout << getSymbol(left()) << " and " << getSymbol(right()) << std::endl;

  freopen(NULL, "w", stdout); 
}

void Dice::prettyPrintOne(){
  std::locale::global(std::locale(""));
  //FUN EXPERIMENTAL THING TO TRY TO PRINT UNICODE DICE
  // stdout only likes to be a 'narrow' (8 bit) character stream or a 'wide' character stream (more than 8 bits)
  // got to reopen stdout to allow it to change modes to wide, then back to narrow
  freopen(NULL, "w", stdout); 
  // wcout for printing wide-character strings
  // use Classname::property to access static members
  std::wcout << getSymbol(left());
  freopen(NULL, "w", stdout); 
}


