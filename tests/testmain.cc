#include <stdio.h>
#include "gtest/gtest.h"
#include "../src/Board.cc"
#include "../src/Color.cc"
#include "../src/Game.cc"

//TODO: include more intelligently, "../src/*" ?

GTEST_API_ int main(int argc, char **argv) {
  printf("Running tests from testmain.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


