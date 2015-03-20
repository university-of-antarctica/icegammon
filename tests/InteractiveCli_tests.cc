#include "gtest/gtest.h"
#include "../include/Dice.h"
#include "../include/Game.h"
#include "../include/InteractiveCli.h"
#include "../include/Turn.h"

TEST(GameplayController, parseMoveValidation) {
  // test ParseMoveString();
  GameState *g = new GameState();
  InteractiveCli *cli= new InteractiveCli(g);

  int testSource = 8;
  int testDest = 9;
  Move *moveObj = cli->ParseMoveString("m 8 9");
  
  EXPECT_EQ(testSource, moveObj->sourcePipNum)<<"Source pip number should match test provided token";
  EXPECT_EQ(testDest, moveObj->destPipNum)<<"Dest pip number should match test provided token";

  testSource = 6;
  testDest = 15;
  moveObj = cli->ParseMoveString("m 6 15");
  
  EXPECT_EQ(testSource, moveObj->sourcePipNum)<<"Source pip number should match test provided token";
  EXPECT_EQ(testDest, moveObj->destPipNum)<<"Dest pip number should match test provided token";

  testSource = 18;
  testDest = 22;
  moveObj = cli->ParseMoveString("m 18 22");
  
  EXPECT_EQ(testSource, moveObj->sourcePipNum)<<"Source pip number should match test provided token";
  EXPECT_EQ(testDest, moveObj->destPipNum)<<"Dest pip number should match test provided token";

}
