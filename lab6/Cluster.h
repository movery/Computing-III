#ifndef _CLUSTER_H
#define _CLUSTER_H

#include <vector>
#include "Point.h"

using std::vector;

class Cluster {
 private:
  vector<Point> points;
  int size;
  Point centroid;
 public:
  Cluster(Point);
  Cluster(const Cluster& arg);
  Cluster& operator=(const Cluster&);
  void addPoint(Point);
  int getSize () const;
  Point getCentroid() const;
  Point getPoint(int) const;
  void calculateCentroid();
};

#endif
