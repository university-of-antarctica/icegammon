#include "../include/Controller.h"

//TODO This class generates turn specific messages, need a method to do that
Controller::Controller(Game* game){
  Controller::game = game;
}

void Controller::promptAndPerformRoll(bool test){
//ask activePlayer to roll
  queryPlayerForRoll(test);
//actuallyRollTheDice
 game->getDice()->roll();
 
 std::cout << "Rolling..." << std::endl;
 game->getDice()->prettyPrint();

}

void Controller::displayBoard(AsciiView *view){
  std::string visualization = view->toString(); 
  std::cout << "/\\/\\/\\*I*C*E*G*A*M*M*O*N/\\/\\/\\/\\ \n" << visualization << std::endl;
}

void Controller::announceTurn(){
  std::cout << game->getActiveColorString() << "'s Move" << std::endl; 
  std::string currPlayer =  game->getActiveColorString();            
  std::cout << "It is:  "  << currPlayer << "'s Turn " << std::endl;

}


bool Controller::getTurn(bool test){
  bool activeGame = true; //TODO: decide on logic for game end 
  bool activeTurn = true;
  
  //ask activePlayer for series of move tokens corresponding to roll
    
    while(activeTurn){
      Turn *turnObj = queryPlayerForMoveObject(test); 
      
      //parse move tokens into move objects into turn object
      //submit turn object to game
      
      bool validTurn = true;
      
      int i = 0;
      while((i < getNumMoves()) &&  validTurn){  
        validTurn = game->isLegal(turnObj->moves[i]); 
        ++i;
      }
      if(validTurn){
        game->submitTurn(turnObj,getNumMoves());
        activeTurn = false;
      }else{
        std::cout << "*ERROR* :::: *INVALID* :::: *MOVE* ... try again...." << std::endl;
      }
  }
  
  game->passTurn();
  return activeGame;
}

Turn* Controller::queryPlayerForMoveObject(bool test){  
  std::string* line =  new std::string();
  Turn *turnObj = new Turn();

  int moveObjectsNeeded = getNumMoves();
  
  for(int i = 0; i < moveObjectsNeeded; ++i){
    do{  
       std::cout << "Input move, format 'm int int' " << std::endl;
    
       if(test){
          line->assign("m 1 11"); //figure out simple valid move syntax
       }else{
          getUserInputLine(line);
       }
      std::cout << "you entered: " << *line << std::endl;
    }while(inputValidationForMoveObject(*line));

    Move *moveObj = parseMove(*line); 
    turnObj->moves[i] = moveObj;//TODO: is this making a deep copy of the moveObj? if so we need to delete it   
  }
 delete line;

 return turnObj;
}

Move* Controller::parseMove(std::string line){
//needs to allocate new move on the heap
//and return that object

  // http://www.cplusplus.com/reference/istream/istream/operator%3E%3E/
  // it looks like you may be able to do this more easily with a stream
  // (look at the example)
  std::vector<std::string> userInputVector = splitByWhiteSpace(line);
  std::string elem1 = userInputVector[1];
  std::string elem2 = userInputVector[2];

  int elem1Int = atoi(elem1.c_str());
  int elem2Int = atoi(elem2.c_str());
  
  Move *moveObj = new Move(elem1Int,elem2Int);
  
  return moveObj;
}

bool Controller::inputValidationForMoveObject(std::string line){
  bool inputInvalidKeepLooking = true;
  std::vector<std::string> userInputVector = splitByWhiteSpace(line);
  //move object only has 3 tokens
  if(userInputVector.size()==3){

    std::string elem0 = userInputVector[0];
    std::string elem1 = userInputVector[1];
    std::string elem2 = userInputVector[2];
    
    //Get length of elements as they are strings 
    int elem1StrLength = elem1.length();
    int elem2StrLength = elem2.length();
    
    //convert strings to integers, if there are non digits characters
    //it will return a digit in the string depending on where the character
    //in the string was.
    int elem1Int = atoi(elem1.c_str());
    int elem2Int = atoi(elem2.c_str());
    
    //get the numberOfDigits, this will be used in a check with
    //the string length, if the string length and num digits match
    //then we know the whole string was an integer we can use.
    int elem1IntLength = numDigits(elem1Int);
    int elem2IntLength = numDigits(elem2Int);

  // std::cout << "1: " << elem1Int << " str: " << elem1StrLength << " int: " << elem1IntLength << " 2: " << elem2Int << " str: " << elem2StrLength << " int: " << elem2IntLength << std::endl;
    
    if(elem0=="m" && elem1StrLength == elem1IntLength && elem2StrLength == elem2IntLength ){ 
        inputInvalidKeepLooking = false;
    }
  }

  return inputInvalidKeepLooking;
}

int Controller::numDigits(int x){  
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
           10)))))))));  //TODO: throw exception? have a guarantee on the max size?
}

