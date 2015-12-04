#ifndef _POINT_H
#define _POINT_H

#include <vector>

using namespace std;

class Point {
 private:
  vector<double> LOC;
 public:
  Point();
  Point(vector<double>);
  Point(const Point& arg);
  Point& operator=(const Point&);
  void setLOC(vector<double>&);
  vector<double> getLOC() const;
  void displayPoint();
};

#endif
