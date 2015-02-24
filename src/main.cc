#include "../include/Board.h"
#include "../include/AsciiView.h"
#include "../include/Dice.h"
#include "../include/Game.h"
#include "../include/Controller.h" 
#include <iostream>



int main(){
	std::locale::global(std::locale(""));

  Game *game = new Game();
	game->passTurn();
	std::cout << "turn: " << game->turn << std::endl;

  AsciiView *view = new AsciiView(game->getBoard());
	std::string visualization = *view->toString();
	std::cout << "view looks like this: \n" << visualization << std::endl;

  Controller *controller = new Controller();
	controller->getUserInputLine();
  
  return 0;

}
