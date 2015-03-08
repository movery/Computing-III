#ifndef _CLUSTER_H
#define _CLUSTER_H

#include <vector>
#include "Point.h"

using std::vector;

class Cluster {
 private:
  vector<Point> points;
  int size;
 public:
  Cluster(Point);
  Cluster(const Cluster& arg);
  Cluster& operator=(const Cluster&);
  void addPoint(Point);
  int getSize () const;
  Point getPoint(int) const;
};

#endif
