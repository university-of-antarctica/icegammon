#include "gtest/gtest.h"
#include "../include/Dice.h"
#include "../include/Game.h"
#include "../include/InteractiveCli.h"
#include "../include/Turn.h"

TEST(InteractiveCli, PromptPlayerForMoveObjects) {
  // test PromptPlayerForMoveObjects 
  // TODO(gpwclark@gmail.com) more dynamic test,
  // only verified one move token,
  // loop only goes 2 times, will need to go 0-4 eventually depending
  // on the roll.
  
  bool test = true;
  GameState *g = new GameState();
  InteractiveCli *cli= new InteractiveCli(g);
  Turn *turnObj = cli->PromptPlayerForTurnObject(test,2);
  for (int i = 0; i < 2; ++i) {
    EXPECT_EQ(1, turnObj->moves[i]->sourcePipNum)<<"Source pip should be 1";   
    EXPECT_EQ(11, turnObj->moves[i]->destPipNum)<<"Dest pip should be 11";

  }
}

TEST(Controller, parseMoveValidation) {
  // test parseMove();
  GameState *g = new GameState();
  InteractiveCli *cli= new InteractiveCli(g);

  int testSource = 8;
  int testDest = 9;
  Move *moveObj = cli->ParseMove("m 8 9");
  
  EXPECT_EQ(testSource, moveObj->sourcePipNum)<<"Source pip number should match test provided token";
  EXPECT_EQ(testDest, moveObj->destPipNum)<<"Dest pip number should match test provided token";

  testSource = 6;
  testDest = 15;
  moveObj = cli->ParseMove("m 6 15");
  
  EXPECT_EQ(testSource, moveObj->sourcePipNum)<<"Source pip number should match test provided token";
  EXPECT_EQ(testDest, moveObj->destPipNum)<<"Dest pip number should match test provided token";

  testSource = 18;
  testDest = 22;
  moveObj = cli->ParseMove("m 18 22");
  
  EXPECT_EQ(testSource, moveObj->sourcePipNum)<<"Source pip number should match test provided token";
  EXPECT_EQ(testDest, moveObj->destPipNum)<<"Dest pip number should match test provided token";

}
