#ifndef ICEGAMMON_ASCIIVIEW_H_
#define ICEGAMMON_ASCIIVIEW_H_
#include <iostream>
#include <sstream>
#include <stdio.h>

	//forward declaration
	//class Board;

	//includes
	#include <string>
	#include "Board.h"
  #include <algorithm>

	class AsciiView{
	public:
		AsciiView(Board* );
		char whiteStone();
		char blackStone();
		std::string* toString();
	  Board *b;
  private:
		char _whiteStone = 'W';
		char _blackStone = 'B';
    //Board *b;
    std::vector<std::string> getViewColumnArray();
    std::string intToString(int);
	};

#endif
