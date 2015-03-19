#ifndef ICEGAMMON_CONTROLLER_H_
#define ICEGAMMON_CONTROLLER_H_

#include <stdint.h>
#include "Game.h"
#include "Dice.h"
#include "AsciiView.h"
#include "Move.h"
#include "Turn.h"
#include "InteractiveCli.h"
#include <cstdlib>
#include <utility>

  class Controller{
// add parameter name in signature
  public:
  Controller(GameState* game);

  //TODO(gpwclark@gmail.com) figure out where these two methods go,
  //as of now they may or not be acceptable, especially DisplayBoard
  //getting asciiView. 
  void AnnounceTurn();
  void DisplayBoard(AsciiView *view);
  
  void RollForInitiative(bool test);
  bool PerformTurn(bool test); 

  // This function is dubiously named and is technically the property of 
  // gameplay logic, or w/e system we end up using to determine the Complete move
  // of the user given their roll.
  // is public for testing
  int GetNumMoves(); 
  
  //public for google test
  DieFace GetDieRoll();
  private:

  GameState* game_;
  InteractiveCli* cli_;
  std::pair<DieFace,DieFace> GetRollsForInitiative(bool test);
  void PerformDiceRoll(bool test);
  bool ExecuteMoves(bool test);
  };
#endif
