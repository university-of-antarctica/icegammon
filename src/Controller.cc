#include "../include/Controller.h"
#include "../include/Move.h"
#include "../include/Turn.h"

void Controller::getRoll(){
  std::cout << "Input R or r to roll for first move" << std::endl;
}

void Controller::getUserInputLine(){

  while(1){
    
    char * line = readline("> ");
    if(!line) break;
    if(*line) add_history(line);
    /* Do something with the line here */
    std::cout << line << std::endl;  
    free(line);
  }
}
