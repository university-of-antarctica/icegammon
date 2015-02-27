#ifndef ICEGAMMON_CONTROLLER_H_
#define ICEGAMMON_CONTROLLER_H_
#include <stdio.h>
#include <stdint.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "Turn.h"
#include "Move.h"
#include <iostream>
  
  class Controller{

  public:
  void getRoll();

  private:
  void getUserInputLine();


  };
#endif
