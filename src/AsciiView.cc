#include "AsciiView.h"

AsciiView::AsciiView(Board* b){
     AsciiView::b = b;
}

char AsciiView::whiteStone(){
	return _whiteStone;
}

char AsciiView::blackStone(){
	return _blackStone;
}

std::string* AsciiView::toString(){
	std::string* visualization = new std::string("WH```P`P`P`P`P`P``|BB|``P`P`P`P`P`P```P`P`P`P`P`P``|WB|``P`P`P`P`P`P```BH\n");

  std::vector<std::string> viewColumnArray;
  viewColumnArray = getViewColumnArray(); 
  
  //put values from viewColumnArray into visualization, if value in viewColumnArray is 2, skip printing next element
  //to ensure the visualization is not out of line.
  for(int i = 1; i < 74; i = i + 1){
   if(viewColumnArray[i].length()==2){
      visualization->append(viewColumnArray[i]);
      i = i + 1;
    }else{
    visualization->append(viewColumnArray[i]);
   }
  }
  
  visualization->append("\n");
  return visualization;
}

std::vector<std::string> AsciiView::getViewColumnArray(){
  std::vector<std::string> viewColumnArray(74," ");
  viewColumnArray[1] = intToString(b->homes[0]);
  viewColumnArray[6] = intToString(b->pips[1]); 
  std::cout << "pip #1: ";
  std::cout << b->pips[1] << std::endl;
  viewColumnArray[8] = intToString(b->pips[2]);
  viewColumnArray[10] = intToString(b->pips[3]);
  viewColumnArray[12] = intToString(b->pips[4]);
  viewColumnArray[14] = intToString(b->pips[5]);
  viewColumnArray[16] = intToString(b->pips[6]);
  viewColumnArray[20] = intToString(b->bars[1]);
  viewColumnArray[25] = intToString(b->pips[7]); 
  viewColumnArray[27] = intToString(b->pips[8]);
  viewColumnArray[29] = intToString(b->pips[9]);
  viewColumnArray[31] = intToString(b->pips[10]);
  viewColumnArray[33] = intToString(b->pips[11]);
  viewColumnArray[35] = intToString(b->pips[12]);
  viewColumnArray[39] = intToString(b->pips[13]);
  viewColumnArray[41] = intToString(b->pips[14]);
  viewColumnArray[43] = intToString(b->pips[15]);
  viewColumnArray[45] = intToString(b->pips[16]);
  viewColumnArray[47] = intToString(b->pips[17]);
  viewColumnArray[49] = intToString(b->pips[18]);
  viewColumnArray[53] = intToString(b->bars[0]);
  viewColumnArray[58] = intToString(b->pips[19]);
  viewColumnArray[60] = intToString(b->pips[20]);
  viewColumnArray[62] = intToString(b->pips[21]);
  viewColumnArray[64] = intToString(b->pips[22]);
  viewColumnArray[66] = intToString(b->pips[23]);
  viewColumnArray[68] = intToString(b->pips[24]);
  viewColumnArray[72] = intToString(b->homes[1]);
     
  return viewColumnArray;
}
std::string AsciiView::intToString ( int number ){
  std::ostringstream oss;
  oss<< number;
  return oss.str();
}

