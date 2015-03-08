#ifndef _SHAPE_H
#define _SHAPE_H

class Shape {
 protected:
  bool isThreeD;
 public:
  Shape(bool);
  bool getisThreeD();
  double virtual getArea();
  double virtual getVolume();
};

class TwoDimensionalShape : public Shape {
 public:
  TwoDimensionalShape();
  double getArea();
};

class ThreeDimensionalShape : public Shape {
 public: 
  ThreeDimensionalShape();
  double getArea();
  double getVolume();
};

class Circle : public TwoDimensionalShape {
 private:
  int radius;
 public:
  Circle(int);
  double getArea();
};

class Square : public TwoDimensionalShape {
 private:
  int side;
 public:
  Square(int);
  double getArea();
};

class Triangle : public TwoDimensionalShape {
 private:
  int side1;
  int side2;
  int side3;
 public:
  Triangle(int, int, int);
  double getArea();
};

class Sphere : public ThreeDimensionalShape {
 private: 
  int radius;
 public:
  Sphere(int);
  double getArea();
  double getVolume();
};

class Cube : public ThreeDimensionalShape {
 private:
  int side;
 public:
  Cube(int);
  double getArea();
  double getVolume();
};

class Tetrahedron : public ThreeDimensionalShape {
 private:
  int a1;
  int a2;
  int a3;
  int a4;
  int a5;
  int a6;
 public:
  Tetrahedron(int, int, int, int, int, int);
  double getArea();
  double getVolume();
};

#endif
