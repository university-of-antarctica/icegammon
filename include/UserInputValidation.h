#ifndef ICEGAMMON_USERINPUTVALIDATION_H
#define ICEGAMMON_USERINPUTVALIDATION_H_

#include <iostream>
#include <sstream>
#include <algorithm>

class UserInputValidation{
  
  //TODO(gpwclark@gmail.com): inheritance for InputValidationFor* ?
  public:

  // CLEANCODE: doesn't follow javabean standard for predicates (isValid 
  // might be better) NAME SHOULD START WITH is IF IT RETURNS bool.
  bool InputValidationForDiceRollPrompt(std::string line);
  

  // CLEANCODE: doesn't follow javabean standard for predicates 
  // (isValid might be better) NAME SHOULD START WITH is IF IT RETURNS bool.
  bool InputValidationForMoveObjectPrompt(std::string); 
  std::vector<std::string> SplitByWhiteSpace(std::string);

  private:

  int NumDigits(int);

  };
#endif
