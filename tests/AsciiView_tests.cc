#include "gtest/gtest.h"
#include <string>
#include "../include/AsciiView.h"
#include "../include/Game.h"
// include asciiview source

TEST(AsciiView, InitialCount) {
  // initialize a board
  // get a string from the view
  // decide what a white stone looks like
  // decide what a black stone looks like
  // iterate over the string and verify that there are 15 of each

  GameState *g = new GameState();
  AsciiView *v = new AsciiView(g);

  std::string s = v->ToString();

  // Count the occurrence of black and white stones on the board
  EXPECT_EQ(v->whiteStoneCount(), 15)<<"there should be 15 white stone characters";
  EXPECT_EQ(v->blackStoneCount(), 15)<<"there should be 15 black stone characters";

  // Access members of AsciiView, sanity check them
  // THESE TESTS MUST BE CALLED AFTER STONE COUNT
  char whiteStone = v->whiteStone();
  EXPECT_GT(whiteStone, 32) << "white stone should be printable char";
  EXPECT_LT(whiteStone, 127) << "white stone should be printable char";
  char blackStone = v->blackStone();
  EXPECT_GT(blackStone, 32) << "black stone should be printable char";
  EXPECT_LT(blackStone, 127) << "black stone should be printable char";

  std::cout << s;
}
