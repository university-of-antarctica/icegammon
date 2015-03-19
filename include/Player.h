#ifndef ICEGAMMON_PLAYER_H_
#define ICEGAMMON_PLAYER_H_

  class Player{
    public:
      std::string toString();
      Color getColor();
    private:
      Color color;
  };
  
#endif