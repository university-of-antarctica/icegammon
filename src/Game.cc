#include "../include/Game.h"

  Game::Game(){
	  Game::b = new Board();
	  Game::dice = new Dice();
  } 

  void Game::submitTurn(Turn *turnObj,int numMoves){
    int i = 0;
    while(i< numMoves){
      moveStone(turnObj->moves[i]);      
      ++i;
    }
    //TODO FREE turnObj memory
  }

	void Game::passTurn(){
		if(turn==Color::WHITE){
			turn=Color::BLACK;
		}
		else{
			turn=Color::WHITE;
		}
	}

  Color Game::getActiveColor(){
    return Game::turn;
  }

  std::string Game::getActiveColorString(){
    if(Game::turn==Color::WHITE){
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

  bool Game::moveStone(Move *move){
    
    //TODO These variables are repeated in isLegal(), should they be put in a struct or class or something?
    int numSourceStones         = b->pips[move->sourcePipNum];
    int numDestStones           = b->pips[move->destPipNum];

    // positive #s represent # of white stones
    // negative #s represent # of black stones
    bool diffColorStones        = numDestStones*numSourceStones < 0;
    bool destHasOneStone        = numDestStones*numDestStones  == 1;
    
    // We can do something if...

      // source and dest are same color or dest is empty
      if(!diffColorStones || numDestStones == 0){
          if(numSourceStones > 0){ // white stone(s)
            b->pips[move->sourcePipNum] -= 1; // 1 fewer stone on source pip
            b->pips[move->destPipNum]   += 1; // 1 more stone on dest pip
          }
          else{ // black stone(s)
            b->pips[move->sourcePipNum] += 1; // 1 fewer stone on source pip (so we add)
            b->pips[move->destPipNum]   -= 1; // 1 more stone on dest pip (so we subtract)
          }
          return true;
      }
      // or
      // different colors, but blottable
      if(diffColorStones && destHasOneStone){
          if(numSourceStones > 0){ // white stone blots black stone
            b->pips[move->sourcePipNum] -= 1; // 1 fewer stone on source pip
            b->pips[move->destPipNum]    = 1; // now exactly 1 white stone on dest pip
            b->bars[1]+=1; //send a black stone to the bar
          }
          else{ // black stone blots white stone
            b->pips[move->sourcePipNum] += 1; // 1 fewer stone on source pip (so we add)
            b->pips[move->destPipNum]    =-1; // now exactly 1 black stone on the dest pip
            b->bars[0]+=1; //send a white stone to the bar
          }
          return true;
      }
     
    
    return false;
  }

  bool Game::isLegal(Move *move){

    //TODO These variables are repeated in moveStone(), should they be put in a struct or class or something?
    int numSourceStones         = b->pips[move->sourcePipNum];
    int numDestStones           = b->pips[move->destPipNum];

    // positive #s represent # of white stones
    // negative #s represent # of black stones
    bool diffColorStones        = numDestStones*numSourceStones < 0;
    bool destHasMultipleStones  = numDestStones*numDestStones   > 1;
    
    //TODO: verify that the distance traveled is at most 6 pips
    //TODO: verify that we should be moving this color stone
    //TODO: verify that we rolled this on the dice
    //TODO: verify that we don't need to get a stone off the bar
    //TODO: consider bearing off at all

    // We can't do anything if...
      // if there is NO stone on the source pip...
      if(numSourceStones == 0){ 
        return false;
      }
      // the dest can't be blotted
      if(diffColorStones && destHasMultipleStones){ 
        return false;
      }
      // the source = the dest
      if(move->sourcePipNum == move->destPipNum){
        return false;
      }
      return true;

  }
