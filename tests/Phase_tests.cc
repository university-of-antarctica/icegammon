#include "gtest/gtest.h"
#include "../include/Game.h"
#include "../include/Phase.h"
#include <iostream>


TEST(Phase, basicTurnProgression) {

  GameState *g = new GameState();
  Phase* phase = g->phase_;
  // std::cout << phase->toString() << std::endl;
  ASSERT_EQ(phase->turn_number(), 1);

  phase->IncrementTurn();
  ASSERT_EQ(phase->turn_number(), 2);

    // std::cout << phase->toString() << std::endl;
  phase->SwitchPlayer();
    phase->IncrementTurn();

  ASSERT_EQ(phase->turn_number(), 3);

    // std::cout << phase->toString() << std::endl;
    MovePhase* m = new MovePhase(); //TODO (lovestevend@gmail.com) remove memory leak!
  phase->set_part_of_turn( m );
    ASSERT_EQ(phase->turn_number(), 3);

    // std::cout << phase->toString() << std::endl;


  // std::cout << "first phase: " << phase.toString() << std::endl;

  // phase = phase.to(OpeningRollOnePhase());
  // phase.toString();

  // phase = phase.to(OpeningRollOnePhase());
  // phase.toString();

  // phase = phase.to(OpeningRollOnePhase());
  // phase.toString();

  // phase = phase.to(OpeningRollOnePhase());
  // phase.toString();

  // phase = phase.to(BeginGamePhase());
  // phase.toString();

  // phase = phase.to(OpeningRollOnePhase());
  // phase.toString();

  // phase = phase.to(OpeningRollOnePhase());
  // phase.toString();

  // phase = OpeningRollOnePhase(phase)
  //phase = phase.to(OpeningRollOnePhase())

}