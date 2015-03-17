#ifndef ICEGAMMON_GAME_H_
#define ICEGAMMON_GAME_H_

  #include "Color.h"
  #include "Board.h"
  #include "Dice.h"
  #include "Move.h"
  #include "Color.h" 
  #include <typeinfo>
  #include <cinttypes>
  #include <iostream>
  #include "Turn.h"

 // #include "gtest/gtest_prod.h" // FRIEND_TEST

  class Game{
  public:
    Game();
    void passTurn();
    std::string getActiveColorString();  // Returns the current value of turn which is whose turn it is, white or black.
    Color getActiveColor();
    Board* getBoard();
    Dice* getDice();
    bool isLegal(Move*);  // should a move also have a color inside it?
    // bool moveStone(Move move, Color player);
    void submitTurn(Turn*, int);
    bool moveStone(Move*); 
  private:
    Board* b;
    Dice* dice;
    Color turn = Color::WHITE;  // White is prompted for first roll
    

   // FRIEND_TEST(Moving, BasicForceMove);
  };
#endif
