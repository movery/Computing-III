#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <string>
#include <sstream>
#include "Point.h"
#include "Cluster.h"

using namespace std;

// Prints current state of the cache
void printCache(vector<vector<double>> arg);

// Displays the current state of the Cluster Vector
void displayOutput(vector<Cluster>& arg);

// Computes the distance between 2 points
double myDistance(Point arg1, Point arg2);

// Calls myDistance to find the pairwise distance between 2 clusters
double clusterDistance(Cluster& arg1, Cluster& arg2);

int main(int argc, char *argv[]) {
  
  vector<Cluster> ClusterList;
  vector<vector<double>> cache;
  vector<double> tempV;
  int K, shortestI, shortestJ;
  double shortestDistance, currentDistance, temp;
  int maxDimensions = 0, countDimensions, flag;
  string input;

  // Load in the input file
  ifstream file("input.txt");

  // Code for K
  K = atoi(argv[1]);

  if(K < 1) {
    cout << "Error: K is less than 1." << endl;
    return 0;
  }

  // Gathering Input
  while(getline(file, input)) {
    istringstream sin(input);
    
    for(countDimensions = 0; sin >> temp; countDimensions++) 
      tempV.push_back(temp);
      
    // Initiate maxDimensions on first pass
    // See if later passes match first pass
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

  file.close();

  if(K > ClusterList.size()) {
    cout << "Error: K is greater than the amount of possible clusters." << endl;
    return 0;
  }
  
  for(int i = 0; i < ClusterList.size(); i++) {
    for(int j = 0; j < ClusterList.size(); j++)
      tempV.push_back(-2);
    cache.push_back(tempV);
    tempV.clear();
  }

   while(ClusterList.size() > K) {
    for(int i = 0; i < ClusterList.size(); i++) {
      for(int j = i; j < ClusterList.size(); j++) {
	if(i != j) {
	  if(true) 
	    cache[i][j] = clusterDistance(ClusterList[i], ClusterList[j]);
    	  if(i == 0 && j == 1) {
	    shortestI = 0;
	    shortestJ = 1;
	    shortestDistance = cache[i][j];
	  } else
	    if(shortestDistance > cache[i][j]) {
	      shortestI = i;
	      shortestJ = j;
	      shortestDistance = cache[i][j];
	    }
	}
      }
    }	  

    // Edit cache:
    // Everything in the I'th columns and rows must be recomputed
    // The J'th columns and rows need to be removed entirely (vector resizes)
    flag = 0;
    for(int i = 0; i < cache.size(); i++) {
      if(i == shortestI) {
	for(int k = 0; k < cache.size(); k++)
	  cache[i][k] = -2;
      }
      if(i == shortestJ) 
	cache.erase(cache.begin() + i);
      for(int j = 0; j < cache[i].size(); j++) {
	if(j == shortestI && flag == 0)
	  if(cache[i][j] == -2)
	    flag = 1;
	  else
	    cache[i][j] = -2;
	if(j == shortestJ)
	  cache[i].erase(cache[i].begin() + j);
      }  
    }

    // Formatting
    cout << "Merging: " << "\n" << "[";
    for(int j = 0; j < ClusterList[shortestI].getSize(); j++) {
      ClusterList[shortestI].getPoint(j).displayPoint();
      if(j != ClusterList[shortestI].getSize() - 1)
	cout << ", ";
    }
    cout << "]" << "\n" << "[";

    for(int j = 0; j < ClusterList[shortestJ].getSize(); j++) {
      ClusterList[shortestJ].getPoint(j).displayPoint();
      if(j != ClusterList[shortestJ].getSize() - 1)
	cout << ", ";
    }
    cout << "]" << "\n" << endl;

    // Merge I and J, and then delete J
    for(int i = 0; i < ClusterList[shortestJ].getSize(); i++)
      ClusterList[shortestI].addPoint(ClusterList[shortestJ].getPoint(i));

    ClusterList.erase(ClusterList.begin() + shortestJ);
  }

  displayOutput(ClusterList);

  return 0;
}

void printCache(vector<vector<double>> arg) {
  for(int i = 0; i < arg.size(); i++) {
    for(int j = 0; j < arg[i].size(); j++)
      cout << " " << arg[i][j] << " ";
    cout << endl;
  }
}

void displayOutput(vector<Cluster>& arg) {
  cout << "Resulting Clusters:" << endl;
  for(int i = 0; i < arg.size(); i++) {
    cout << "Cluster: [";
    for(int j = 0; j < arg[i].getSize(); j++) {
      arg[i].getPoint(j).displayPoint();
      if(j != arg[i].getSize() - 1)
	cout << ", ";
    }
    cout << "]" << endl;
  }
}

double clusterDistance(Cluster& arg1, Cluster& arg2) {
  double distance = 0;
  for(int i = 0; i < arg1.getSize(); i++)
    for(int j = 0; j < arg2.getSize(); j++) 
      distance += myDistance(arg1.getPoint(i), arg2.getPoint(j));
  distance /= arg1.getSize() * arg2.getSize();
  
  return distance;
}

double myDistance(Point arg1, Point arg2) {
 
  double distance = 0;
  vector<double> temp;

  for(int i = 0; i < arg1.getLOC().size(); i++) {
    temp.push_back(arg1.getLOC()[i] - arg2.getLOC()[i]);
    temp[i] *= temp[i];
  }
  for(int i = 0; i < temp.size(); i++) 
    distance += temp[i];

  distance = sqrt(distance);
  
  return distance;
}
