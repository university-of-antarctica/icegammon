#include "gtest/gtest.h"
#include "../include/Game.h"
#include "../include/Color.h"

TEST(Validation, isLegal) {
  GameState *g = new GameState();  // starting board
  GameLogic logic = GameLogic(g);
  Dice *d = g->getDice();
  d->set(ONE, SIX);

  bool legality;
  Move potentialMove;

  potentialMove = Move(1, 2);
  legality = logic.isLegal(&potentialMove);
  EXPECT_EQ(legality, true) << "black should be able to move from 1 to 2";
  
  legality = logic.isLegal(&potentialMove);
  EXPECT_EQ(legality, false) << "white shouldn't be able to move from 1 to 2 as black is on pip 1";

  potentialMove = Move(6, 3);
  legality = logic.isLegal(&potentialMove);
  EXPECT_EQ(legality, false) << "white shouldn't be able to move 3 spaces as the dice rolls are one and six";

  potentialMove = Move(6, 5);
  legality = logic.isLegal(&potentialMove);
  EXPECT_EQ(legality, true) << "white should be able to move 1 space in the wrong direction";
}
