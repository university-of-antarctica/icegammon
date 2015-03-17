#include "gtest/gtest.h"
#include "../include/Controller.h"
#include "../include/Game.h"
#include "../include/Move.h"
#include "../include/Color.h"
#include <unistd.h>
#include <string>
#include <sstream>
#include <iostream>
#include <thread>
#include "../include/Dice.h"

#define LAST_ASCII_CHAR 127
#define LC_R 114
#define UC_R 82

TEST(Controller, verifyTurnStateStartsCorrectly){
  Game *g = new Game();
  EXPECT_EQ(Color::WHITE,g->getActiveColor())<<"First call to getActiveColor should be white";
}

TEST(Controller, verifyTurnsPassCorrectly){
  Game *g = new Game();
  g->passTurn();
  EXPECT_EQ(Color::BLACK,g->getActiveColor())<<"Second call to getActiveColor should be black";
}

TEST(Controller,GetOneDieTest){
  Game *g = new Game();
  Controller *controller = new Controller(g);
  DieFace sampleDieRoll;
  
  for(int i = 0; i < 10; ++i){
    sampleDieRoll = controller->getFirstDieRoll();
    EXPECT_GT(sampleDieRoll,0)<<"Die roll must be greater than 0";
    EXPECT_LT(sampleDieRoll,7)<<"Die roll must be smaller than 7";
  }

}

TEST(Controller,verifyInputsForFirstTurn){
  
  Game *g = new Game();
  Controller *controller = new Controller(g);
  bool testValue;
  //InputValidationForDiceRollPrompt only checks first char,
  //and returns true if first chars aren't 'r' or 'R'.
  
  std::string testLine; 
 
 for(int i = 0; i < LAST_ASCII_CHAR; ++i){
    testLine.assign(1,i);
    testValue = controller->inputValidationForDiceRollPrompt(testLine);
    
    if( i == UC_R){
      EXPECT_EQ(false,testValue)<<"If input is 'R' return false so we stop looping";
    }
    if(i == LC_R){
      EXPECT_EQ(false,testValue)<<"If input is 'r' return false so we stop looping";
    }
 
  }
}

TEST(Controller, verifyPostFirstTurnState){
  Game *g = new Game();
  Controller *controller = new Controller(g);
  controller->getFirstTurnRolls(true); 
  
  ASSERT_NE(g->getDice()->left(), g->getDice()->right())<<"Rolls must be different to start game" ;
  
  if(g->getDice()->left() > g->getDice()->right()){
    EXPECT_EQ(Color::WHITE,g->getActiveColor())<<"If white won then it should be their turn";
  }else{
    EXPECT_EQ(Color::BLACK,g->getActiveColor())<<"If black won then it should be their turn";
  }

}

TEST(Controller, isInvalidTest){
  //test isInvalid
  bool test = true;
  Game *g = new Game();
  Controller *c = new Controller(g);
  Turn *turnObj = c->isInvalid(test);
  for(int i = 0; i < 2; ++i){
    EXPECT_EQ(1,turnObj->moves[i]->sourcePipNum)<<"Source pip should be 1";   
    EXPECT_EQ(11,turnObj->moves[i]->destPipNum)<<"Dest pip should be 11";

  }
}

TEST(Controller, validateInputForMoveObject){
  Game *g = new Game();
  Controller *c = new Controller(g);
  // test inputValidationForMoveObject();
  //This function returns FALSE if the input is VALID
  //and return TRUE if the input is INVALID
  //as it is the exit condition for a loop
  EXPECT_EQ(true,c->inputValidationForMoveObject("t 80 80"))<<"Invalid Input should return true";
  EXPECT_EQ(true,c->inputValidationForMoveObject("N 80 80"))<<"Invalid Input should return true";
  EXPECT_EQ(true,c->inputValidationForMoveObject("M 80 80"))<<"Invalid Input should return true";
  EXPECT_EQ(true,c->inputValidationForMoveObject("m XX ys90"))<<"Invalid Input should return true";
  EXPECT_EQ(true,c->inputValidationForMoveObject("m 8X0 90xx09"))<<"Invalid Input should return true";
  EXPECT_EQ(true,c->inputValidationForMoveObject("m 450X X80"))<<"Invalid Input should return true";
  EXPECT_EQ(true,c->inputValidationForMoveObject("m X80X X80s"))<<"Invalid Input should return true";
  EXPECT_EQ(true,c->inputValidationForMoveObject("m 80 0009"))<<"Invalid Input should return true";

  EXPECT_EQ(false,c->inputValidationForMoveObject("m 8 9"))<<"Valid Input should return false";
  EXPECT_EQ(false,c->inputValidationForMoveObject("m 0 49"))<<"Valid Input should return false";
  EXPECT_EQ(false,c->inputValidationForMoveObject("m 1 9"))<<"Valid Input should return false";
  EXPECT_EQ(false,c->inputValidationForMoveObject("m 12 18"))<<"Valid Input should return false";
  EXPECT_EQ(false,c->inputValidationForMoveObject("m 4 9"))<<"Valid Input should return false";
  EXPECT_EQ(false,c->inputValidationForMoveObject("m 19 22"))<<"Valid Input should return false";
  EXPECT_EQ(false,c->inputValidationForMoveObject("m 12 13"))<<"Valid Input should return false";
  EXPECT_EQ(false,c->inputValidationForMoveObject("m 1 9"))<<"Valid Input should return false";
 
}

TEST(Controller,verifyGetNumMoves){
  Game *g = new Game();
  Controller *c = new Controller(g);
  int numMoves;
  
  
  for(int i = 1; i < 7; ++i){
    for(int j =1; j < 7; ++j){
      //verify DieFace cast works
      g->getDice()->set((DieFace)i, (DieFace)j);
      numMoves = c->getNumMoves();
      if(i==j){ 
        EXPECT_EQ(numMoves,4);
      }else{
        EXPECT_EQ(numMoves,2);
      }
    }
  }
}

TEST(Controller,parseMoveValidation){
  //test parseMove();
  Game *g = new Game();
  Controller *c = new Controller(g);

  int testSource = 8;
  int testDest = 9;
  Move *moveObj = c->parseMove("m 8 9");
  
  EXPECT_EQ(testSource,moveObj->sourcePipNum)<<"Source pip number should match test provided token";
  EXPECT_EQ(testDest,moveObj->destPipNum)<<"Dest pip number should match test provided token";

  testSource = 6;
  testDest = 15;
  moveObj = c->parseMove("m 6 15");
  
  EXPECT_EQ(testSource,moveObj->sourcePipNum)<<"Source pip number should match test provided token";
  EXPECT_EQ(testDest,moveObj->destPipNum)<<"Dest pip number should match test provided token";

  testSource = 18;
  testDest = 22;
  moveObj = c->parseMove("m 18 22");
  
  EXPECT_EQ(testSource,moveObj->sourcePipNum)<<"Source pip number should match test provided token";
  EXPECT_EQ(testDest,moveObj->destPipNum)<<"Dest pip number should match test provided token";

}
