#include <vector>
#include "Cluster.h"
#include "Point.h"

Cluster::Cluster(Point _point) : centroid(_point.getLOC()) {
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
  vector<double> _LOC = points[0].getLOC();

  for(int i = 1; i < size; i++) 
    for(int j = 0; j < _LOC.size(); j++) 
      _LOC[j] += points[i].getLOC()[j];
  
  for(int i = 0; i < _LOC.size(); i++)
    _LOC[i] /= size;

  centroid.setLOC(_LOC);
}
