#include "../include/InteractiveCli.h"

InteractiveCli::InteractiveCli(GameState* game) {
  InteractiveCli::game_ = game;
  InteractiveCli::input_validator_ = new UserInputValidation();
}

void InteractiveCli::DisplayBoard(AsciiView *view){
  std::string visualization = view->ToString(); 
  std::cout << "/\\/\\/\\*I*C*E*G*A*M*M*O*N/\\/\\/\\/\\ \n" << visualization << std::endl;
}

void InteractiveCli::AnnounceTurn(){
  std::cout << "It is: " << game_->getActiveColorString() << "'s Turn" << std::endl; 
}

void InteractiveCli::PromptAndPerformRoll(bool test) {
// ask activePlayer to roll
  PromptPlayerForRoll(test);
// actuallyRollTheDice
 game_->getDice()->roll();
 
 std::cout << "Rolling..." << std::endl;
 game_->getDice()->prettyPrint();
}


void InteractiveCli::PromptPlayerForRoll(bool test) {  
  // this should be it's own method (print current player's turn)
  // these also shouldn't be coupled; printing the curr player's turn is a side-effect
  AnnounceTurn();
  std::cout << "Input R or r to roll" << std::endl;
  std::string* line =  new std::string();
  do{  
    std::cout << "Enter an R or an r" << std::endl;
    if (test) {
      line->assign(1, 'r');
    }else{
      GetUserInputLine(line);
    }
    std::cout << "you entered: " << *line << std::endl;
 }while (input_validator_->InputValidationForDiceRollPrompt(*line));
 delete line;
}

void InteractiveCli::AnnounceWinnerOfRollForInitiative(){
  std::cout << game_->getActiveColorString() << " won the roll and will start the game." << std::endl;
  game_->getDice()->prettyPrint();
}


void InteractiveCli::PromptAndPerformTurn(bool test,int moveObjectsNeeded) {  
  // This moveObjectsNeed int definitely will come from the GameState class 
  // when we get to that point
  GameLogic logic = GameLogic(game_); 
  bool is_valid_move;
  for (int i = 0; i < moveObjectsNeeded; ++i){
  //TODO(gpwclark@gmail.com) do I need to create new line every time or no?
    do {
      std::string* line =  new std::string();
      PromptPlayerForMoveString(test, line); 
      Move *moveObj = ParseMoveString(*line); 
      is_valid_move = logic.moveStone(moveObj); 
      if (!is_valid_move){
        std::cout << "*ERROR* :: *INVALID* :: *MOVE* ... try again...." << std::endl;
      }
      delete line;
      delete moveObj;
    } while (!is_valid_move);
  }
}

void InteractiveCli::PromptPlayerForMoveString(bool test, std::string *line){
  //TODO(gpwclark@gmail.com): Need support for 'm 2 h' and 'm b 3' moves.
  bool is_invalid_input; 
    do {  
       std::cout << "Input move, format 'm int int' " << std::endl;
    
       if (test) {
          line->assign("m 1 11");  // figure out simple valid move syntax
       } else {
          GetUserInputLine(line);
       }
      std::cout << "you entered: " << *line << std::endl;
      
      // InputValidationForMoveObjectPrompt's bool is configured for loop
      // logic. This means it returns true if the input is false and the 
      // loop needs to run again to get valid input from user. It returns
      // false when input is valid and the loop doesn't need to execute.
      is_invalid_input = input_validator_->InputValidationForMoveObjectPrompt(*line);
      if (is_invalid_input){
        std::cout << "*ERROR* :: *INVALID* :: *MOVE* :: *STRING* ... try again...." << std::endl;
      }
    } while (is_invalid_input);
}

Move* InteractiveCli::ParseMoveString(std::string line) {

  std::vector<std::string> userInputVector = input_validator_->SplitByWhiteSpace(line);
  std::string elem1 = userInputVector[1];
  std::string elem2 = userInputVector[2];

  // Converting a string (that may or may not be an int) to an int is tricky
  // business and the behavior of the atoi() function, specifically the way
  // that it handles mixed int/char strings e.g. "h8k" is the most logical
  // choice 
  int elem1Int = atoi(elem1.c_str());
  int elem2Int = atoi(elem2.c_str());
  
  Move *moveObj = new Move(elem1Int, elem2Int);
  return moveObj;
}

void InteractiveCli::GetUserInputLine(std::string* returnString) {
    char *line = readline("> ");
    // !!!!!!
    // From http:// cnswww.cns.cwru.edu/php/chet/readline/readline.html#SEC24 ...
    // "If readline encounters an EOF while reading the line, and 
    // the line is empty at that point, then (char *)NULL is returned. 
    // Otherwise, the line is ended just as if a newline had been typed.""
    // this causes a segmentation fault as of 9:00 AM on 3/05 if [Ctrl D] is pressed
    *returnString = reinterpret_cast<char*>(line);
    free(line);
}
