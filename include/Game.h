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
  #include "Phase.h"

  //Describe this class and its responsibilities
  class GameState{
    public:
      GameState();  // default board, dice, initial phase
      GameState Copy(GameState* copyable_state);  // copy constructor
      
      Board* getBoard();
      Dice* getDice();

      //Phase:
      void passTurn();
      std::string getActiveColorString();  // Returns the current value of turn which is whose turn it is, white or black.
      Color getActiveColor();
      Phase phase_;

    private:
      Color turn_;
      Board* board_;
      Dice* dice_;
      
  };

  class GameLogic{
    public:
      GameLogic(GameState* state);
      bool isLegal(Move*);
      void submitTurn(Turn*, int);
      bool moveStone(Move*);
      GameState getGameState();
    private:
      GameState* state_;
  };

#endif
