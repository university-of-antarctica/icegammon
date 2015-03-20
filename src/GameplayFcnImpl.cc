#include "../include/GameplayGameplayFcn.h"

// http://stackoverflow.com/questions/318064/how-do-you-declare-an-interface-in-c

class AnnounceTurnImpl : public GameplayFcnAnnounceTurnAbstract, public GameplayFcnInterface {
  public:
    GameplayFcnAnnounceTurnAbstract(InstanceVars *iv);
    virtual ~GameplayFcnAnnounceTurnAbstract(); //{do stuff}
};

class DisplayBoardImpl : public GameplayFcnDisplayBoardAbstract, public GameplayFcnInterface {
  public:
    GameplayFcnDisplayBoardAbstract(InstanceVars *iv);
    virtual ~GameplayFcnDisplayBoardAbstract(); //{do stuff}
};

class RollForInitiativeImpl : public GameplayFcnRollForInitiativeAbstract, public GameplayFcnInterface {
  public:
    GameplayFcnRollForInitiativeAbstract(InstanceVars *iv);
    virtual ~GameplayFcnRollForInitiativeAbstract(); //{do stuff}
};

class PerformFirstTurnImpl : public GameplayFcnPerformFirstTurnAbstract, public GameplayFcnInterface {
  public:
    GameplayFcnPerformFirstTurnAbstract(InstanceVars *iv);
    virtual ~GameplayFcnPerformFirstTurnAbstract(); //{do stuff}
};

class AnnounceTurnImpl : public GameplayFcnPerformTurnAbstract, public GameplayFcnInterface {
  public:
    GameplayFcnPerformTurnAbstract(InstanceVars *iv); 
    virtual ~GameplayFcnPerformTurnAbstract(); //{do stuff}
};

