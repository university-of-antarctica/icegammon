#include "../include/Controller.h"

//TODO This class generates turn specific messages, need a method to do that
Controller::Controller(Game* game){
  Controller::game = game;
}
//TODO controller will call getNextTurn() and then decide if it is
//the first turn or the Nth turn.

std::pair<uint8_t,uint8_t> Controller::getFirstTurn(bool test){

uint8_t whiteRoll;
uint8_t blackRoll;
std::pair<uint8_t,uint8_t> firstTurnDiceValues;
 
 do{
    //Print  white's turn
    //White player is asked to roll one die
    queryPlayerForFirstRoll(test);
    
    //white player rolls one die, call game for die roll then print it to screen
    whiteRoll = getFirstDieRoll();

    //pass turn
    game->passTurn();

    //print black's turn
    //Black player is asked to roll one die
    queryPlayerForFirstRoll(test);
    
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

uint8_t Controller::getFirstDieRoll(){
    uint8_t dieRoll;
    game->getDice()->roll();
    dieRoll = game->getDice()->left();
    game->getDice()->prettyPrintOne(); 
    std::cout << std::endl; 
  return dieRoll;
}

bool Controller::inputValidationForDiceRollPrompt(std::string* line){
  bool inputInvalidKeepLooping = false;
  
  
  if (line->at(0)!='r' && line->at(0)!='R'){
    inputInvalidKeepLooping = true;
  }

  return inputInvalidKeepLooping;
}

void Controller::queryPlayerForFirstRoll(bool test){  
 std::string currPlayer =  game->getActiveColorString(); 
  std::cout << "It is:  "  << currPlayer << "'s Turn " << std::endl;
  std::cout << "Input R or r to roll for first move" << std::endl;
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


void Controller::getUserInputLine(std::string* returnString){
    char * line = readline("> ");
    *returnString = reinterpret_cast<char*>(line);
    free(line);
}
