#include <iostream>
#include <vector>
#include "Point.h"

using namespace std;

Point::Point() {

}

Point::Point(vector<double> _LOC) {
  LOC = _LOC;
}

Point::Point(const Point& arg) {
  LOC = arg.getLOC();
}

Point& Point::operator=(const Point& arg) {
  if(this == &arg)
    return *this;

  LOC = arg.getLOC();

  return *this;
}

void Point::setLOC(vector<double>& _LOC) {
  LOC = _LOC;
}

vector<double> Point::getLOC() const {
  return LOC;
}

void Point::displayPoint() {
  for(int i = 0; i < LOC.size(); i++)
    cout << LOC[i] << " ";

  cout << endl;
}
