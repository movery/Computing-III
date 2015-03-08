#ifndef _POINT_H
#define _POINT_H

class Point { 
 private:
  double W;
  double X;
  double Y;
  double Z;
 public:
  Point();
  Point(double, double, double, double);
  Point(const Point& arg);
  Point& operator=(const Point&);
  void setW(double);
  void setX(double);
  void setY(double);
  void setZ(double);
  double getW() const;
  double getX() const;
  double getY() const;
  double getZ() const;
  void displayPoint();
};

#endif
