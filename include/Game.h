#ifndef ICEGAMMON_GAME_H_
#define ICEGAMMON_GAME_H_

  #include "Color.h"
  #include "Board.h"
  #include "Dice.h"
  #include "Move.h"
  #include "Color.h" 
  #include <typeinfo>
  #include <cinttypes>
  #include <iostream>
  #include "Turn.h"

  //Describe this class and its responsibilities
  //
  




  class Game{
    //public static constants
    //private static variables
    //private instance variables
    //public functions
    //private utilities called by a public function
  public:
    Game();
    void passTurn();
    std::string getActiveColorString();  // Returns the current value of turn which is whose turn it is, white or black.
    Color getActiveColor();
    Board* getBoard();
    Dice* getDice();
    bool isLegal(Move*);  // should a move also have a color inside it?
    // bool moveStone(Move move, Color player);
    void submitTurn(Turn*, int);
    bool moveStone(Move*); 

    // classes:
    //  Game state: getters
    //  Gameplay logic: isLegal
    //    
    //  Move validation
    //    interface for RULEs that take Game State and a Move
    //    correct color of player moving validation
    //    correct # spaces moved validation
    //    correct source pip # validation
    //      >0 same-color stones
    //    correct destination pip # validation
    //      0 stones
    //      >0 same-color stones
    //      1 enemy stone (blotting)
    //    
    // but we need to do move enmueration anyway so lets work with that




    //  Move enumeration
    //  MoveEnumerator takes a GameState?
    //   
    //    find all viable source pips 
    //      (same color stones, >0 on the pip)
    //      (if on bar, only the bar)
    //    find all viable distances
    //    find all viable dest pips from distances
    //    cull out non-viable dest pips (>1 enemy stones)
    //    consider bearing off at all

    //  Enumerate turns by brute forcing move enumeration
    //  we only need to do this if the player moves once and then can't move
    //  we have to then check that there's no way for them to make 2 moves



    //
    //  turn management
    //  


  private:
    Board* b;
    Dice* dice;
    Color turn = Color::WHITE;  // White is prompted for first roll
    

   // FRIEND_TEST(Moving, BasicForceMove);
  };
#endif
