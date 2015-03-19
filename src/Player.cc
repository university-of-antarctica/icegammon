#include "../include/Player.h"


Player::Player(Color colorOfPlayer){
  color_ = colorOfPlayer;
}

std::string Player::toString(){
  if (color_ == Color::WHITE) {
    return "White";
  }else{
    return "Black";
  }
}

Color Player::color(){
  return color_;
}