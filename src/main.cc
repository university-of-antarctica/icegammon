#include "../include/Game.h"
#include "../include/Controller.h" 
#include "../include/AsciiView.h"
#include <iostream>


int main(){

	Game *game = new Game();
  Controller *controller = new Controller(game);
  AsciiView *view = new AsciiView(game);
  
  //first turn logic
  //controller queries each player and prints their die values and the proper prompts
  //a winner of the opening roll is determined (this is the exit condition)
  
  bool test = false; 
  std::pair<DieFace,DieFace> firstTurnDiceRolls = controller->getFirstTurnRolls(test);
	
  std::string visualization = view->toString();
	std::cout << "view looks like this: \n" << visualization << std::endl;
  std::cout << game->getActiveColorString() << "'s Move" << std::endl;
	//For this case, we actually need to feed prettyPrint the values since they
  //aren't random here, they must be equal to the outcome of the first rolls.

  //RETURN DICE ROLLS FROM getFirstTurn!!!!!
  game->getDice()->set(firstTurnDiceRolls.first,firstTurnDiceRolls.second);
  game->getDice()->prettyPrint();
  //controller->getFirstTurn();
  /*
   bool activeGame = true;
    while(activeGame){  
     std::string visualization = view->toString();
     activeGame = controller->getTurn();
  }
  */
  return 0;

}
