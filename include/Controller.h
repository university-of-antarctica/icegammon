#ifndef ICEGAMMON_CONTROLLER_H_
#define ICEGAMMON_CONTROLLER_H_
#include <stdio.h>
#include <stdint.h>
#include <readline/readline.h>
#include <readline/history.h>
//#include "Turn.h"
//#include "Move.h"
#include "Game.h"
#include <iostream>
  
  class Controller{

  public:
  Controller(Game*);
  std::pair<uint8_t,uint8_t> getFirstTurn(bool);
  void queryPlayerForFirstRoll(bool);
  uint8_t getFirstDieRoll();
  bool inputValidationForDiceRollPrompt(std::string*);
  
  private:
  Game* game;
  void getUserInputLine(std::string*);
  };
#endif
