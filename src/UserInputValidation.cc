#include "../include/UserInputValidation.h"


bool UserInputValidation::InputValidationForDiceRollPrompt(std::string line) {
  bool inputInvalidKeepLooping = false;  // CLEANCODE: javabean predicate
// CLEANCODE: repetition of "line->at(0)".  
  // show intent by naming this. "firstCharOfInput"?
  // I feel fine about 'r' and 'R' being magic numbers, but I don't think Clean Code does...
  if (line.at(0)!='r' && line.at(0)!='R') { 
      inputInvalidKeepLooping = true;     
  }
  return inputInvalidKeepLooping;
}

bool UserInputValidation::InputValidationForMoveObjectPrompt(std::string line) {
  bool inputInvalidKeepLooking = true;
  std::vector<std::string> userInputVector = SplitByWhiteSpace(line);
  // move object only has 3 tokens
  if (userInputVector.size() == 3) {

    std::string elem0 = userInputVector[0];
    std::string elem1 = userInputVector[1];
    std::string elem2 = userInputVector[2];
    
    // Get length of elements as they are strings 
    int elem1StrLength = elem1.length();
    int elem2StrLength = elem2.length();
    
    // convert strings to integers, if there are non digits characters
    // it will return a digit in the string depending on where the character
    // in the string was.
    int elem1Int = atoi(elem1.c_str());
    int elem2Int = atoi(elem2.c_str());

    // get the numberOfDigits, this will be used in a check with
    // the string length, if the string length and num digits match
    // then we know the whole string was an integer we can use.
    int elem1IntLength = NumDigits(elem1Int);
    int elem2IntLength = NumDigits(elem2Int);

  // std::cout << "1: " << elem1Int << " str: " << elem1StrLength << " int: " << elem1IntLength << " 2: " << elem2Int << " str: " << elem2StrLength << " int: " << elem2IntLength << std::endl;

    if (elem0 == "m" && elem1StrLength == elem1IntLength && elem2StrLength == elem2IntLength ) { 
        if (elem1Int != 0 && elem2Int != 0) {
          inputInvalidKeepLooking = false;
        }
    }
  }

  return inputInvalidKeepLooking;
}


std::vector<std::string> UserInputValidation::SplitByWhiteSpace(std::string line) {
  std::string buf;  // Have a buffer string
  std::stringstream ss(line);  // Insert the string into a stream
  std::vector<std::string> tokens;  // Create vector to hold our words
  while (ss >> buf) {
    tokens.push_back(buf);
  }
  return tokens;
}

int UserInputValidation::NumDigits(int x) {  
    x = abs(x);  // this is beautiful
    return (x < 10 ? 1 :   
           (x < 100 ? 2 :   
           (x < 1000 ? 3 :   
           (x < 10000 ? 4 :   
           (x < 100000 ? 5 :   
           (x < 1000000 ? 6 :   
           (x < 10000000 ? 7 :  
           (x < 100000000 ? 8 :  
           (x < 1000000000 ? 9 :  
           10)))))))));  // TODO(lovestevend@gmail.com): throw exception? have a guarantee on the max size?
}
