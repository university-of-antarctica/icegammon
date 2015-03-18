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
// add parameter name in signature
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
  // be better) NAME SHOULD START WITH is IF IT RETURNS bool.
  bool inputValidationForMoveObject(std::string); 

  // CLEANCODE:javabean predicate rule //SAME THING AS ABOVE
  bool inputValidationForDiceRollPrompt(std::string);

  //This function is dubiously named and is technically the property of gameplay logic 
  int getNumMoves(); 

  // CLEANCODE: this doesn't follow javabean standard for get methods, it is 
  // a pun, don't use get, don't return a turn, this is more a perform turn.
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
  // CLEANCODE: get method returns void? Revisit whether or not the line could be returned,
  // we would prefer to not have output arguments.
  void getUserInputLine(std::string*); 
  std::vector<std::string> splitByWhiteSpace(std::string);
  int numDigits(int);
  };
#endif
