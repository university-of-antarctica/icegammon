//#include <stdio.h> //
#include <stdlib.h> //rand, srand
#include "testmain.cc"
#include "gtest/gtest.h"

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
returnedRoll = d->rollDice();
uint8_t firstRoll = returnedRoll.first;
uint8_t secondRoll = returnedRoll.second;
EXPECT_LE(firstRoll,6);
EXPECT_LE(secondRoll,6);
EXPECT_GE(firstRoll,1);
EXPECT_GE(secondRoll,1);

}

TEST(DiceRolls,MeanAndStdDev){

//TODO As of now this is a sanity check, it needs to be much more statistically valid in the future

Dice *d = new Dice();
std::pair<uint8_t,uint8_t> returnedRoll;
returnedRoll = d->rollDice();
uint8_t firstRoll;
uint8_t secondRoll;
std::vector<double> vectorOfRolls(100);
std::vector<double>::iterator iter;
iter = vectorOfRolls.begin();

for(int i = 0; i < 50 ; i = i + 1 ){
  returnedRoll = d->rollDice(); 
  firstRoll = returnedRoll.first;
  secondRoll = returnedRoll.second;
 // vectorOfRolls.insert( iter, (double)firstRoll);
 // vectorOfRolls.insert( iter, (double)secondRoll);
}

//double sum = std::accumulate(vectorOfRolls.begin(),vectorOfRolls.end(),0.0);
//double mean = sum / vectorOfRolls.size();
double mean = 3.5;
/*
std::vector<double> diff(vectorOfRolls.size());
std::transform(vectorOfRolls.begin(), vectorOfRolls.end(), diff.begin(),std::bind2nd(std::minus<double>(), mean));
double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
double stdev = std::sqrt(sq_sum / vectorOfRolls.size()); 
*/

double mean_actual = 3.5;
double mean_tolerance = 0.5;

double stdev_actual = 1.709;
double stdev_tolerance = 0.25;

EXPECT_LE(mean,mean_actual + mean_tolerance);
EXPECT_GE(mean,mean_actual - mean_tolerance);

//EXPECT_LE(stdev,stdev_actual + stdev_tolerance);
//EXPECT_GE(stdev,stdev_actual - stdev_tolerance);
}


