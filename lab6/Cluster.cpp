#include <vector>
#include "Cluster.h"
#include "Point.h"

Cluster::Cluster(Point _point) : centroid(_point.getW(), _point.getX(), _point.getY(), _point.getZ()) { 
  points.push_back(_point);
  size = points.size();
}

Cluster::Cluster(const Cluster& arg) {
  for(int i = 0; i < arg.getSize(); i++) 
    points.push_back(arg.getPoint(i));

  size = arg.getSize();
  centroid = arg.getCentroid();
}

Cluster& Cluster::operator=(const Cluster& arg) {
  if(this == &arg)
    return *this;

  points.clear();

  for(int i = 0; i < arg.getSize(); i++)
    points.push_back(arg.getPoint(i));
  
  size = arg.getSize();
  centroid = arg.getCentroid();

  return *this;
}

void Cluster::addPoint(Point _point) {
  points.push_back(_point);
  size = points.size();
  calculateCentroid();
}

int Cluster::getSize() const {
  return size;
}

Point Cluster::getCentroid() const {
  return centroid;
}

Point Cluster::getPoint(int index) const {
  return points[index];
}

void Cluster::calculateCentroid() {
  double _W = 0, _X = 0, _Y = 0, _Z = 0;
  
  for(int i = 0; i < size; i++) {
    _W += points[i].getW();
    _X += points[i].getX();
    _Y += points[i].getY();
    _Z += points[i].getZ();
  }

  _W /= size;
  _X /= size;
  _Y /= size;
  _Z /= size;

  centroid.setW(_W);
  centroid.setX(_X);
  centroid.setY(_Y);
  centroid.setZ(_Z);
}
