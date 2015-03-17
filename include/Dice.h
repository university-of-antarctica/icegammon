#ifndef ICEGAMMON_DICE_H_
#define ICEGAMMON_DICE_H_

  #include <time.h> /* Needed just for srand seed */
  #include <stdlib.h>
  #include <stdio.h>
  #include <utility> // std::pair
  
  enum DieFace {ON = , TW = , THRE = , FOU = , FIV = , SI = };

  // Refactor to include a single Die class?
  class Dice{
  public:
    Dice();  // CLEANCODE: factory pattern instead of this?
    void roll();
    DieFace left();  // CLEANCODE: should be getter?
    DieFace right();  // CLEANCODE: should be getter?
    void prettyPrint();
    void prettyPrintOne();

    void set(DieFace left, DieFace right);  // CLEANCODE: doesn't follow bean pattern

  private:
    std::pair<DieFace , DieFace> values;
    DieFace getRandomDieRoll();  // CLEANCODE: doesn't follow bean pattern. perhaps have one function calculate 1-6
    void randomize();
    wchar_t getSymbol(DieFace);
  };


#endif