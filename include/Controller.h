#ifndef ICEGAMMON_CONTROLLER_H_
#define ICEGAMMON_CONTROLLER_H_
#include <stdio.h>
#include <stdint.h>
#include <readline/readline.h>
#include <readline/history.h>
//#include "Turn.h"
//#include "Move.h"
#include "Game.h"
#include <iostream>
#include "Dice.h"
#include "Move.h"
#include "Turn.h"

  class Controller{

  public:
  Controller(Game*);
  std::pair<DieFace,DieFace> getFirstTurnRolls(bool);
  void queryPlayerForRoll(bool);
  DieFace getFirstDieRoll();
  bool inputValidationForDiceRollPrompt(std::string*);
  
  void getFirstTurn(bool);
  Turn* queryPlayerForMoveObject(bool);
  bool inputValidationForMoveObject(std::string*); 
  int getNumMoves(); 
  bool getTurn(bool);
  Move* parseMove(std::string*);

  private:
  Game* game;
  void getUserInputLine(std::string*);
  };
#endif
