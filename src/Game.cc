#include "../include/Game.h"


  Game::Game(){
	  Game::b = new Board();
	  Game::dice = new Dice();
  }

	void Game::passTurn(){
		if(turn==WHITE){
			turn=BLACK;
		}
		else{
			turn=WHITE;
		}
	}
  Color Game::getActiveColor(){
    return Game::turn;
  }

  Board* Game::getBoard(){
    return Game::b;
  }

  Dice* Game::getDice(){
    return Game::dice;
  }

  bool Game::isLegal(Move potentialMove, Color player){
    return false;
  }

  // bool Game::moveStone(Move move, Color stoneColor){
  //   return false;
  // }
