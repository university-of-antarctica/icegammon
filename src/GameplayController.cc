#include "../include/GameplayController.h"

GameplayController::GameplayController(GameState* game) {
  game_ = game;
  cli_ = new InteractiveCli(game_);
}

void GameplayController::DisplayBoard(AsciiView *view) {
  cli_->DisplayBoard(view);
}

void GameplayController::AnnounceTurn() {
  cli_->AnnounceTurn();
}

void GameplayController::RollForInitiative(bool test) {
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

std::pair<DieFace,DieFace> GameplayController::GetRollsForInitiative(bool test){

    std::pair<DieFace,DieFace> player_rolls;
    
    // This for loop repeats twice so each player gets to roll a die.
    for (int i = 0; i < 2; ++i){
      // Print current player's turn. current player is asked to roll one die
      cli_->PromptPlayerForRoll(test);
    
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

DieFace GameplayController::GetDieRoll() { 
    DieFace die_roll;
    game_->getDice()->roll();
    die_roll = game_->getDice()->left();
    game_->getDice()->prettyPrintOne(); 
    std::cout << std::endl; 
  return die_roll;
}
void GameplayController::PerformFirstTurn(bool test){
  //On the first turn we don't roll the dice, they are set properly because
  //of RollForInitiative
  // ask activePlayer for turn object until they submit a valid one 
  ExecuteMoves(test); 
  game_->passTurn();
}
bool GameplayController::PerformTurn(bool test) {

  // A turn is just a dice roll, move execution, and then a call to game to pass the turn
  PerformDiceRoll(test);
  bool is_active_game;  // TODO(lovestevend@gmail.com): decide on logic for game_ end 
  
  // ask activePlayer for turn object until they submit a valid one 
  is_active_game = ExecuteMoves(test); 
  game_->passTurn();
  return is_active_game;
}

void GameplayController::PerformDiceRoll(bool test){
  cli_->PromptAndPerformRoll(test);
}

bool GameplayController::ExecuteMoves(bool test){
  // TODO(gpwclark@gmail.com): need to figure out game end logic.
  bool is_active_game = true; 
  // ask player for move string and perform turn
  cli_->PromptAndPerformTurn(test,GetNumMoves()); 
  return is_active_game;
}

int GameplayController::GetNumMoves() {
  
  DieFace leftDie = GameplayController::game_->getDice()->left();
  DieFace rightDie = GameplayController::game_->getDice()->right();
  if (leftDie == rightDie) {
  // in backgammon if you roll doubles you get 4 moves
    return 4;
  }else{
  // normal rolls constitute 2 moves
    return 2;
  }
}
