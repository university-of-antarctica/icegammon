#include "gtest/gtest.h"
#include "../include/UserInputValidation.h"

#define LC_R 114
#define UC_R 82
#define LAST_ASCII_CHAR 127


TEST(UserInputValidation, verifyInputsForFirstTurn) {
  
  UserInputValidation *iv = new UserInputValidation(); 
  bool testValue;
  // InputValidationForDiceRollPrompt only checks first char, // and returns true if first chars aren't 'r' or 'R'.
  
  std::string testLine; 
 
 for (int i = 0; i < LAST_ASCII_CHAR; ++i) {
    testLine.assign(1, i);
    testValue = iv->InputValidationForDiceRollPrompt(testLine);
    
    if ( i == UC_R) {
      EXPECT_EQ(false, testValue)<<"If input is 'R' return false so we stop looping";
    }
    if (i == LC_R) {
      EXPECT_EQ(false, testValue)<<"If input is 'r' return false so we stop looping";
    }
 
  }
}

TEST(UserInputValidation, validateInputForMoveObject) {
  UserInputValidation *iv = new UserInputValidation(); 

  // test inputValidationForMoveObject();
  // This function returns FALSE if the input is VALID
  // and return TRUE if the input is INVALID
  // as it is the exit condition for a loop
  EXPECT_EQ(true, iv->InputValidationForMoveObjectPrompt("t 80 80"))<<"Invalid Input should return true";
  EXPECT_EQ(true, iv->InputValidationForMoveObjectPrompt("N 80 80"))<<"Invalid Input should return true";
  EXPECT_EQ(true, iv->InputValidationForMoveObjectPrompt("M 80 80"))<<"Invalid Input should return true";
  EXPECT_EQ(true, iv->InputValidationForMoveObjectPrompt("m j j"))<<"Invalid Input should return true";
  EXPECT_EQ(true, iv->InputValidationForMoveObjectPrompt("m XX ys90"))<<"Invalid Input should return true";
  EXPECT_EQ(true, iv->InputValidationForMoveObjectPrompt("m 8X0 90xx09"))<<"Invalid Input should return true";
  EXPECT_EQ(true, iv->InputValidationForMoveObjectPrompt("m 450X X80"))<<"Invalid Input should return true";
  EXPECT_EQ(true, iv->InputValidationForMoveObjectPrompt("m X80X X80s"))<<"Invalid Input should return true";
  EXPECT_EQ(true, iv->InputValidationForMoveObjectPrompt("m 80 0009"))<<"Invalid Input should return true";
  EXPECT_EQ(false, iv->InputValidationForMoveObjectPrompt("m 8 9"))<<"Valid Input should return false";
  EXPECT_EQ(false, iv->InputValidationForMoveObjectPrompt("m 1 9"))<<"Valid Input should return false";
  EXPECT_EQ(false, iv->InputValidationForMoveObjectPrompt("m 12 18"))<<"Valid Input should return false";
  EXPECT_EQ(false, iv->InputValidationForMoveObjectPrompt("m 4 9"))<<"Valid Input should return false";
  EXPECT_EQ(false, iv->InputValidationForMoveObjectPrompt("m 19 22"))<<"Valid Input should return false";
  EXPECT_EQ(false, iv->InputValidationForMoveObjectPrompt("m 12 13"))<<"Valid Input should return false";
  EXPECT_EQ(false, iv->InputValidationForMoveObjectPrompt("m 1 9"))<<"Valid Input should return false";
}
