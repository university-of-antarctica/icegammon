#include "../include/Board.h"
#include "../include/AsciiView.h"
#include "../include/Dice.h"
#include "../include/Game.h"
#include <iostream>

#include <locale> //printing fun symbols
#include <string>

int main(){
	std::locale::global(std::locale(""));

	Board *b = new Board();
	b->initialize();
	std::cout << "pip 2 on board has: " <<b->pips[2] << " stones " << std::endl;


	AsciiView *view = new AsciiView(b);
	std::string visualization = *view->toString();
	std::cout << "view looks like this: \n" << visualization << std::endl;

// DICE
	Dice *dice = new Dice();
	dice->roll();
	int left,right;
	left = dice->left();
	right = dice->right();

	std::cout << "dice rolled: " << left << " and " << right << std::endl;
	

	//FUN EXPERIMENTAL THING TO TRY TO PRINT UNICODE DICE
	// stdout only likes to be a 'narrow' (8 bit) character stream or a 'wide' character stream (more than 8 bits)
	// got to reopen stdout to allow it to change modes to wide, then back to narrow
	freopen(NULL, "w", stdout); 
	// wcout for printing wide-character strings
	// use Classname::property to access static members
	std::wcout << "dice rolled: " << Dice::symbols[left-1] << " and " << Dice::symbols[right-1] << std::endl;
	freopen(NULL, "w", stdout);	
	
// GAME
	Game *game = new Game();
	game->passTurn();
	std::cout << "turn: " << game->turn << std::endl;

	return 0;
}