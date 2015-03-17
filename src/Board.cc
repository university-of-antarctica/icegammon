#include "../include/Board.h"

Board::Board() {
 initialize();
}

void Board::initialize() {
  pips[24] = 2;  // 2 white stones on pip 24
  pips[19] = -5;  // 5 black stones on pip 19
  pips[17] = -3;  // ...
  pips[13] = 5;
  pips[12] = -5;
  pips[8] = 3;
  pips[6] = 5;
  pips[1] = -2;
}
