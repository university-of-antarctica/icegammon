#include "../include/Game.h"
#include "../include/GameplayController.h" 
#include "../include/AsciiView.h"
#include <iostream>


int main() {

  GameState *game = new GameState();
  GameplayController *controller = new GameplayController(game);
  AsciiView *view = new AsciiView(game);
  
  // first turn logic
  // controller queries each player and prints their die values and the proper prompts
  // a winner of the opening roll is determined (this is the exit condition)
  
  bool test = false; 
  controller->RollForInitiative(test);
  controller->DisplayBoard(view);  // this argument is NOT kosher 
  controller->AnnounceTurn();
  controller->PerformFirstTurn(test);
  
   bool activeGame = true;
    while (activeGame) { 
     controller->DisplayBoard(view); 
     activeGame = controller->PerformTurn(test);
     controller->AnnounceTurn();
    }
 
  return 0;

}
