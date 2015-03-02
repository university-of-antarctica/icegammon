#include "../include/Controller.h"

//TODO This class generates turn specific messages, need a method to do that

Controller::Controller(Game* game){
  Controller::game = game;
}
//TODO controller will call getNextTurn() and then decide if it is
//the first turn or the Nth turn.

void Controller::getFirstTurn(){
    //Print  white's turn
    //White player is asked to roll one die
    //white player rolls one die, call game for die roll then print it to screen
    //print black's turn
    //Black player is asked to roll one die
    //Black player rolls one die, call game for die roll then print it to screen
    //keep doing that until white and black dice rolls aren't the same.
    //if winner of rolls is white, passTurn is called
    //else passTurn is not called, meaning black won and remains in control of the turn.

}

void Controller::queryPlayerForFirstRoll(Color activeColor){  
  std::cout << "Input R or r to roll for first move" << std::endl;
  std::string* line =  new std::string();
  do{  void queryPlayerForFirstRoll(Color activeColor);

    std::cout << "Enter an R or an r" << std::endl;
    getUserInputLine(line);
    std::cout << "you entered: " << *line << std::endl;
 
 }while(line->at(0)!='r' && line->at(0)!='R');

 std::cout << "user entered r or R" << std::endl;
 delete line;

}


void Controller::getUserInputLine(std::string* returnString){
    char * line = readline("> ");
    *returnString = reinterpret_cast<char*>(line);
    free(line);
}