std::vector<std::string> Controller::splitByWhiteSpace(std::string line){
 
  std::string buf; // Have a buffer string
  std::stringstream ss(line); // Insert the string into a stream
  std::vector<std::string> tokens; // Create vector to hold our words

  while (ss >> buf){
    tokens.push_back(buf);
  }
  
  return tokens;
}

int Controller::getNumMoves(){
  
  DieFace leftDie = Controller::game->getDice()->left();
  DieFace rightDie = Controller::game->getDice()->right();
  if(leftDie==rightDie){
  //in backgammon if you roll doubles you get 4 moves
    return 4;
  }else{
  //normal rolls constitute 2 moves
    return 2;
  }
}

void Controller::getFirstTurnRolls(bool test){

  DieFace whiteRoll;
  DieFace blackRoll;
  do{
    //alternative:
    /////////////////////////////////////////////
        //game->getDice()->roll();
        
        //whiteRoll = dice->left();
        //view->displayCurrentTurn(); //UNIMPLEMENTED
        //queryPlayerForRoll(test) //just make white player type r
        //print left(white) die
        //game->passTurn();


        //blackRoll = dice->right();
        //view->displayCurrentTurn(); //UNIMPLEMENTED
        //queryPlayerForRoll(test) //just make black player type r
        //print right(black) die
        //game->passTurn(); //white's turn


        //}
        //while(whiteRoll == blackRoll);
        // ...

    //could write method to do the 5 lines above
    /////////////////////////////////////////////////




    //Print  white's turn
    //White player is asked to roll one die
    queryPlayerForRoll(test);
    
    //white player rolls one die, call game for die roll then print it to screen
    whiteRoll = getFirstDieRoll();

    //pass turn
    game->passTurn();

    //print black's turn
    //Black player is asked to roll one die
    queryPlayerForRoll(test);
    
    //Black player rolls one die, call game for die roll then print it to screen
    blackRoll = getFirstDieRoll();
    game->passTurn();

    //keep doing that until white and black dice rolls aren't the same.
  }while(whiteRoll == blackRoll);

  //if winner of rolls is black, passTurn is called
  //else passTurn is not called, meaning white won and remains in control of the turn.
  if(whiteRoll<blackRoll){
    game->passTurn();
  }

  std::string currPlayer =  game->getActiveColorString(); 
  std::cout << currPlayer << " won the roll and will start the game" << std::endl;
  //For this case, we actually need to feed prettyPrint the values since they
  ////aren't random here, they must be equal to the outcome of the first rolls.    
  game->getDice()->set(whiteRoll,blackRoll);
  game->getDice()->prettyPrint();
  
}

void Controller::queryPlayerForRoll(bool test){  
  //this should be it's own method (print current player's turn)
  //these also shouldn't be coupled; printing the curr player's turn is a side-effect
  std::string currPlayer =  game->getActiveColorString(); 
  std::cout << "It is:  "  << currPlayer << "'s Turn " << std::endl;
  std::cout << "Input R or r to roll" << std::endl;
  std::string* line =  new std::string();
  do{  

    std::cout << "Enter an R or an r" << std::endl;
    if(test){
      line->assign(1,'r');
    }else{
      getUserInputLine(line);
    }
    std::cout << "you entered: " << *line << std::endl;
 }while(inputValidationForDiceRollPrompt(line));

 std::cout << "Rolling..." << std::endl;
 delete line;

}

bool Controller::inputValidationForDiceRollPrompt(std::string* line){
  bool inputInvalidKeepLooping = false; //CLEANCODE: javabean predicate
  
//CLEANCODE: repetition of "line->at(0)".  
  //show intent by naming this. "firstCharOfInput"?
  //I feel fine about 'r' and 'R' being magic numbers, but I don't think Clean Code does...
  if (line->at(0)!='r' && line->at(0)!='R'){ 
      inputInvalidKeepLooping = true;     
  }

  return inputInvalidKeepLooping;
}

//should be as simple as game->getDice()->left();
//we don't want side effects like printing in a 'get' method
DieFace Controller::getFirstDieRoll(){ 
    DieFace dieRoll;
    game->getDice()->roll();
    dieRoll = game->getDice()->left();
    game->getDice()->prettyPrintOne(); 
    std::cout << std::endl; 
  return dieRoll;
}

void Controller::getUserInputLine(std::string* returnString){
    char * line = readline("> ");
    //!!!!!!
    // From http://cnswww.cns.cwru.edu/php/chet/readline/readline.html#SEC24 ...
    //    "If readline encounters an EOF while reading the line, and 
    //    the line is empty at that point, then (char *)NULL is returned. 
    //    Otherwise, the line is ended just as if a newline had been typed.""
    // this causes a segmentation fault as of 9:00 AM on 3/05 if [Ctrl D] is pressed
    *returnString = reinterpret_cast<char*>(line);
    free(line);
}
