#include "../include/Game.h"


  Game::Game(){
	  Game::b = new Board();
    std::cout << "pip 2 on board has: " <<b->pips[2] << " stones " << std::endl;

	  Game::dice = new Dice();
    dice->roll();
    uint8_t firstRoll = dice->left();
    uint8_t secondRoll = dice->right();
    std::cout << "dice rolled: " << int(firstRoll) << " and " << int(secondRoll) << std::endl;
  }

	void Game::passTurn(){
		if(turn==WHITE){
			turn=BLACK;
		}
		else{
			turn=WHITE;
		}
	}
 
  Board* Game::getBoard(){
    return Game::b;
  }

  Dice* Game::getDice(){
    return Game::dice;
  }
