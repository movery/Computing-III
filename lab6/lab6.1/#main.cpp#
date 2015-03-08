#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <string>
#include <sstream>
#include "Point.h"
#include "Cluster.h"

using namespace std;

void displayOutput(vector<Cluster>& arg);

double myDistance(Point arg1, Point arg2);

int main(int argc, char *argv[]) {
  
  vector<Cluster> ClusterList;
  vector<double> tempV;
  int K, shortestI, shortestJ;
  double shortestDistance;
  string input;
  double temp;
  int maxDimensions = 0;
  int countDimensions;

  // Code for K
  K = atoi(argv[1]);

  if(K < 1) {
    cout << "Error: K is less than 1." << endl;
    return 0;
  }

  // Gathering Input
  while(getline(cin, input)) {
    istringstream sin(input);
    
    for(countDimensions = 0; sin >> temp; countDimensions++) 
      tempV.push_back(temp);
      
    if(countDimensions != maxDimensions && maxDimensions != 0) {
      cout << "Error: Not all dimensions match up." << endl;
      return 0;
    } else {
      maxDimensions = countDimensions;
    }

    Point P(tempV);
    Cluster C(P);
    ClusterList.push_back(C);
    tempV.clear();
  }

  if(K > ClusterList.size()) {
    cout << "Error: K is greater than the amount of possible clusters." << endl;
    return 0;
  }

  // Clustering Algorithm
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

    cout << shortestI << " " << shortestJ << " " << shortestDistance << endl;
    
    for(int i = 0; i < ClusterList[shortestJ].getSize(); i++)
      ClusterList[shortestI].addPoint(ClusterList[shortestJ].getPoint(i));

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

double myDistance(Point arg1, Point arg2) {
 
  double distance = 0;
  vector<double> temp;

  for(int i = 0; i < arg1.getLOC().size(); i++) {
    temp.push_back(arg1.getLOC()[i] - arg2.getLOC()[i]);
    temp[i] *= temp[i];
  }
  for(int i = 0; i < arg1.getLOC().size(); i++) 
    distance += temp[i];

  distance = sqrt(distance);
  
  return distance;
}
