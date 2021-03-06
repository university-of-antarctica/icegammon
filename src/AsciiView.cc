#include "../include/AsciiView.h"

std::string visualization_header = std::string(
  "WH```P`P`P`P`P`P``|BB|``P`P`P`P`P`P```P`P`P`P`P`P``|WB|``P`P`P`P`P`P```BH\n");

AsciiView::AsciiView(Game* game) {
  AsciiView::game = game;
}

char AsciiView::whiteStone() {
  incrementWhiteStones();
  return _whiteStone;
}

void AsciiView::incrementWhiteStones() {
  numWhiteStones = numWhiteStones + 1;
}

int AsciiView::whiteStoneCount() {
  return numWhiteStones;
}

char AsciiView::blackStone() {
  incrementBlackStones();
  return _blackStone;
}

void AsciiView::incrementBlackStones() {
  numBlackStones = numBlackStones + 1;
}

int AsciiView::blackStoneCount() {
  return numBlackStones;
}

std::string AsciiView::toString() {
  // needs to print the turn number? maybe
  // needs to print whose turn it is white or black
  // Dice rolls
  std::string visualization = visualization_header;
  std::vector<int> viewColumnArray;
  viewColumnArray = getViewColumnArray();
  for (int i = 0; i < 15; i = i + 1) {
    for (int j = 1; j < 73; j = j + 1) {
      if (viewColumnArray[j] == 0 || abs(viewColumnArray[j]) <= i) {
        visualization.append(" ");
      }
      else{
        if (viewColumnArray[j] > 0) {
          visualization.append(charToString(whiteStone()));
        }
        else{
          visualization.append(charToString(blackStone()));
        }
      }
    }
  visualization.append("\n");
  }
  return visualization;
}

std::vector<int> AsciiView::getViewColumnArray() {
  Board* b = game->getBoard();
  std::vector<int> viewColumnArray(73,0);
  viewColumnArray[1] = b->homes[0];
  viewColumnArray[6] = b->pips[1]; 
  viewColumnArray[8] = b->pips[2];
  viewColumnArray[10] = b->pips[3];
  viewColumnArray[12] = b->pips[4];
  viewColumnArray[14] = b->pips[5];
  viewColumnArray[16] = b->pips[6];
  viewColumnArray[20] = b->bars[1];
  viewColumnArray[25] = b->pips[7];
  viewColumnArray[27] = b->pips[8];
  viewColumnArray[29] = b->pips[9];
  viewColumnArray[31] = b->pips[10];
  viewColumnArray[33] = b->pips[11];
  viewColumnArray[35] = b->pips[12];
  viewColumnArray[39] = b->pips[13];
  viewColumnArray[41] = b->pips[14];
  viewColumnArray[43] = b->pips[15];
  viewColumnArray[45] = b->pips[16];
  viewColumnArray[47] = b->pips[17];
  viewColumnArray[49] = b->pips[18];
  viewColumnArray[53] = b->bars[0];
  viewColumnArray[58] = b->pips[19];
  viewColumnArray[60] = b->pips[20];
  viewColumnArray[62] = b->pips[21];
  viewColumnArray[64] = b->pips[22];
  viewColumnArray[66] = b->pips[23];
  viewColumnArray[68] = b->pips[24];
  viewColumnArray[72] = b->homes[1];
  return viewColumnArray;
}

std::string AsciiView::charToString(char c) {
  std::stringstream ss;
  std::string s;
  ss << c;
  ss >> s;
  return s;
}
