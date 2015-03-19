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

  //TODO(gpwclark@gmail.com): inheritance for PromptAndPerform*
  //and PromptPlayer* ?

  public:
  InteractiveCli(GameState* game);

  void DisplayBoard(AsciiView *view);
  void AnnounceTurn();
  void PromptAndPerformRoll(bool test); 
  void PromptPlayerForRoll(bool test);
  void AnnounceWinnerOfRollForInitiative();
  
  // This is going to need to change to return a move object, turn object
  // returns don't allow for a player to move a stone more than once
  // in certain scenarios (when stone is moved to empty pip for first move).
  void PromptAndPerformTurn(bool test, int moveObjectsNeeded); 
  void PromptPlayerForMoveString(bool test, std::string *line);
  Move* ParseMoveString(std::string); 

  private:
  GameState *game_;
  UserInputValidation *input_validator_;
  void GetUserInputLine(std::string* returnString);
  };
#endif
