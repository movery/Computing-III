/*****************************************************************************/
/* Factorial of an integer                                                   */
/* (Up to and including 20)                                                  */
/* Michael Overy                                                             */
/*****************************************************************************/
#include <iostream>
#include <limits>

using namespace std;

// Recursively finds the factorial of an integer
long long factorial(long long);

// Main Function to prompt the user. Calls factorial()
int main() {

  int n;
  char response;
   // Loop until user wishes to end.
  do {
    cout << "Please enter a positive integer" << endl << "? ";

    // Input code to clear cin and prompts the user to enter valid information
    // when invalid characters are entered
    while(!(cin >> n) || n < 0) {
      cout << "Please enter a valid positive integer" << endl << "? ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if(n > 20) 
      cout << "Integer Overflow" << endl; 
    
    cout << "The factorial of " << n << " is " << factorial((long long)n) << "." << endl;

    cout << "Would you like to compute another factorial? (y or n)" << endl << "? ";
    cin >> response;
  } while(response == 'y');

  cout << "Exiting Program" << endl;

  return 0;
}

// Recursively finds the factorial of a numbe.
long long factorial(long long n) {

  if(n <= 1)
    return 1;

  return n * factorial(n - 1);
}
