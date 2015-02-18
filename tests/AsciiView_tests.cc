#include "gtest/gtest.h"
#include <string>
#include "../src/AsciiView.h"
//include asciiview source

TEST(AsciiView, InitialCount){
	//initialize a board
	//get a string from the view
	//decide what a white stone looks like
	//decide what a black stone looks like
	//iterate over the string and verify that there are 15 of each

	Board *b = new Board();
	AsciiView *v = new AsciiView(b);


	// Access members of AsciiView, sanity check them
	char whiteStone = v->whiteStone();
	EXPECT_GT(whiteStone,32)<<"white stone should be printable char";
	char blackStone = v->blackStone();
	EXPECT_GT(blackStone,32)<<"black stone should be printable char";
	std::string *s = v->toString();
	EXPECT_GE(s->length(),28)<<"Even the most minimalist design should have a char for each of the 28 locations on the board";


	// Count the occurrence of black and white stones on the board
	std::string::iterator it;
	int whiteCount, blackCount;
	char currentChar;
	for(it = s->begin(); it < s->end(); ++it){
		currentChar = *it;
		if(currentChar==whiteStone){
			++whiteCount;
		}
		if(currentChar==blackStone){
			++blackCount;
		}
	}

	// Verify that there are 15 of each
	EXPECT_EQ(whiteCount,15)<<"there should be 15 white stone characters";
	EXPECT_EQ(blackCount,15)<<"there should be 15 black stone characters";

	std::cout << *s;
}