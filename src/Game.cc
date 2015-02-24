#include "../include/Game.h"


  Game::Game(){
	  Game::b = new Board();
	  Game::dice = new Dice();
    dice->roll();
    uint8_t firstRoll = dice->left();
    uint8_t secondRoll = dice->right();
    rollForFirstMove(); 
  }
  void Game::rollForFirstMove(){
    //getDiceRollFromWhite
    //passTurn
    //getDiceRollFromBlack
    //keep doing that until white and black dice rolls aren't the same
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
