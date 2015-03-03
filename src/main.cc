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
  std::pair<uint8_t,uint8_t> secondTurnDiceRolls = controller->getFirstTurn(test);
	std::string visualization = view->toString();
	std::cout << "view looks like this: \n" << visualization << std::endl;
  std::cout << game->getActiveColorString() << "'s Move" << std::endl;
	//For this case, we actually need to feed prettyPrint the values since they
  //aren't random here, they must be equal to the outcome of the first rolls.

  //RETURN DICE ROLLS FROM getFirstTurn!!!!!
  std::cout << int(secondTurnDiceRolls.first) << " " << int(secondTurnDiceRolls.second) << std::endl; 

  return 0;

}
