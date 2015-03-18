#include "gtest/gtest.h"
#include "../include/Game.h"
#include "../include/Controller.h"
#include "../include/AsciiView.h"
#include <ctime> 
#include <cstdlib> // abs

TEST(Turns, First4TurnsAlternate) {
  Game *g = new Game();

  Color first = g->getActiveColor();
  g->passTurn();
  Color second = g->getActiveColor();
  g->passTurn();
  Color third = g->getActiveColor();
  g->passTurn();
  Color fourth= g->getActiveColor();

  EXPECT_EQ(first, third) << "first and third turns should be the same color";
  EXPECT_EQ(second, fourth) << "second and fourth turns should be the same color";
  EXPECT_NE(first, second) << "first and second turns shouldn't be the same color";
}

TEST(Turns, EvenOddRandomized) {
  Game *g = new Game();

  srand(time(NULL));
  Color first = g->getActiveColor();
  g->passTurn();
  Color second = g->getActiveColor();

  int n = rand() % 1000;  // in the range between 0 and 999
  for (int i = 0; i < n; ++i) {
    g->passTurn();
  }

  // if n is odd, then the color should be same as the first color
  // if n is even, then the color should be the same as the second color

  if (n%2 == 1) {  // n is odd
    EXPECT_EQ(first, g->getActiveColor()) << "all odd numbered turns should be the same color";
  } else {  // n is even
    EXPECT_EQ(second, g->getActiveColor()) << "all even numbered turns should be the same color";
  }
  EXPECT_NE(first, second) << "first and second turns shouldn't be the same color";

}

TEST(Turns, validationForTurnSubmission) {
  // test submitTurn();

}

TEST(Moving, BasicFirstMove) {
  Game* g = new Game();
  bool success;
  Move move;
  Board* b = g->getBoard();

  // Before move
  EXPECT_EQ(b->pips[1], -2)<< "there should be 2 black stones on pip 1";
  EXPECT_EQ(b->pips[3], 0)<< "there shouldnt be any stones on pip 3";

  move = Move(1, 3);
  success = g->moveStone(&move );

  // After move
  EXPECT_EQ(success, true)<<"black should be able to move forward 2 pips";
  EXPECT_EQ(b->pips[1], -1)<< "there should be 1 remaining black stone on pip 1";
  EXPECT_EQ(b->pips[3], -1)<< "there should now be 1 black stone on pip 3";
}

TEST(Moving, RandomMoves) {
  Game *g = new Game();
  Board *b = g->getBoard();
  srand(time(NULL));
  int source, dest;
  int sourceNumBefore, destNumBefore;
  int sourceNumAfter , destNumAfter;
  int totalBarsBefore, totalBarsAfter;
  bool success;

  // make random moves
  for (int i = 0; i < 100; ++i) {

    source = rand()%24+1;  // 1 to 24
    dest   = rand()%24+1;  // 1 to 24

    sourceNumBefore = std::abs(b->pips[source]);
    destNumBefore   = std::abs(b->pips[dest]);
    totalBarsBefore = b->bars[0]+b->bars[1];
    
    Move move = Move(source, dest);
    success = g->moveStone(&move);

    sourceNumAfter = std::abs(b->pips[source]);
    destNumAfter   = std::abs(b->pips[dest]);
    totalBarsAfter = b->bars[0]+b->bars[1];

    bool blotted;


    if (success) {
      std::cout << "(" << source << " to " << dest << ")" <<std::endl;

      EXPECT_EQ( sourceNumBefore-1, sourceNumAfter);

      blotted = (totalBarsAfter > totalBarsBefore);
      if (blotted) {
        EXPECT_EQ( totalBarsBefore+1, totalBarsAfter);
        EXPECT_EQ( destNumBefore, destNumAfter);
      } else {
        EXPECT_EQ( destNumBefore+1, destNumAfter);
        EXPECT_EQ( totalBarsBefore, totalBarsAfter);
      }
    } else {
      EXPECT_EQ(sourceNumBefore, sourceNumAfter);
      EXPECT_EQ(destNumBefore, destNumAfter);
    }
  }

  // test counts
  int whitecount = 0;
  int blackcount = 0;
  int pipval;
  for (int i = 1; i < 25; ++i) {
    pipval = b->pips[i];
    if(pipval > 0) {
      whitecount += pipval;
    }
    else{
      blackcount -= pipval;
    }
  }
  whitecount += b->bars[0];
  blackcount += b->bars[1];

  EXPECT_EQ(whitecount, blackcount) << "there should still be the same # of white and black stones";
  EXPECT_EQ(whitecount, 15) << "there should still be 15 white stones";
  EXPECT_EQ(blackcount, 15) << "there should still be 15 black stones";

  AsciiView *v = new AsciiView(g);
  std::cout << v->toString() << std::endl;

}

