#ifndef ICEGAMMON_GAME_H_
#define ICEGAMMON_GAME_H_

	#include "Color.h"
  #include "Board.h"
  #include "Dice.h"
  #include "Controller.h"
  #include <typeinfo>
  #include <cinttypes>
  #include <iostream>
  #include "AsciiView.h"

	class Game{
	public:
    Game(Controller*);
    Color turn = WHITE; //TODO: roll for initiative
		void passTurn();
    Board* getBoard();
    Dice* getDice();
    void rollForFirstMove();
    std::string drawBoard();
  private:
    AsciiView* view;
    Board* b;
    Dice* dice;
    Controller* controller;
  };
#endif
