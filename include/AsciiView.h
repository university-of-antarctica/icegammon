#ifndef ICEGAMMON_ASCIIVIEW_H_
#define ICEGAMMON_ASCIIVIEW_H_
#include <stdio.h>
#include <cmath>
#include <sstream>
#include <string>
#include "Game.h"
  // forward declaration
  

  // includes
  #include <string>
  #include "Board.h"
  #include <algorithm>

  class AsciiView{
  public:
    AsciiView(Game*);
    char whiteStone();
    char blackStone();
    int whiteStoneCount();
    int blackStoneCount();
    std::string toString();
  private:
    Game *game;
    char _whiteStone = 'W';
    char _blackStone = 'B';
    int numWhiteStones = 0;
    int numBlackStones = 0;
    std::vector<int> getViewColumnArray();
    std::string charToString(char);
    void incrementBlackStones();
    void incrementWhiteStones();
  };

#endif
