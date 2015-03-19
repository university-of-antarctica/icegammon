#ifndef ICEGAMMON_INTERACTIVECLI_H
#define ICEGAMMON_INTERACTIVECLI_H_

#include <stdio.h>
#include <algorithm>
#include <readline/readline.h>
#include <readline/history.h>
#include "Turn.h"
#include "Game.h"
#include "AsciiView.h"
#include "UserInputValidation.h"

class InteractiveCli{

  public:
  InteractiveCli(GameState* game);

  void DisplayBoard(AsciiView *view);
  void AnnounceTurn();

  // CLEANCODE: be consistent with our language.  everything should be 
  // 'query' or 'prompt' (my preference) for methods that block waiting 
  // for user input
  void PromptAndPerformRoll(bool test); 
  void QueryPlayerForRoll(bool test);
  void AnnounceWinnerOfRollForInitiative();
  
  //This is going to need to change to return a move object, turn object
  //returns don't allow for a player to move a stone more than once
  //in certain scenarios (when stone is moved to empty pip for first move).
  Turn* PromptPlayerForTurnObject(bool, int moveObjectsNeeded); 

  // CLEANCODE: we're parsing a move string into a move object, so, 
  // parseMoveString(std::string)?
  Move* ParseMove(std::string); 

  //TODO(gpwclark@gmail.com) make private after PromptForMove & IsInvalid
  //are done. 

  private:
  GameState *game_;
  UserInputValidation *input_validator_;
  void GetUserInputLine(std::string* returnString);
  };
#endif
