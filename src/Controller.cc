#include "../include/Controller.h"

Controller::Controller(GameState* game) {
  game_ = game;
  cli_ = new InteractiveCli(game_);
}

void Controller::DisplayBoard(AsciiView *view) {
  cli_->DisplayBoard(view);
}

void Controller::AnnounceTurn() {
  cli_->AnnounceTurn();
}

void Controller::RollForInitiative(bool test) {
  std::pair<DieFace, DieFace> initiative_dice_rolls;

  do {
    initiative_dice_rolls = GetRollsForInitiative(test);
    // keep looping until white and black dice rolls aren't the same.
  } while (initiative_dice_rolls.first == initiative_dice_rolls.second);
  
  // set game_'s dice value so it is ready for the second turn
  game_->getDice()->set(initiative_dice_rolls.first, initiative_dice_rolls.second);

  // if winner of rolls is black, passTurn is called because black won
  // else passTurn is not called, meaning white won and remains in control of the turn.
  if (initiative_dice_rolls.first < initiative_dice_rolls.second) {
    game_->passTurn();
  }
  // Game's state now set so let's announce the winner who will take the second turn 
  cli_->AnnounceWinnerOfRollForInitiative();
}

std::pair<DieFace,DieFace> Controller::GetRollsForInitiative(bool test){

    std::pair<DieFace,DieFace> player_rolls;
    
    // This for loop repeats twice so each player gets to roll a die.
    for (int i = 0; i < 2; ++i){
      // Print current player's turn. current player is asked to roll one die
      cli_->QueryPlayerForRoll(test);
    
      // current player rolls one die, call game_ for die roll then print it to screen
      if (i == 0) {
        std::get<0>(player_rolls) = GetDieRoll();
      } else {
        std::get<1>(player_rolls) = GetDieRoll();
      }
      game_->passTurn();
    }

    return player_rolls;
}

DieFace Controller::GetDieRoll() { 
    DieFace die_roll;
    game_->getDice()->roll();
    die_roll = game_->getDice()->left();
    game_->getDice()->prettyPrintOne(); 
    std::cout << std::endl; 
  return die_roll;
}
void Controller::PerformFirstTurn(bool test){
  //On the first turn we don't roll the dice, they are set properly because
  //of RollForInitiative
  // ask activePlayer for turn object until they submit a valid one 
  ExecuteMoves(test); 
  game_->passTurn();
}
bool Controller::PerformTurn(bool test) {

  // A turn is just a dice roll, move execution, and then a call to game to pass the turn
  PerformDiceRoll(test);
  bool is_active_game;  // TODO(lovestevend@gmail.com): decide on logic for game_ end 
  
  // ask activePlayer for turn object until they submit a valid one 
  is_active_game = ExecuteMoves(test); 
  game_->passTurn();
  return is_active_game;
}

void Controller::PerformDiceRoll(bool test){
  cli_->PromptAndPerformRoll(test);
}

bool Controller::ExecuteMoves(bool test){
  GameLogic logic = GameLogic(game_);
  bool is_active_game = true; // TODO(gpwclark@gmail.com): need to figure out when this actually is.
  // parse move tokens into move objects into turn object
  Turn *turnObj = cli_->PromptPlayerForTurnObject(test,GetNumMoves()); 
  logic.submitTurn(turnObj, GetNumMoves());
  return is_active_game;
}

int Controller::GetNumMoves() {
  
  DieFace leftDie = Controller::game_->getDice()->left();
  DieFace rightDie = Controller::game_->getDice()->right();
  if (leftDie == rightDie) {
  // in backgammon if you roll doubles you get 4 moves
    return 4;
  }else{
  // normal rolls constitute 2 moves
    return 2;
  }
}
