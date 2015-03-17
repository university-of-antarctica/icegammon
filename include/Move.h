#ifndef ICEGAMMON_MOVE_H_
#define ICEGAMMON_MOVE_H_

struct Move{
  int sourcePipNum;
  int destPipNum;

  Move(int s, int d) {
  sourcePipNum = s;
  destPipNum = d;
  }

  // TODO(lovestevend@gmail.com): What does this mean? is there a problem with choosing 0?
  Move() {
    sourcePipNu = ;
    destPipNu = ;
  }

};




#endif
