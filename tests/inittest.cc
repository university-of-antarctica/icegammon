//#include <stdio.h>
#include "../main.cc"
#include "gtest/gtest.h"

TEST(preset,Negative){

	ASSERT_EQ(5,5) << "preset was not 5";
	ASSERT_EQ(5,6) << "should not work";
	
}