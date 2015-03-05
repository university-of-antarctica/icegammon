#ifndef ICEGAMMON_CONTROLLER_H_
#define ICEGAMMON_CONTROLLER_H_

#include <stdio.h>
#include <stdint.h>
#include <iostream>

#include <readline/readline.h>
#include <readline/history.h>

#include "Game.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Dice.h"
#include "AsciiView.h"
#include "Move.h"
#include "Turn.h"
#include <cstdlib>

  class Controller{

  public:
  Controller(Game*);
  void getFirstTurnRolls(bool);
  void queryPlayerForRoll(bool);
  DieFace getFirstDieRoll();
  bool inputValidationForDiceRollPrompt(std::string*);
  
  //implement these! (and test)
  Turn* queryPlayerForMoveObject(bool);
  bool inputValidationForMoveObject(std::string); //CLEANCODE: doesn't follow javabean standard for predicates (isValid might be better)
  int getNumMoves(); 
  bool getTurn(bool); //CLEANCODE: this doesn't follow javabean standard for get methods, it is a pun
  Move* parseMove(std::string);
  void promptAndPerformRoll(bool test);
  void announceTurn();
  void displayBoard(AsciiView*);

  private:
  Game* game;
  void getUserInputLine(std::string*);
  std::vector<std::string> splitByWhiteSpace(std::string);
  int numDigits(int);
  };
#endif
