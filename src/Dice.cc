
#include "../include/Dice.h"
#include <locale> // printing fun symbols
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


  Dice::Dice() {
      randomize();
      roll();
  }

  void Dice::roll() {
   values.first = getRandomDieRoll();
   values.second = getRandomDieRoll();
  }

  DieFace Dice::left() {
      return values.first;
  }
  DieFace Dice::right() {
      return values.second;
  }

  void Dice::set(DieFace left, DieFace right) {
    values.first = left;
    values.second = right;
  }

 DieFace Dice::getRandomDieRoll() {
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

 void Dice::randomize() {
   srand((unsigned)time(NULL));
 }

// wide characters (>8 bits each)
// note the L before each character to denote that it's longer than a normal char
// the first die can be arrived at with the following keys: [Ctrl Shift U][2][6][8][0]
// in a terminal.
wchar_t Dice::getSymbol(DieFace die) {
  switch(die) {
    case ONE:   return L'⚀';  // 0x2680
    case TWO:   return L'⚁';  // 0x2681
    case THREE: return L'⚂';  // 0x2682
    case FOUR:  return L'⚃';  // 0x2683
    case FIVE:  return L'⚄';  // 0x2684
    case SIX:   return L'⚅';  // 0x2685
    default:    // TODO(lovestevend@gmail.com): throw exception instead of a fun skull
        return L'☠';  // 0x2620 ( a skull )
  }
}

void Dice::prettyPrint() {
  std::locale::global(std::locale(""));
  // FUN EXPERIMENTAL THING TO TRY TO PRINT UNICODE DICE
  // stdout only likes to be a 'narrow' (8 bit) character stream or a 'wide' character stream (more than 8 bits)
  // got to reopen stdout to allow it to change modes to wide, then back to narrow
  freopen(NULL, "w", stdout); 
  // wcout for printing wide-character strings
  std::wcout << getSymbol(left()) << " and " << getSymbol(right()) << std::endl;

  freopen(NULL, "w", stdout); 
}

void Dice::prettyPrintOne() {
  std::locale::global(std::locale(""));
  // FUN EXPERIMENTAL THING TO TRY TO PRINT UNICODE DICE
  // stdout only likes to be a 'narrow' (8 bit) character stream or a 'wide' character stream (more than 8 bits)
  // got to reopen stdout to allow it to change modes to wide, then back to narrow
  freopen(NULL, "w", stdout); 
  // wcout for printing wide-character strings
 std::wcout << getSymbol(left());
  freopen(NULL, "w", stdout); 
}


