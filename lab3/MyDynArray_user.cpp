/*****************************************************************************/
/* MyDynArray_user.cpp                                                       */
/* 10/7/2014                                                                 */
/* Programmer: Michael Overy                                                 */
/*****************************************************************************/

#include <iostream>
#include <string>

#include "MyDynArray.h"

using namespace std;

// Function to print the array
void print(MyDynArray a, string prefix = "") {
  
  cout << prefix;
  for(int i = 0; i < a.getSize(); i++)
    cout << a.get(i) << " ";
  cout << endl;
}

int main() {

  // Testing Copy Constructor
  cout << "***** Testing Copy Constructor *****\n";
  bool copy_constructor_failed = false;
  MyDynArray a(10);
  print(a, "a: ");
  a.set(3, 9);
  MyDynArray b = a;
  print(b, "b: ");
  b.set(-2, 9);
  print(b, "b: ");
  print(a, "a: ");

  if(a.get(9) == b.get(9))
    copy_constructor_failed = true;

  if(copy_constructor_failed)
    cout << "FAILED: Copy Constructor\n";
  else
    cout << "PASSED: Copy Constructor\n";

  // Testing Assignment Operator
  cout << "***** Testing assignment operator *****\n";
  bool assignment_operator_failed = false;
  MyDynArray c;
  c = a;
  print(c, "c: ");
  c.set(-4, 3);
  print(c, "c: ");
  print(a, "a: ");

  if (a.get(9) != c.get(9))
    assignment_operator_failed = true;
  if (a.get(3) == c.get(3))
    assignment_operator_failed = true;
  

  if (assignment_operator_failed)
    cout << "FAILED: Assignment operator\n";
  else
    cout << "PASSED: Assignment operator\n";
  
  // Testing Constructor
  cout << "***** Testing Constructor *****\n";
  MyDynArray d1(10);
  MyDynArray d2(0);
  MyDynArray d3(-2);
  if ((d1.getSize() == 10) && (d2.getSize() == 0) && (d3.getSize() == 0))
    cout << "PASSED: constructor argument validation\n";
  else
    cout << "FAILED: constructor argument validation\n";

  // Testing Setting Out of Size Range
  cout << "***** Testing setting an element outside of array range *****\n";
  MyDynArray s1(10);
  MyDynArray s2(5);
  MyDynArray s3(20);

  if(!s1.set(5, 13)) 
    cout << "Did not allocate extra space for s1" << endl;
  if(!s2.set(5, -2))
    cout << "Did not allocate extra space for s2" << endl;
  if(!s3.set(5, 1000000000000000000))
    cout << "Did not allocate extra space for s3" << endl;

  if(s1.get(13) == 5 && s1.getSize() == 13) 
    cout << "PASSED: Array Expansion" << endl;
  else
    cout << "FAILED: Array Expansion" << endl;

  return 0;
}
