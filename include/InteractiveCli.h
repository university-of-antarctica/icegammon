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
#include "AsciiView.h"

class InteractiveCli{
  public:
  InteractiveCli(Game* game);
  
  void DisplayBoard(AsciiView *view);
  void AnnounceTurn();

  // CLEANCODE: be consistent with our language.  everything should be 
  // 'query' or 'prompt' (my preference) for methods that block waiting 
  // for user input
  void PromptAndPerformRoll(bool test); 
  void QueryPlayerForRoll(bool test);
  void AnnounceWinnerOfRollForInitiative();
  // CLEANCODE: doesn't follow javabean standard for predicates (isValid might 
  // be better) NAME SHOULD START WITH is IF IT RETURNS bool.
  bool InputValidationForDiceRollPrompt(std::string line);
  
  //This is going to need to change to return a move object, turn object
  //returns don't allow for a player to move a stone more than once
  //in certain scenarios (when stone is moved to empty pip for first move).
  Turn* PromptPlayerForTurnObject(bool, int moveObjectsNeeded); 

  // CLEANCODE: we're parsing a move string into a move object, so, 
  // parseMoveString(std::string)?
  Move* ParseMove(std::string); 

  // CLEANCODE: doesn't follow javabean standard for predicates (isValid might 
  // be better) NAME SHOULD START WITH is IF IT RETURNS bool.
  bool InputValidationForMoveObjectPrompt(std::string); 

  //TODO(gpwclark@gmail.com) make private after PromptForMove & IsInvalid
  //are done. 

  private:
  Game* game_;
  void GetUserInputLine(std::string* returnString);
  std::vector<std::string> SplitByWhiteSpace(std::string);
  int NumDigits(int);
  };
#endif
