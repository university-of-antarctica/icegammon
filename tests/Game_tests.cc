#include "gtest/gtest.h"
#include "../include/Game.h"
#include "../include/Controller.h"
#include <ctime>

TEST(Turns, First4TurnsAlternate){
	Game *g = new Game();
	Controller *controller = new Controller(g);

	Color first = g->getActiveColor();
	g->passTurn();
	Color second = g->getActiveColor();
	g->passTurn();
	Color third = g->getActiveColor();
	g->passTurn();
	Color fourth= g->getActiveColor();

	EXPECT_EQ(first,third) << "first and third turns should be the same color";
	EXPECT_EQ(second,fourth) << "second and fourth turns should be the same color";
	EXPECT_NE(first,second) << "first and second turns shouldn't be the same color";
}

TEST(Turns, EvenOddRandomized){
	Game *g = new Game();
	Controller *controller = new Controller(g);

  srand(time(NULL));
	Color first = g->getActiveColor();
	g->passTurn();
	Color second = g->getActiveColor();

	int n = rand() % 1000; //in the range between 0 and 999
	for(int i = 0; i < n; ++i){
		g->passTurn();
	}

	//if n is odd, then the color should be same as the first color
	//if n is even, then the color should be the same as the second color
	if(n%2==1){//n is odd
		EXPECT_EQ(first,g->getActiveColor())<< "all odd numbered turns should be the same color";
	}
	else{//n is even
		EXPECT_EQ(second,g->getActiveColor()) << "all even numbered turns should be the same color";
	}
	EXPECT_NE(first,second) << "first and second turns shouldn't be the same color";

}

TEST(Moving, BasicFirstMove){
	Game* g = new Game();
	bool success;
	Move move;
	Board* b = g->getBoard();

	//Before move
	EXPECT_EQ(b->pips[1],2)<< "there should be 2 black stones on pip 1";
	EXPECT_EQ(b->pips[3],0)<< "there shouldnt be any black stones on pip 3";

	move = Move(1,3);
	success = g->moveStone( move, BLACK);

	//After move
	EXPECT_EQ(success,true)<<"black should be able to move forward 2 pips";
	EXPECT_EQ(b->pips[1],1)<< "there should be 1 remaining black stone on pip 1";
	EXPECT_EQ(b->pips[3],1)<< "there should now be 1 black stone on pip 3";

}
