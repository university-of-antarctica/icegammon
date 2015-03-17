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
  Turn* isInvalid(bool);

  // CLEANCODE: misnamed, this prompts a player for a turn object, not a move 
  // object. good opportunity to make an actual promptPlayerForMoveObject method
  Turn* queryPlayerForMoveObject(bool); 

  // CLEANCODE: doesn't follow javabean standard for predicates (isValid might 
  // be better)
  bool inputValidationForMoveObject(std::string); 

  // CLEANCODE:javabean predicate rule
  bool inputValidationForDiceRollPrompt(std::string);
  
  // will need to be more complicated since we have to enumerate all turns to 
  // find the one with the most moves, right?
  int getNumMoves(); 

  // CLEANCODE: this doesn't follow javabean standard for get methods, it is 
  // a pun
  bool  getTurn(bool); 

  // CLEANCODE: we're parsing a move string into a move object, so, // parseMoveString(std::string)?
  Move* parseMove(std::string); 
  void announceTurn();
  void displayBoard(AsciiView*);

  // CLEANCODE: be consistent with our language.  everything should be 
  // 'query' or 'prompt' (my preference) for methods that block waiting 
  // for user input
  void promptAndPerformRoll(bool test); 

  private:
  Game* game;
  // CLEANCODE: get method returns void?
  void getUserInputLine(std::string*); 
  std::vector<std::string> splitByWhiteSpace(std::string);
  int numDigits(int);
  };
#endif
