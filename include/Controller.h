#ifndef ICEGAMMON_CONTROLLER_H_
#define ICEGAMMON_CONTROLLER_H_

#include <stdio.h>
#include <stdint.h>
#include <iostream>

#include <readline/readline.h>
#include <readline/history.h>

#include "Game.h"
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
  
  //implement these! (and test)
  void getFirstTurn(bool);
  Turn* queryPlayerForMoveObject(bool);
  bool inputValidationForMoveObject(std::string*); //CLEANCODE: doesn't follow javabean standard for predicates (isValid might be better)
  int getNumMoves(); 
  bool getTurn(bool); //CLEANCODE: this doesn't follow javabean standard for get methods, it is a pun
  Move* parseMove(std::string*);


  private:
  Game* game;
  void getUserInputLine(std::string*);
  };
#endif
