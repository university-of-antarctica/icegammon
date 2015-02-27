#ifndef ICEGAMMON_ASCIIVIEW_H_
#define ICEGAMMON_ASCIIVIEW_H_
#include <stdio.h>
#include <cmath>
#include <sstream>
#include <string>
	//forward declaration
	//class Board;

	//includes
	#include <string>
	#include "Board.h"
  #include <algorithm>

	class AsciiView{
	public:
		AsciiView(Board*);
		char whiteStone();
		char blackStone();
		int whiteStoneCount();
    int blackStoneCount();
    std::string toString();
  private:
		char _whiteStone = 'W';
		char _blackStone = 'B';
    int numWhiteStones = 0;
    int numBlackStones = 0;
    Board *b; 
    std::vector<int> getViewColumnArray();
    std::string charToString(char);
    void incrementBlackStones();
    void incrementWhiteStones();
	};

#endif
