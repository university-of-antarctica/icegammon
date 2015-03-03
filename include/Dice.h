#ifndef ICEGAMMON_DICE_H_
#define ICEGAMMON_DICE_H_

	#include <time.h> /* Needed just for srand seed */
	#include <stdlib.h>
	#include <stdio.h>
	#include <stdint.h> //uint_8t
	#include <utility> //std::pair
	
	enum DieFace {ONE=1,TWO=2,THREE=3,FOUR=4,FIVE=5,SIX=6};
	//TODO: change all the uint8_t stuff to DieVals

	class Dice{
	public:
		Dice();
		void roll();
		DieFace left();
		DieFace right();
		static const wchar_t symbols[];
		void prettyPrint();
		void prettyPrintOne();


		void set(DieFace left, DieFace right);

	private:
		std::pair<DieFace ,DieFace> values;
		DieFace getRandomDieRoll();
		void randomize();
		wchar_t getSymbol(DieFace);
	};


#endif