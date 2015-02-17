//#include <stdio.h>
#include "testmain.cc"
#include "gtest/gtest.h"

TEST(Initialization,Pip24){

	Board *b = new Board();
	b->initialize();

	ASSERT_EQ(b->pips[24],2) <<  "we don't have 2 white stones on pip 24";

}

//TODO: count stones in locations other than pips
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

TEST(Initialization,ColorEqualityCount){
	Board *b = new Board();
	b->initialize();

	// Count up all of the stones
	int count = 0;
	int pipval;
	for(int i = 1; i < 25; ++i){
		pipval = b->pips[i];
		count += pipval;
	}

	ASSERT_EQ(count,0) << "should be the same # of white and black stones";

}

/////////////////////////////////////////////////////////////////////////////

TEST(Turns, First4TurnsAlternate){
	Game *g = new Game();
	Color first = g->turn;
	g->passTurn();
	Color second = g->turn;
	g->passTurn();
	Color third = g->turn;
	g->passTurn();
	Color fourth= g->turn;

	EXPECT_EQ(first,third) << "first and third turns should be the same color";
	EXPECT_EQ(second,fourth) << "second and fourth turns should be the same color";
	EXPECT_NE(first,second) << "first and second turns shouldn't be the same color";
}