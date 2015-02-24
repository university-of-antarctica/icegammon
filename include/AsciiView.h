#ifndef ICEGAMMON_ASCIIVIEW_H_
#define ICEGAMMON_ASCIIVIEW_H_

	//forward declaration
	//class Board;

	//includes
	#include <string>
	#include "Board.h"

	class AsciiView{
	public:
		AsciiView(Board* );
		char whiteStone();
		char blackStone();
		std::string* toString();
	private:
		char _whiteStone = 'W';
		char _blackStone = 'B';
	};

#endif