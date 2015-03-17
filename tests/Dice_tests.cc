// #include "gtest/gtest.h"
// #include "testmain.cc"
// #include "../src/utils.cc"

#include "../include/Dice.h"
#include "../include/utils.h"
#include "gtest/gtest.h"
TEST(DiceRolls,VerifyValidDiceValues){

Dice *d = new Dice();
d->roll();
uint8_t firstRoll = d->left();
uint8_t secondRoll = d->right();
EXPECT_LE(firstRoll,6);
EXPECT_LE(secondRoll,6);
EXPECT_GE(firstRoll,1);
EXPECT_GE(secondRoll,1);

}

TEST(DiceRolls,MeanAndStdDev){
//TODO: As of now this is a sanity check, it needs to be much more statistically valid in the future

// Parameters
int numberOfRolls = 1000;
double mean_tolerance = 0.2;
double stdev_tolerance = 0.2;

// Declarations
Dice *d = new Dice();
uint8_t firstRoll, secondRoll;
std::vector<double> vectorOfRolls; //removed the (numberOfRolls) construction argument.  It was initializing the vector with <numberOfRolls> zeros.

// Roll dice a bunch of times
for(int i = 0; i < (numberOfRolls/2) ; i = i + 1 ){
  d->roll();
  firstRoll  = d->left();
  secondRoll = d->right();
  vectorOfRolls.push_back( (double) firstRoll);
  vectorOfRolls.push_back( (double) secondRoll);
}

// Calculate statistics
double mean_observed  = utils_mean(vectorOfRolls);
double stdev_observed = utils_stddev(vectorOfRolls);

// Expected results 
// from (http://www.futureaccountant.com/theory-of-expectation-random-variable/problems-solutions/throwing-rolling-dice.php#.VOQF0jVTdNA)
double mean_desired  = 3.5; 
double stdev_desired = 1.709;

double mean_lower_bound  = mean_desired  - mean_tolerance;
double mean_upper_bound  = mean_desired  + mean_tolerance;
double stdev_lower_bound = stdev_desired - stdev_tolerance;
double stdev_upper_bound = stdev_desired + stdev_tolerance;

EXPECT_LE(mean_lower_bound, mean_observed);
EXPECT_GE(mean_upper_bound, mean_observed);
EXPECT_LE(stdev_lower_bound, stdev_observed);
EXPECT_GE(stdev_upper_bound, stdev_observed);

}

TEST(EdgeCaseBehavior, Declaration){
  Dice* d = new Dice();
  d->prettyPrint();
}