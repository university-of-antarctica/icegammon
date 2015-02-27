#include "gtest/gtest.h"
#include "../include/Game.h"
#include <ctime>

TEST(Turns, First4TurnsAlternate){
  Controller *controller = new Controller();
	Game *g = new Game(controller);
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
  Controller *controller = new Controller();
	Game *g = new Game(controller);
  srand(time(NULL));
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
