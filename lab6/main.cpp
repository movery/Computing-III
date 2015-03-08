/*****************************************************************************/
/* main.cpp                                                                  */
/* 11/10/2014                                                                */
/* Programmer: Michael Overy                                                 */
/*****************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
#include "Point.h"
#include "Cluster.h"

using namespace std;

void displayOutput(vector<Cluster>& arg);

double myDistance(Point arg1, Point arg2) {
  double pq1 = arg1.getW() - arg2.getW();
  double pq2 = arg1.getX() - arg2.getX();
  double pq3 = arg1.getY() - arg2.getY();
  double pq4 = arg1.getZ() - arg2.getZ();

  pq1 *= pq1;
  pq2 *= pq2;
  pq3 *= pq3;
  pq4 *= pq4;

  double distance = sqrt(pq1 + pq2 + pq3 + pq4);

  return distance;
}

int main(int argc, char *argv[]) {

  int K;
  char buffer[256];
  vector<Cluster> ClusterList;
  double shortestDistance;
  int shortestI;
  int shortestJ;

  // COLLECT K VALUE
  K = atoi(argv[1]);

  if(K < 1) {
    cout << "K is less than 1. Please enter a positive, non-zero value" << endl;
    return 0;
  }
  
  // COLLECT INPUT
  // GRAB NUMBERS 4 AT A TIME
  while(cin >> buffer) {
    double W = atof(buffer);

    if(cin >> buffer == NULL) {
      cout << "Invalid Input." << endl;
      return 0;
    }
    double X = atof(buffer);

    if(cin >> buffer == NULL) {
      cout << "Invalid Input." << endl;
      return 0;
    }
    double Y = atof(buffer);

    if(cin >> buffer == NULL) {
      cout << "Invalid Input." << endl;
      return 0;
    }
    double Z = atof(buffer);
    
    Point P(W, X, Y, Z);
    Cluster C(P);
    ClusterList.push_back(C);
  }
  
  // ERROR CHECK K and INPUT
  if(K > ClusterList.size()) {
    cout << "K is greater than the amount of possible Clusters" << endl;
    return 0;
  }
  
  // Start looking for shortest distance
  while(ClusterList.size() > K) {
    for(int i = 0; i < ClusterList.size(); i++) {
      for(int j = i; j < ClusterList.size(); j++) {
	
	Point P1 = ClusterList[i].getCentroid();
	Point P2 = ClusterList[j].getCentroid();

	if(i != j)
	  if(i == 0 && j == 1) { 
	    shortestI = 0;
	    shortestJ = 1;
	    shortestDistance = myDistance(P1, P2);
	  } else 
	    if(shortestDistance > myDistance(P1, P2)) {
	      shortestI = i;
	      shortestJ = j;
	      shortestDistance = myDistance(P1, P2);
	    }
      }
    }

    for(int z = 0; z < ClusterList[shortestJ].getSize(); z++) 
      ClusterList[shortestI].addPoint(ClusterList[shortestJ].getPoint(z));

    ClusterList.erase(ClusterList.begin() + shortestJ);
  }
  
  displayOutput(ClusterList);

  return 0;
}

void displayOutput(vector<Cluster>& arg) {

  for(int i = 0; i < arg.size(); i++) {
    cout << "Cluster # " << i+1 << endl;
    for(int j = 0; j < arg[i].getSize(); j++) 
      arg[i].getPoint(j).displayPoint();
    
    cout << endl;
  }
}
