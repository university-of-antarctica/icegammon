#include "../include/Board.h"
#include "../include/AsciiView.h"
#include "../include/Dice.h"
#include "../include/Game.h"
#include <iostream>

int main(){

	Board *b = new Board();
	b->initialize();
	std::cout << "pip 2 on board has: " <<b->pips[2] << " stones " << std::endl;


	AsciiView *view = new AsciiView(b);
	std::string visualization = *view->toString();
	std::cout << "view looks like this: " << visualization << std::endl;


	Dice *dice = new Dice();
	dice->roll();
	std::cout << "dice rolled: " << dice->left() << " and " << dice -> right() << std::endl;


	Game *game = new Game();
	game->passTurn();
	std::cout << "turn: " << game->turn << std::endl;

	return 0;
}