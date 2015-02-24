#ifndef ICEGAMMON_DICE_H_
#define ICEGAMMON_DICE_H_

	#include <time.h> /* Needed just for srand seed */
	#include <stdlib.h>
	#include <stdio.h>
	#include <stdint.h> //uint_8t
	#include <utility> //std::pair
	
	
	class Dice{
	public:
		Dice();
		void roll();
		uint8_t left();
		uint8_t right();
		static const wchar_t symbols[];
		
	private:
		std::pair<uint8_t,uint8_t> values;
		uint8_t getRandomDieRoll();
		void randomize();
	};


#endif