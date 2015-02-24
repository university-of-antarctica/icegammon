#ifndef ICEGAMMON_BOARD_H_
#define ICEGAMMON_BOARD_H_

	class Board{
	public:
		int pips[25]={0}; //0 unused
		int homes[2]={0}; //white is 0, black is 1
		int bars[2]={0};  //white is 0, black is 1

		//sets up the board for a traditional backgammon game
		void initialize();

	};
	
#endif