#include "../include/AsciiView.h"

AsciiView::AsciiView(Board* b){

}

char AsciiView::whiteStone(){
	return _whiteStone;
}

char AsciiView::blackStone(){
	return _blackStone;
}

std::string* AsciiView::toString(){
	std::string* visualization = new std::string("ABCDEFGHIJKLMNOPQRSTUVWXYZ\nABCDEFGHIJKLMNOPQRSTUVWXYZ\n");

	return visualization;
}