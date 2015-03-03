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

  std::string Game::getActiveColorString(){
   if(Game::turn==1){
    return "White";
   }else{
    return "Black";
  }

  }

  Board* Game::getBoard(){
    return Game::b;
  }

  Dice* Game::getDice(){
    return Game::dice;
  }
