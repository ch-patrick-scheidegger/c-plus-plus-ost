#ifndef POINT_H_
#define POINT_H_


struct Point {
  int x;
  int y;
};

inline Point modify(Point in) {
  in.x = 3;
  in.y = 4;
  return in;
}



#endif /* POINT_H_ */
