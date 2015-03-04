#include "../include/Game.h"


  Game::Game(){
	  Game::b = new Board();
	  Game::dice = new Dice();
  } 

  void Game::submitTurn(Turn *turnObj){
    //YOUR CODE GOES HERE
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

  bool Game::isLegal(Move potentialMove, Color player){
    return false;
  }

  bool Game::moveStone(Move move, Color stoneColor){

    int numSourceStones = b->pips[move.sourcePipNum];

    if(numSourceStones == 0){ // there is no stone on the source pip
      return false;
    }
    else{ // there is at least one stone on the source pip
      //positive #s represent # of white stones
      //negative #s represent # of black stones
      if(numSourceStones > 0){ // white stone(s)
        b->pips[move.sourcePipNum] -= 1; // 1 fewer stone on source pip
        b->pips[move.destPipNum]   += 1; // 1 more stone on dest pip
      }
      else{ // black stone(s)
        b->pips[move.sourcePipNum] += 1; // 1 fewer stone on source pip (so we add)
        b->pips[move.destPipNum]   -= 1; // 1 more stone on dest pip (so we subtract)
      }
      return true;
    }
  }
