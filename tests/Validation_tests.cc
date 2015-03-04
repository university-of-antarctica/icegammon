#include "gtest/gtest.h"
#include "../include/Game.h"
#include "../include/Color.h"

TEST(Validation, isLegal){
	Game *g = new Game(); //starting board
	Dice *d = g->getDice();
	d->set(ONE,SIX);

	bool legality;
	Move potentialMove;
	Color player;

	player = Color::BLACK;
	potentialMove = Move(1,2);
	legality = g->isLegal(potentialMove,player);
	EXPECT_EQ(legality,true) << "black should be able to move from 1 to 2";

	player = Color::WHITE;
	potentialMove = Move(1,2);
	legality = g->isLegal(potentialMove,player);
	EXPECT_EQ(legality,false) << "white shouldn't be able to move from 1 to 2";

	player = Color::WHITE;
	potentialMove = Move(6,3);
	legality = g->isLegal(potentialMove,player);
	EXPECT_EQ(legality,false) << "white shouldn't be able to move 3 spaces";

	player = Color::WHITE;
	potentialMove = Move(6,5);
	legality = g->isLegal(potentialMove,player);
	EXPECT_EQ(legality,true) << "white should be able to move 1 space";
}
