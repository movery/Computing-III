#include <iostream>
#include <vector>
#include "Point.h"

Point::Point() {
  W = 0;
  X = 0;
  Y = 0;
  Z = 0;
}

Point::Point(double _W, double _X, double _Y, double _Z) {
  W = _W;
  X = _X;
  Y = _Y;
  Z = _Z;
}

Point::Point(const Point& arg) {
  W = arg.getW();
  X = arg.getX();
  Y = arg.getY();
  Z = arg.getZ();
}

Point& Point::operator=(const Point& arg) {
  if(this == &arg)
    return *this;

  W = arg.getW();
  X = arg.getX();
  Y = arg.getY();
  Z = arg.getZ();

  return *this;
}

double Point::getW() const {
  return W;
}

double Point::getX() const {
  return X;
}

double Point::getY() const {
  return Y;
}

double Point::getZ() const {
  return Z;
}

void Point::setW(double _W) {
  W = _W;
}

void Point::setX(double _X) {
  X = _X;
}

void Point::setY(double _Y) {
  Y = _Y;
}

void Point::setZ(double _Z) {
  Z = _Z;
}

void Point::displayPoint() {
  std::cout << W << " " << X << " " << Y << " " << Z << std::endl;
}