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
  //
  controller->getFirstRoll();
	std::string visualization = game->drawBoard();
	std::cout << "view looks like this: \n" << visualization << std::endl;
  
	std::cout << "turn: " << game->turn << std::endl;

	game->getDice()->prettyPrint();

  return 0;

}
