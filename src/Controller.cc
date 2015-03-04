#include "../include/Controller.h"

//TODO This class generates turn specific messages, need a method to do that
Controller::Controller(Game* game){
  Controller::game = game;
}

bool Controller::getTurn(bool test){
 bool activeGame = true; //TODO: decide on logic for game end 
//ask activePlayer to roll
  queryPlayerForRoll(test);
//actuallyRollTheDice
  game->getDice()->roll();

//ask activePlayer for series of move tokens corresponding to roll
  Turn *turnObj = queryPlayerForMoveObject(test);
//parse move tokens into move objects into turn object
//submit turn object to game
  game->submitTurn(turnObj);
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
         // line->assign(1,'r'); //figure out simple valid move syntax
       }else{
          getUserInputLine(line);
       }
      std::cout << "you entered: " << *line << std::endl;
    }while(inputValidationForMoveObject(line));//not implemented

    Move *moveObj = parseMove(line); //not implemented
    turnObj->moves[i] = moveObj;//TODO: is this making a deep copy of the moveObj? if so we need to delete it   
  }
 delete line;

 return turnObj;
}

Move* Controller::parseMove(std::string* line){
  Move *moveObj = new Move();
//needs to allocate new move on the heap
//and return that object
  return moveObj;
}

bool Controller::inputValidationForMoveObject(std::string *line){
  bool validMove = false;

  return validMove;
}

void Controller::getFirstTurn(bool test){
  Turn *turnObj = queryPlayerForMoveObject(test); 
  game->submitTurn(turnObj);
  game->passTurn();
}

int Controller::getNumMoves(){
  int numMoves = 0;
  game->getDice()->left();
  game->getDice()->right();
  return numMoves;
}

std::pair<DieFace,DieFace> Controller::getFirstTurnRolls(bool test){

  DieFace whiteRoll;
  DieFace blackRoll;
  std::pair<DieFace,DieFace> firstTurnDiceValues;
 
  do{
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
  firstTurnDiceValues.first = whiteRoll;
  firstTurnDiceValues.second = blackRoll;

  return firstTurnDiceValues;
}

void Controller::queryPlayerForRoll(bool test){  
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
  bool inputInvalidKeepLooping = false;
  
  if (line->at(0)!='r' && line->at(0)!='R'){
    inputInvalidKeepLooping = true;
  }

  return inputInvalidKeepLooping;
}

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
    *returnString = reinterpret_cast<char*>(line);
    free(line);
}