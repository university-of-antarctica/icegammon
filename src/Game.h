#ifndef ICEGAMMON_GAME_H_
#define ICEGAMMON_GAME_H_

	#include "Color.cc"

	class Game{

	public:
		Color turn = WHITE; //TODO: roll for initiative
		void passTurn();
	};
#endif