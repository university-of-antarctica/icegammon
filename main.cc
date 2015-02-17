#include <stdio.h>

#include "gtest/gtest.h"

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from gtest_main.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}



class Board{
	
	public:
		int pips[25]={0}; //0 unused
		int homes[2]={0}; //white is 0, black is 1
		int bars[2]={0};  //white is 0, black is 1

		void initialize(){
			pips[24] =  2; // 2 white stones on pip 24
			pips[19] = -5; // 5 black stones on pip 19
			pips[17] = -3; // ...
			pips[13] =  5;
			pips[12] = -5;
			pips[8]  = -3;
			pips[6]  =  5;
			pips[1]  = -2;
		};
};