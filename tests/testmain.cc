#include <stdio.h>
#include "gtest/gtest.h"
// #include "../src/*"
#include "../src/Board.h"
#include "../src/Color.h"
#include "../src/Game.h"
#include "../src/Dice.h"
#include "../src/utils.h"

//TODO: include more intelligently, "../src/*" ?

GTEST_API_ int main(int argc, char **argv) {
  printf("Running tests from testmain.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


