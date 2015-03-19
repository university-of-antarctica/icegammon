#ifndef ICEGAMMON_PLAYER_H_
#define ICEGAMMON_PLAYER_H_

#include "Color.h"
#include <string>

  class Player{
    public:
      Player(){color_=Color::WHITE;}
      Player(Color colorOfPlayer);
      std::string toString();
      Color getColor();
    private:
      Color color_;
  };
  
#endif