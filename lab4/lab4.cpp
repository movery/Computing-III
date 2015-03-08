/*****************************************************************************/
/* lab4.cpp                                                                  */
/* 10/30/2014                                                                */
/* Programmer: Michael Overy                                                 */
/*****************************************************************************/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void permute(vector<string> &arr, int i, int n);

int main() {

  string line;
  vector<string> arr;

  while(cin >> line) {   // Read strings in from stdin
    arr.push_back(line); // Put them in the vector
  }

  permute(arr, 0, arr.size() - 1);

  return 0;
}

void permute(vector<string> &arr, int i, int n) {

  static int count = 1;

  // If maximum depth is reached, print the vector
  if(i == n) {
    cout << count << ": ";
    count++;
    for(int j = 0; j < arr.size(); j++) {
      cout << arr[j] << ' ';
    }
    cout << endl;
  }

  // Recursively permute the array until maximum depth is reached
  else {
    for(int j = i; j <= n; j++) {
      arr[i].swap(arr[j]);
      permute(arr, i + 1, n);
      arr[i].swap(arr[j]);
    }
  }
}
