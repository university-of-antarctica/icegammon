//#include <stdio.h> //
#include <stdlib.h> //rand, srand
#include "testmain.cc"
#include "gtest/gtest.h"
#include "../src/utils.cc"
//for dice rolls
#include <numeric> 
#include <algorithm>
#include <cmath>
#include <vector>

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

TEST(Turns, EvenOddRandomized){
	Game *g = new Game();
	Color first = g->turn;
	g->passTurn();
	Color second = g->turn;

	int n = rand() % 1000; //in the range between 0 and 999
	for(int i = 0; i < n; ++i){
		g->passTurn();
	}

	//if n is odd, then the color should be same as the first color
	//if n is even, then the color should be the same as the second color
	if(n%2==1){//n is odd
		EXPECT_EQ(first,g->turn)<< "all odd numbered turns should be the same color";
	}
	else{//n is even
		EXPECT_EQ(second,g->turn) << "all even numbered turns should be the same color";
	}
	EXPECT_NE(first,second) << "first and second turns shouldn't be the same color";

}

///////////////////////////////////////////////////////////////////////
TEST(DiceRolls,VerifyValidDiceValues){

Dice *d = new Dice();
std::pair<uint8_t,uint8_t> returnedRoll;
d->roll();
uint8_t firstRoll = d->left();
uint8_t secondRoll = d->right();
EXPECT_LE(firstRoll,6);
EXPECT_LE(secondRoll,6);
EXPECT_GE(firstRoll,1);
EXPECT_GE(secondRoll,1);

}

TEST(DiceRolls,MeanAndStdDev){
//TODO: As of now this is a sanity check, it needs to be much more statistically valid in the future

// Parameters
int numberOfRolls = 1000;
double mean_tolerance = 0.2;
double stdev_tolerance = 0.2;

// Declarations
Dice *d = new Dice();
std::pair<uint8_t,uint8_t> returnedRoll;
uint8_t firstRoll, secondRoll;
std::vector<double> vectorOfRolls; //removed the (numberOfRolls) construction argument.  It was initializing the vector with <numberOfRolls> zeros.

// Roll dice a bunch of times
for(int i = 0; i < (numberOfRolls/2) ; i = i + 1 ){
  d->roll();
  firstRoll  = d->left();
  secondRoll = d->right();
  vectorOfRolls.push_back( (double) firstRoll);
  vectorOfRolls.push_back( (double) secondRoll);
}

// Calculate statistics
double mean  = utils_mean(vectorOfRolls);
double stdev = utils_stddev(vectorOfRolls);

// Expected results 
// from (http://www.futureaccountant.com/theory-of-expectation-random-variable/problems-solutions/throwing-rolling-dice.php#.VOQF0jVTdNA)
double mean_actual  = 3.5; 
double stdev_actual = 1.709;


EXPECT_GE(mean,mean_actual - mean_tolerance);
EXPECT_LE(mean,mean_actual + mean_tolerance);

EXPECT_GE(stdev,stdev_actual - stdev_tolerance);
EXPECT_LE(stdev,stdev_actual + stdev_tolerance);

}
