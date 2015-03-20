#ifndef ICEGAMMON_GameplayFcn_H_
#define ICEGAMMON_GameplayFcn_H_

#include <stdint.h>
#include "Game.h"
#include "Dice.h"
#include "AsciiView.h"
#include "Move.h"
#include "Turn.h"
#include "InteractiveCli.h"
#include <cstdlib>
#include <utility>

class GameplayFcnInterface{
   public:
     virtual ~GameplayFcnInterface() {}
     virtual void ExecuteFcn() = 0;
};

struct InstanceVars{
  GameState *game;
  InteracticeCli *cli;

  InstanceVars(GameState *g, InteracticeCli *c) {
    game = g;
    cli = c;
  }
};


class GameplayFcnAnnounceTurnAbstract {
  public:
    GameplayFcnAnnounceTurnAbstract(InstanceVars *iv);
    virtual ~GameplayFcnAnnounceTurnAbstract(); //{do stuff}
};

class GameplayFcnDisplayBoardAbstract {
  public:
    GameplayFcnDisplayBoardAbstract(InstanceVars *iv);
    virtual ~GameplayFcnDisplayBoardAbstract(); //{do stuff}
};

class GameplayFcnRollForInitiativeAbstract {
  public:
    GameplayFcnRollForInitiativeAbstract(InstanceVars *iv);
    virtual ~GameplayFcnRollForInitiativeAbstract(); //{do stuff}
};

class GameplayFcnPerformFirstTurnAbstract {
  public:
    GameplayFcnPerformFirstTurnAbstract(InstanceVars *iv);
    virtual ~GameplayFcnPerformFirstTurnAbstract(); //{do stuff}
};

class GameplayFcnPerformTurnAbstract {
  public:
    GameplayFcnPerformTurnAbstract(InstanceVars *iv); 
    virtual ~GameplayFcnPerformTurnAbstract(); //{do stuff}
};

#endif
