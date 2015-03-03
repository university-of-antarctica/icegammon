#ifndef ICEGAMMON_GAME_H_
#define ICEGAMMON_GAME_H_

	#include "Color.h"
  #include "Board.h"
  #include "Dice.h"
  #include "Move.h"
 
  #include <typeinfo>
  #include <cinttypes>
  #include <iostream>

	class Game{
	public:
    Game();
		void passTurn();
    Color getActiveColor(); // Returns the current value of turn which is whose turn it is, white or black.
    Board* getBoard();
    Dice* getDice();
    bool isLegal(Move potentialMove, Color player);
    // bool moveStone(Move move, Color player);
  private:
    Board* b;
    Dice* dice;
    Color turn = WHITE; // White is prompted for first roll
  };
#endif
