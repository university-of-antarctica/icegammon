#include "gtest/gtest.h"
#include "../include/GameplayController.h"
#include "../include/Game.h"
#include "../include/Move.h"
#include "../include/Color.h"
#include <unistd.h>
#include <string>
#include <sstream>
#include <iostream>
#include <thread>
#include "../include/Dice.h"


TEST(GameplayController, verifyTurnStateStartsCorrectly) {
  GameState *g = new GameState();
  EXPECT_EQ(Color::WHITE, g->getActiveColor())<<"First call to getActiveColor should be white";
}

TEST(GameplayController, verifyTurnsPassCorrectly) {
  GameState *g = new GameState();
  g->passTurn();
  EXPECT_EQ(Color::BLACK, g->getActiveColor())<<"Second call to getActiveColor should be black";
}

TEST(GameplayController, GetOneDieTest) {
  GameState *g = new GameState();
  GameplayController *controller = new GameplayController(g);
  DieFace sampleDieRoll;
  
  for (int i = 0; i < 10; ++i) {
    sampleDieRoll = controller->GetDieRoll();
    EXPECT_GT(sampleDieRoll, 0)<<"Die roll must be greater than 0";
    EXPECT_LT(sampleDieRoll, 7)<<"Die roll must be smaller than 7";
  }

}


TEST(GameplayController, verifyPostFirstTurnState) {
  GameState *g = new GameState();
  GameplayController *controller = new GameplayController(g);
  controller->RollForInitiative(true); 
  
  ASSERT_NE(g->getDice()->left(), g->getDice()->right())<<"Rolls must be different to start game" ;
  
  if (g->getDice()->left() > g->getDice()->right()) {
    EXPECT_EQ(Color::WHITE, g->getActiveColor())<<"If white won then it should be their turn";
  }else{
    EXPECT_EQ(Color::BLACK, g->getActiveColor())<<"If black won then it should be their turn";
  }

}

TEST(GameplayController, verifyGetNumMoves) {
  GameState *g = new GameState();
  GameplayController *c = new GameplayController(g);
  int numMoves;
  
  for(int i = 1; i < 7; ++i) {
    for(int j = 1; j < 7; ++j) {
      // verify DieFace cast works
      g->getDice()->set((DieFace)i, (DieFace)j);
      numMoves = c->GetNumMoves();
      if( i == j ) { 
        EXPECT_EQ(numMoves,4);
      }else{
        EXPECT_EQ(numMoves, 2);
      }
    }
  }
}

