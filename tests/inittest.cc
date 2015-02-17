//#include <stdio.h>
#include "../main.cc"
#include "gtest/gtest.h"

TEST(Initialization,Pip24){

	// ASSERT_EQ(preset(),5) << "preset was not 5";
	// EXPECT_EQ(4,preset()) << "should not work";

	Board *b = new Board();

	EXPECT_EQ(b->pips[24],2) <<  "we want 2 white stones on pip 24";

	b->initialize();

	ASSERT_EQ(b->pips[24],3) <<  "we better have 2 white stones on pip 24";

}

TEST(Initialization,WhiteCount){
	Board *b = new Board();
	b->initialize();

	// Count up the white stones
	int count = 0;
	int pipval;
	for(int i = 1; i < 25; ++i){
		pipval = b->pips[i];
		if(pipval > 0){ // white stones are here
			count += pipval;
		}
	}
	// now count = # white stones on the board

	ASSERT_EQ(count,15) <<  "we want 15 white stones on the board";

}