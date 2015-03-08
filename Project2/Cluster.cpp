#include <vector>
#include "Cluster.h"
#include "Point.h"

Cluster::Cluster(Point _point) {
  points.push_back(_point);
  size = points.size();
}

Cluster::Cluster(const Cluster& arg) {
  for(int i = 0; i < arg.getSize(); i++)
    points.push_back(arg.getPoint(i));

  size = arg.getSize();
}

Cluster& Cluster::operator=(const Cluster& arg) {
  if(this == &arg)
    return *this;

  points.clear();

  for(int i = 0; i < arg.getSize(); i++)
    points.push_back(arg.getPoint(i));

  size = arg.getSize();

  return *this;
}

void Cluster::addPoint(Point _point) {
  points.push_back(_point);
  size = points.size();
}

int Cluster::getSize() const {
  return size;
}

Point Cluster::getPoint(int index) const {
  return points[index];
}
