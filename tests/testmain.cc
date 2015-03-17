#include <stdio.h>
#include "gtest/gtest.h"
// #include "../src/*"
#include "../include/Board.h"
#include "../include/Color.h"
#include "../include/Game.h"
#include "../include/Dice.h"
#include "../include/utils.h"
#include "../include/AsciiView.h"

// TODO(lovestevend@gmail.com): include more intelligently, "../src/*" ?

GTEST_API_ int main(int argc, char **argv) {
  printf("Running tests from testmain.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


