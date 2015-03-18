#ifndef ICEGAMMON_INTERACTIVECLI_H
#define ICEGAMMON_INTERACTIVECLI_H_

#include <stdio.h>
#include <iostream>
#include <readline/readline.h>
#include <readline/history.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Turn.h"
#include "Game.h"

class InteractiveCli{
  public:
  InteractiveCli(Game* game);

  // CLEANCODE: be consistent with our language.  everything should be 
  // 'query' or 'prompt' (my preference) for methods that block waiting 
  // for user input
  void PromptAndPerformRoll(bool test); 
  void QueryPlayerForRoll(bool test);
  void AnnounceWinnerOfFirstTurnRolls(std::string curr_player);
  // CLEANCODE: doesn't follow javabean standard for predicates (isValid might 
  // be better) NAME SHOULD START WITH is IF IT RETURNS bool.
  bool InputValidationForDiceRollPrompt(std::string line);

  // CLEANCODE: misnamed, this prompts a player for a turn object, not a move 
  // object. good opportunity to make an actual promptPlayerForMoveObject method
  Turn* PromptPlayerForMoveObjects(bool, int moveObjectsNeeded); 

  // CLEANCODE: we're parsing a move string into a move object, so, 
  // parseMoveString(std::string)?
  Move* ParseMove(std::string); 

  // CLEANCODE: doesn't follow javabean standard for predicates (isValid might 
  // be better) NAME SHOULD START WITH is IF IT RETURNS bool.
  bool InputValidationForMoveObjectPrompt(std::string); 

  //TODO(gpwclark@gmail.com) make private after PromptForMove & IsInvalid
  //are done. 

  private:
  Game* game;
  void GetUserInputLine(std::string* returnString);
  std::vector<std::string> SplitByWhiteSpace(std::string);
  int NumDigits(int);
  };
#endif
