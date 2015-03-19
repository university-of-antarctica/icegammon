#include "../include/InteractiveCli.h"


InteractiveCli::InteractiveCli(GameState* game) {
  InteractiveCli::game = game;

}

void InteractiveCli::PromptAndPerformRoll(bool test) {
// ask activePlayer to roll
  QueryPlayerForRoll(test);
// actuallyRollTheDice
 game->getDice()->roll();
 
 std::cout << "Rolling..." << std::endl;
 game->getDice()->prettyPrint();
}


void InteractiveCli::QueryPlayerForRoll(bool test) {  
  // this should be it's own method (print current player's turn)
  // these also shouldn't be coupled; printing the curr player's turn is a side-effect
  std::string currPlayer =  game->getActiveColorString(); 
  std::cout << "It is:  "  << currPlayer << "'s Turn " << std::endl;
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
 }while (InputValidationForDiceRollPrompt(*line));
 std::cout << "Rolling..." << std::endl;
 delete line;
}

void InteractiveCli::AnnounceWinnerOfFirstTurnRolls(std::string curr_player){
  std::cout << curr_player << " won the roll and will start the game." << std::endl;
}

bool InteractiveCli::InputValidationForDiceRollPrompt(std::string line) {
  bool inputInvalidKeepLooping = false;  // CLEANCODE: javabean predicate
// CLEANCODE: repetition of "line->at(0)".  
  // show intent by naming this. "firstCharOfInput"?
  // I feel fine about 'r' and 'R' being magic numbers, but I don't think Clean Code does...
  if (line.at(0)!='r' && line.at(0)!='R') { 
      inputInvalidKeepLooping = true;     
  }
  return inputInvalidKeepLooping;
}

Turn* InteractiveCli::PromptPlayerForMoveObjects(bool test,int moveObjectsNeeded) {  
  std::string* line =  new std::string();
  Turn *turnObj = new Turn();
  for (int i = 0; i < moveObjectsNeeded; ++i) {
    do{  
       std::cout << "Input move, format 'm int int' " << std::endl;
    
       if (test) {
          line->assign("m 1 11");  // figure out simple valid move syntax
       }else{
          GetUserInputLine(line);
       }
      std::cout << "you entered: " << *line << std::endl;
    }while (InputValidationForMoveObjectPrompt(*line));

    Move *moveObj = ParseMove(*line); 
    turnObj->moves[i] = moveObj;  // TODO(lovestevend@gmail.com): is this making a deep copy of the moveObj? if so we need to delete it   
  }
 delete line;

 return turnObj;
}
Move* InteractiveCli::ParseMove(std::string line) {
// needs to allocate new move on the heap
// and return that object

  // http:// www.cplusplus.com/reference/istream/istream/operator%3E%3E/
  // it looks like you may be able to do this more easily with a stream
  // (look at the example)
  std::vector<std::string> userInputVector = SplitByWhiteSpace(line);
  std::string elem1 = userInputVector[1];
  std::string elem2 = userInputVector[2];

  int elem1Int = atoi(elem1.c_str());
  int elem2Int = atoi(elem2.c_str());
  
  Move *moveObj = new Move(elem1Int, elem2Int);
  
  return moveObj;
}

bool InteractiveCli::InputValidationForMoveObjectPrompt(std::string line) {
  bool inputInvalidKeepLooking = true;
  std::vector<std::string> userInputVector = SplitByWhiteSpace(line);
  // move object only has 3 tokens
  if (userInputVector.size() == 3) {

    std::string elem0 = userInputVector[0];
    std::string elem1 = userInputVector[1];
    std::string elem2 = userInputVector[2];
    
    // Get length of elements as they are strings 
    int elem1StrLength = elem1.length();
    int elem2StrLength = elem2.length();
    
    // convert strings to integers, if there are non digits characters
    // it will return a digit in the string depending on where the character
    // in the string was.
    int elem1Int = atoi(elem1.c_str());
    int elem2Int = atoi(elem2.c_str());
    
    // get the numberOfDigits, this will be used in a check with
    // the string length, if the string length and num digits match
    // then we know the whole string was an integer we can use.
    int elem1IntLength = NumDigits(elem1Int);
    int elem2IntLength = NumDigits(elem2Int);

  // std::cout << "1: " << elem1Int << " str: " << elem1StrLength << " int: " << elem1IntLength << " 2: " << elem2Int << " str: " << elem2StrLength << " int: " << elem2IntLength << std::endl;

    if (elem0 == "m" && elem1StrLength == elem1IntLength && elem2StrLength == elem2IntLength ) { 
        inputInvalidKeepLooking = false;
    }
  }

  return inputInvalidKeepLooking;
}

void InteractiveCli::GetUserInputLine(std::string* returnString) {
    char * line = readline("> ");
    // !!!!!!
    // From http:// cnswww.cns.cwru.edu/php/chet/readline/readline.html#SEC24 ...
    // "If readline encounters an EOF while reading the line, and 
    // the line is empty at that point, then (char *)NULL is returned. 
    // Otherwise, the line is ended just as if a newline had been typed.""
    // this causes a segmentation fault as of 9:00 AM on 3/05 if [Ctrl D] is pressed
    *returnString = reinterpret_cast<char*>(line);
    free(line);
}

std::vector<std::string> InteractiveCli::SplitByWhiteSpace(std::string line) {
  std::string buf;  // Have a buffer string
  std::stringstream ss(line);  // Insert the string into a stream
  std::vector<std::string> tokens;  // Create vector to hold our words
  while (ss >> buf) {
    tokens.push_back(buf);
  }
  return tokens;
}

int InteractiveCli::NumDigits(int x) {  
    x = abs(x);  // this is beautiful
    return (x < 10 ? 1 :   
           (x < 100 ? 2 :   
           (x < 1000 ? 3 :   
           (x < 10000 ? 4 :   
           (x < 100000 ? 5 :   
           (x < 1000000 ? 6 :   
           (x < 10000000 ? 7 :  
           (x < 100000000 ? 8 :  
           (x < 1000000000 ? 9 :  
           10)))))))));  // TODO(lovestevend@gmail.com): throw exception? have a guarantee on the max size?
}
