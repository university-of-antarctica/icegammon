#ifndef ICEGAMMON_GAME_H_
#define ICEGAMMON_GAME_H_

	#include "Color.h"
  #include "Board.h"
  #include "Dice.h"
  #include <typeinfo>
  #include <cinttypes>
  #include <iostream>

	class Game{
	public:
    Game();
    Color turn = WHITE; //TODO: roll for initiative
		void passTurn();
    Board* getBoard();
    Dice* getDice();
  private:
    Board* b;
    Dice* dice;
  
  };
#endif
