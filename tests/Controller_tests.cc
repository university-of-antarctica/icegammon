#include "gtest/gtest.h"
#include "../include/Controller.h"
#include "../include/Game.h"
#include <unistd.h>
#include <string>
#include <sstream>
#include <iostream>
#include <thread>

#define WHITE_STONE 1
#define BLACK_STONE 0
#define LAST_ASCII_CHAR 127
#define LC_R 114
#define UC_R 82

TEST(Controller, verifyTurnStateStartsCorrectly){
  Game *g = new Game();
  Controller *controller = new Controller(g);

  EXPECT_EQ(1,g->getActiveColor())<<"First call to getActiveColor should be 1, for white";
}

TEST(Controller, verifyTurnsPassCorrectly){
  Game *g = new Game();
  Controller *controller = new Controller(g);
  
  g->passTurn();
  EXPECT_EQ(0,g->getActiveColor())<<"Second call to getActiveColor should be 0, for black";
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
    testValue = controller->inputValidationForDiceRollPrompt(&testLine);
    
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
  std::pair<DieFace,DieFace> diceRolls = controller->getFirstTurnRolls(true); 
  
  ASSERT_NE(diceRolls.first, diceRolls.second)<<"Rolls must be different to start game" ;
  
  if(diceRolls.first>diceRolls.second){
    EXPECT_EQ(WHITE_STONE,g->getActiveColor())<<"If white won then it should be their turn";
  }else{
    EXPECT_EQ(BLACK_STONE,g->getActiveColor())<<"If black won then it should be their turn";
  }

}
