#include "../include/Controller.h"

// TODO(lovestevend@gmail.com) This class generates turn specific messages, need a method to do that
Controller::Controller(Game* game) {
  Controller::game = game;
  Controller::cli = new InteractiveCli(game);
}


void Controller::DisplayBoard(AsciiView *view) {
  std::string visualization = view->ToString(); 
  std::cout << "/\\/\\/\\*I*C*E*G*A*M*M*O*N/\\/\\/\\/\\ \n" << visualization << std::endl;
}

void Controller::AnnounceTurn() {
  std::cout << game->getActiveColorString() << "'s Move" << std::endl; 
  std::string curr_player =  game->getActiveColorString();            
  std::cout << "It is:  "  << curr_player << "'s Turn " << std::endl;
}

void Controller::PerformRoll(bool test){
  cli->PromptAndPerformRoll(test);
}

void Controller::PerformFirstTurnRolls(bool test) {
  DieFace white_roll;
  DieFace black_roll;
  do{
    // Print white's turn. White player is asked to roll one die
    cli->QueryPlayerForRoll(test);
    
    // white player rolls one die, call game for die roll then print it to screen
    white_roll = PerformFirstDieRoll();

    // pass turn
    game->passTurn();

    //Same series is done for black player, to get black's die roll.
    cli->QueryPlayerForRoll(test);
    black_roll = PerformFirstDieRoll();
    game->passTurn();

    // keep doing that until white and black dice rolls aren't the same.
  }while (white_roll == black_roll);
  
  //set game's dice value so it is ready for the first turn
  
  game->getDice()->set(white_roll, black_roll);
  // if winner of rolls is black, passTurn is called
  // else passTurn is not called, meaning white won and remains in control of the turn.
  if (white_roll < black_roll) {
    game->passTurn();
  }

  std::string curr_player =  game->getActiveColorString(); 
  cli->AnnounceWinnerOfFirstTurnRolls(curr_player);
  // For this case, we actually need to feed prettyPrint the values since they
  // // aren't random here, they must be equal to the outcome of the first rolls.    
  game->getDice()->prettyPrint();
  
}

DieFace Controller::PerformFirstDieRoll() { 
    DieFace dieRoll;
    game->getDice()->roll();
    dieRoll = game->getDice()->left();
    game->getDice()->prettyPrintOne(); 
    std::cout << std::endl; 
  return dieRoll;
}

bool Controller::PerformTurn(bool test) {
  bool activeGame = true;  // TODO(lovestevend@gmail.com): decide on logic for game end 
  bool activeTurn = true;
  
  // ask activePlayer for series of move tokens corresponding to roll
    
    while (activeTurn) {
      Turn *turnObj = cli->PromptPlayerForMoveObjects(test,GetNumMoves()); 
      
      // parse move tokens into move objects into turn object
      // submit turn object to game
      
      bool validTurn = true;
      
      int i = 0;
      while ((i < GetNumMoves()) &&  validTurn) {  
        validTurn = game->isLegal(turnObj->moves[i]); 
        ++i;
      }
      if (validTurn) {
        game->submitTurn(turnObj, GetNumMoves());
        activeTurn = false;
      }else{
        std::cout << "*ERROR* :::: *INVALID* :::: *MOVE* ... try again...." << std::endl;
      }
  }
  game->passTurn();
  return activeGame;
}

int Controller::GetNumMoves() {
  
  DieFace leftDie = Controller::game->getDice()->left();
  DieFace rightDie = Controller::game->getDice()->right();
  if (leftDie == rightDie) {
  // in backgammon if you roll doubles you get 4 moves
    return 4;
  }else{
  // normal rolls constitute 2 moves
    return 2;
  }
}
