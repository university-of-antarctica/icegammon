#include <stdio.h>
#include "gtest/gtest.h"
#include "../src/Board.cc"

GTEST_API_ int main(int argc, char **argv) {
  printf("Running tests from testmain.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


