#include "Game.h"

	void Game::passTurn(){
		if(turn==WHITE){
			turn=BLACK;
		}
		else{
			turn=WHITE;
		}
	}