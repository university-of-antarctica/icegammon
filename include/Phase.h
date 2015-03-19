#ifndef ICEGAMMON_PHASE_H_
#define ICEGAMMON_PHASE_H_

#include "Player.h"
#include "Color.h"
#include <exception>
#include <string>
#include <iostream>
#include <cinttypes>

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

const Color kFirstColorOnTurn = Color::WHITE;
const uint kFirstTurnNumber = 1;
const PhaseType kFirstPhaseType = PhaseType::BeginGame;

  class Phase{
     public:
      Phase();
      std::string toString();
      //virtual Phase fromPrevPhase(Phase prevPhase) = 0;
      // virtual Phase to(Phase& nextPhase);


      Player player_on_turn() const { return player_on_turn_; }
      void set_player_on_turn(Player player) { player_on_turn_ = player; }
      PhaseType part_of_turn() const { return part_of_turn_; }
      void set_part_of_turn(PhaseType phase) { part_of_turn_ = phase; }
      uint turn_number() const { return turn_number_; }
      void set_turn_number(uint turnNumber) {turn_number_ = turnNumber; }

      void IncrementTurn(){ ++turn_number_; }
      void SwitchPlayer();
      // void Proceed();
      // void Reroll();
      // void End();


   
    protected:
      PhaseType part_of_turn_;
      Player    player_on_turn_;
      uint      turn_number_;

  };/*

  class BeginGamePhase;
  class OpeningRollOnePhase;

  class BeginGamePhase : public Phase {
    public:
      BeginGamePhase();
      std::string toString() override;
      Phase to(OpeningRollOnePhase &nextPhase);
      //Phase to(PhaseType nextPhaseType);
  };

  class OpeningRollOnePhase : public Phase {
    public:
      OpeningRollOnePhase();
      Phase to(BeginGamePhase &nextPhase);
      Phase to(OpeningRollOnePhase &nextPhase);
      std::string toString() override;
     // Phase to(PhaseType nextPhaseType);
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