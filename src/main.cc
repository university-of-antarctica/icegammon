#include "../include/Board.h"
#include "../include/AsciiView.h"
#include "../include/Dice.h"
#include "../include/Game.h"
#include "../include/Controller.h" 
#include <iostream>

int main(){
  
  Controller *controller = new Controller();

	Game *game = new Game();

  AsciiView *view = new AsciiView(game->getBoard());
	std::string visualization = *view->toString();
	std::cout << "view looks like this: \n" << visualization << std::endl;

	std::cout << "turn: " << game->turn << std::endl;
	game->rollForFirstMove();
  
  return 0;

}
