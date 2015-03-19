#include "../include/Game.h"

// GAMESTATE /////////////////////////////////////
  GameState::GameState() {
    board_ = new Board();
    dice_ = new Dice();
    // turn_ = Color::WHITE;
    phase_ = new Phase();
  } 

  void GameState::passTurn() {
    phase_->SwitchPlayer();
  }

  Color GameState::getActiveColor() {
    return phase_->player_on_turn().color();
  }

  std::string GameState::getActiveColorString() {
    return phase_->player_on_turn().toString();
  }

  Board* GameState::getBoard() {
    return board_;
  }

  Dice* GameState::getDice() {
    return dice_;
  }

// GAMELOGIC ////////////////////////////////////

  GameLogic::GameLogic(GameState* state){
     state_ = state;
  }

//  void GameLogic::submitTurn(Turn *turnObj, int numMoves) {
//    int i = 0;
//    while (i< numMoves) {
//      moveStone(turnObj->moves[i]);      
//      ++i;
//    }
    // TODO(lovestevend@gmail.com) FREE turnObj memory
    // Need to meet about the deconstructor of turnObj
    // delete turnObj;
//  }

  bool GameLogic::moveStone(Move *move) {
    if(!isLegal(move)){
      return false;
    }
    Board* board = state_->getBoard();
    
    // TODO(lovestevend@gmail.com) These variables are repeated in isLegal(),
    // should they be put in a struct or class or something?
    int numSourceStones         = board->pips[move->sourcePipNum];
    int numDestStones           = board->pips[move->destPipNum];

    // positive #s represent # of white stones
    // negative #s represent # of black stones
    bool diffColorStones        = numDestStones*numSourceStones < 0;
    bool destHasOneStone        = numDestStones*numDestStones  == 1;
    
    // We can do something if...

      // source and dest are same color or dest is empty

      if(!diffColorStones || numDestStones == 0) {
          if(numSourceStones > 0) {  // white stone(s)
            board->pips[move->sourcePipNum] -= 1;  // 1 fewer stone on source pip
            board->pips[move->destPipNum]   += 1;  // 1 more stone on dest pip
          }
          else{  // black stone(s)
            // 1 fewer stone on source pip (so we add)
            board->pips[move->sourcePipNum] += 1;  
            // 1 more stone on dest pip (so we subtract)
            board->pips[move->destPipNum]   -= 1;  
          }
          return true;
      }
      // or
      // different colors, but blottable
      if(diffColorStones && destHasOneStone) {
          if(numSourceStones > 0) {  // white stone blots black stone
            // 1 fewer stone on source pip
            board->pips[move->sourcePipNum] -= 1;  
            // now exactly 1 white stone on dest pip
            board->pips[move->destPipNum]    = 1;  
            board->bars[1]+=1;  // send a black stone to the bar
          }
          else{  // black stone blots white stone
            // 1 fewer stone on source pip (so we add)
            board->pips[move->sourcePipNum] += 1;  
            // now exactly 1 black stone on the dest pip
            board->pips[move->destPipNum]    =-1;  
            board->bars[0]+=1;  // send a white stone to the bar
          }
          return true;
      }
     
    
    return false;
  }

  bool GameLogic::isLegal(Move *move) {
    Board* board = state_->getBoard();
    // TODO(lovestevend@gmail.com) These variables are repeated in moveStone(),
    // should they be put in a struct or class or something?
    int numSourceStones         = board->pips[move->sourcePipNum];
    int numDestStones           = board->pips[move->destPipNum];

    // positive #s represent # of white stones
    // negative #s represent # of black stones
    bool diffColorStones        = numDestStones*numSourceStones < 0;
    bool destHasMultipleStones  = numDestStones*numDestStones   > 1;
    
    // TODO(lovestevend@gmail.com): verify that the distance traveled is at most
    // 6 pips
    // TODO(lovestevend@gmail.com): verify that we should be moving this color
    // stone
    // TODO(lovestevend@gmail.com): verify that we rolled this on the dice
    // TODO(lovestevend@gmail.com): verify that we don't need to get a stone 
    // off the bar
    // TODO(lovestevend@gmail.com): consider bearing off at all

    // We can't do anything if...
      // if there is NO stone on the source pip...
      if (numSourceStones == 0) { 
        return false;
      }
      // the dest can't be blotted
      if (diffColorStones && destHasMultipleStones) { 
        return false;
      }
      // the source = the dest
      if (move->sourcePipNum == move->destPipNum) {
        return false;
      }
      return true;

  }
