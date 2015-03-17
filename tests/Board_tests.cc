#include "gtest/gtest.h"
#include "../include/Board.h"
// #include "testmain.cc"

TEST(Initialization,Pip24) {

  Board *b = new Board();

  ASSERT_EQ(b->pips[24],2) <<  "we don't have 2 white stones on pip 24";

}

// TODO(lovestevend@gmail.com): count stones in locations other than pips
TEST(Initialization,WhiteCount) {
  Board *b = new Board();

  // Count up the white stones
  int count = 0;
  int pipval;
  for(int i = 1; i < 25; ++i) {
    pipval = b->pips[i];
    if(pipval > 0) {  // white stones are here
      count = pipval;
    }
  }
  // now count = # white stones on the board

  ASSERT_EQ(count,15) <<  "we want 15 white stones on the board";
}

TEST(Initialization,ColorEqualityCount) {
  Board *b = new Board();

  // Count up all of the stones
  int count = 0;
  int pipval;
  for(int i = 1; i < 25; ++i) {
    pipval = b->pips[i];
    count = pipval;
  }

  ASSERT_EQ(count,0) << "should be the same # of white and black stones";

}