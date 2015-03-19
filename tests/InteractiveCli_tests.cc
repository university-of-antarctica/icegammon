#include "gtest/gtest.h"
#include "../include/Dice.h"
#include "../include/Game.h"
#include "../include/InteractiveCli.h"
#include "../include/Turn.h"

#define LC_R 114
#define UC_R 82
#define LAST_ASCII_CHAR 127


TEST(InteractiveCli, verifyInputsForFirstTurn) {
  
  GameState *g = new GameState();
  InteractiveCli *cli= new InteractiveCli(g);
  bool testValue;
  // InputValidationForDiceRollPrompt only checks first char, // and returns true if first chars aren't 'r' or 'R'.
  
  std::string testLine; 
 
 for (int i = 0; i < LAST_ASCII_CHAR; ++i) {
    testLine.assign(1, i);
    testValue = cli->InputValidationForDiceRollPrompt(testLine);
    
    if ( i == UC_R) {
      EXPECT_EQ(false, testValue)<<"If input is 'R' return false so we stop looping";
    }
    if (i == LC_R) {
      EXPECT_EQ(false, testValue)<<"If input is 'r' return false so we stop looping";
    }
 
  }
}

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

TEST(Controller, validateInputForMoveObject) {
  GameState *g = new GameState();
  InteractiveCli *cli= new InteractiveCli(g);
  // test inputValidationForMoveObject();
  // This function returns FALSE if the input is VALID
  // and return TRUE if the input is INVALID
  // as it is the exit condition for a loop
  EXPECT_EQ(true, cli->InputValidationForMoveObjectPrompt("t 80 80"))<<"Invalid Input should return true";
  EXPECT_EQ(true, cli->InputValidationForMoveObjectPrompt("N 80 80"))<<"Invalid Input should return true";
  EXPECT_EQ(true, cli->InputValidationForMoveObjectPrompt("M 80 80"))<<"Invalid Input should return true";
  EXPECT_EQ(true, cli->InputValidationForMoveObjectPrompt("m XX ys90"))<<"Invalid Input should return true";
  EXPECT_EQ(true, cli->InputValidationForMoveObjectPrompt("m 8X0 90xx09"))<<"Invalid Input should return true";
  EXPECT_EQ(true, cli->InputValidationForMoveObjectPrompt("m 450X X80"))<<"Invalid Input should return true";
  EXPECT_EQ(true, cli->InputValidationForMoveObjectPrompt("m X80X X80s"))<<"Invalid Input should return true";
  EXPECT_EQ(true, cli->InputValidationForMoveObjectPrompt("m 80 0009"))<<"Invalid Input should return true";
  EXPECT_EQ(false, cli->InputValidationForMoveObjectPrompt("m 8 9"))<<"Valid Input should return false";
  EXPECT_EQ(false, cli->InputValidationForMoveObjectPrompt("m 0 49"))<<"Valid Input should return false";
  EXPECT_EQ(false, cli->InputValidationForMoveObjectPrompt("m 1 9"))<<"Valid Input should return false";
  EXPECT_EQ(false, cli->InputValidationForMoveObjectPrompt("m 12 18"))<<"Valid Input should return false";
  EXPECT_EQ(false, cli->InputValidationForMoveObjectPrompt("m 4 9"))<<"Valid Input should return false";
  EXPECT_EQ(false, cli->InputValidationForMoveObjectPrompt("m 19 22"))<<"Valid Input should return false";
  EXPECT_EQ(false, cli->InputValidationForMoveObjectPrompt("m 12 13"))<<"Valid Input should return false";
  EXPECT_EQ(false, cli->InputValidationForMoveObjectPrompt("m 1 9"))<<"Valid Input should return false";
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
