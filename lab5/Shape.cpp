#include <iostream>
#include <cmath>
#include "Shape.h"

using namespace std;

Shape::Shape(bool _isThreeD) {
  isThreeD = _isThreeD;
}

double Shape::getArea() {
  cout << "Shape Area" << endl;
  return 0;
}

double Shape::getVolume() {
  cout << "Shape Volume" << endl;
  return 0;
}

bool Shape::getisThreeD() {
  return isThreeD;
}

TwoDimensionalShape::TwoDimensionalShape() : Shape(false) { }

double TwoDimensionalShape::getArea() {
  cout << "TwoDimensionalShape Area" << endl;
  return 0;
}

ThreeDimensionalShape::ThreeDimensionalShape() : Shape(true) { }

double ThreeDimensionalShape::getArea() {
  cout << "ThreeDimensionalShape Area" << endl;
  return 0;
}

double ThreeDimensionalShape::getVolume() {
  cout << "ThreeDimensionalShape Volume" << endl;
  return 0;
}

Circle::Circle(int _radius) : TwoDimensionalShape() {
  radius = _radius;
}

double Circle::getArea() {
  return radius * radius * M_PI;
}

Square::Square(int _side) : TwoDimensionalShape() {
  side = _side;
}

double Square::getArea() {
  return side * side;
}

Triangle::Triangle(int _side1, int _side2, int _side3) {
  side1 = _side1;
  side2 = _side2;
  side3 = _side3;
}

double Triangle::getArea() {
  double s = (side1 + side2 + side3) / 2.0;
  return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}
Sphere::Sphere(int _radius) : ThreeDimensionalShape() {
  radius = _radius;
}

double Sphere::getArea() {
  return 4 * M_PI * radius * radius;
}

double Sphere::getVolume() {
  return 4 / 3.0 * M_PI * radius * radius * radius;
}


Cube::Cube(int _side) : ThreeDimensionalShape() {
  side = _side;
}

double Cube::getArea() {
  return 6 * side * side;
}

double Cube::getVolume() {
  return side * side * side;
}

Tetrahedron::Tetrahedron(int _a1, int _a2, int _a3, int _a4, int _a5, int _a6) : ThreeDimensionalShape() {
  a1 = _a1;
  a2 = _a2;
  a3 = _a3;
  a4 = _a4;
  a5 = _a5;
  a6 = _a6;
}

double Tetrahedron::getArea() {
  Triangle area1(a1, a6, a3);
  Triangle area2(a1, a4, a2);
  Triangle area3(a2, a5, a3);
  Triangle area4(a4, a5, a6);

  return area1.getArea() + area2.getArea() + area3.getArea() + area4.getArea();
}

double Tetrahedron::getVolume() {
  double x1 = a1 * a1;
  double x2 = a2 * a2;
  double x3 = a3 * a3;
  double x4 = a4 * a4;
  double x5 = a5 * a5;
  double x6 = a6 * a6;

  double volume;

  volume = sqrt((x1*x5*(x2+x3+x4+x6-x1-x5)+x2*x6*(x1+x3+x4+x5-x2-x6)+x3*x4*(x1+x2+x5+x6-x3-x4)-x1*x2*x4-x2*x3*x5-x1*x3*x6-x4*x5*x6)/144.0);

  return volume;
}
