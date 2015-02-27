#include "../include/Game.h"


  Game::Game(Controller* controller){
	  Game::b = new Board();
    Game::view = new AsciiView(Game::b);
	  Game::dice = new Dice();
    Game::controller = controller;
    dice->roll();
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
 
 std::string Game::drawBoard(){
    return Game::view->toString();
 }
  Board* Game::getBoard(){
    return Game::b;
  }

  Dice* Game::getDice(){
    return Game::dice;
  }
