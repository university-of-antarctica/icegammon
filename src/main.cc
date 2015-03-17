#include "../include/Game.h"
#include "../include/Controller.h" 
#include "../include/AsciiView.h"
#include <iostream>


int main() {

  Game *game = new Game();
  Controller *controller = new Controller(game);
  AsciiView *view = new AsciiView(game);
  
  // first turn logic
  // controller queries each player and prints their die values and the proper prompts
  // a winner of the opening roll is determined (this is the exit condition)
  
  bool test = false; 
  controller->getFirstTurnRolls(test);
  
  controller->displayBoard(view);  // this argument is NOT kosher 
  controller->announceTurn();
  controller->getTurn(test);
  
   bool activeGame = true;
    while(activeGame) { 
     controller->displayBoard(view); 
     controller->promptAndPerformRoll(test);
     controller->displayBoard(view); 
     activeGame = controller->getTurn(test);
     controller->announceTurn();
    }
 
  return 0;

}
