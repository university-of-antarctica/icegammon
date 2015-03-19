#ifndef ICEGAMMON_PHASE_H_
#define ICEGAMMON_PHASE_H_

#include "Player.h"


  enum class PhaseType{ 
    // Start
    BeginGame,
    OpeningRollOne,
    OpeningRollTwo,
    FirstMove,
    // Normal turns
    BeginningOfTurn,
    Roll,
    Move,
    // Finish
    EndGame,
  };

  // Usage:
  // Phase phase = new BeginGamePhase();
  // Player white, black;
  // ...
  //
  // phase = phase.to( new OpeningRollOnePhase(white) );
  // ...
  // phase = phase.to( new OpeningRollTwoPhase(black) );
  // Player winningRoller = ...
  //
  //
  // phase = phase.to( new FirstMovePhase(winningRoller) );
  // //OR
  // phase = phase.to( new OpeningRollOnePhase() );
  class Phase{
    public:
      Phase();
      //Phase(Phase previousPhase) = 0;
      // Construct a phase from a previous phase
     // Phase to(PhaseType nextPhase) = 0;  // Alternative: argument is a Phase
      std::string toString();
    private:
      PhaseType part_of_turn;
      Player    player_on_turn;
      uint      turn_number;

  };

  class BeginGamePhase : public Phase {
    public:
      BeginGamePhase();
      Phase to(PhaseType nextPhaseType);
  };

  class OpeningRollOnePhase : public Phase {
    public:
      OpeningRollOnePhase();
      Phase to(PhaseType nextPhaseType);
  };

  class OpeningRollTwoPhase : public Phase {
    public:
      OpeningRollTwoPhase();
      Phase to(PhaseType nextPhaseType);
  };

  class FirstMovePhase : public Phase {
    public:
      FirstMovePhase();
      Phase to(PhaseType nextPhaseType);
  };
  /*
  
  class BeginTurnPhase : public Phase {
    public:
      BeginTurnPhase(Phase previousPhase);
  };

  class MovePhase : public Phase {
    public:
      MovePhase(Phase previousPhase);
  };
  
  class RollPhase : public Phase {
    public:
      RollPhase(Phase previousPhase);
  };

  class EndGamePhase : public Phase {
    public:
      EndGamePhase(Phase previousPhase);
  };
  */
#endif