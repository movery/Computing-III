/*****************************************************************************/
/* Ezponent Program                                                          */
/* X to the power of Y                                                       */
/* Michael Overy                                                             */
/*****************************************************************************/

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int main() {

  double b, e;

  // User Prompt
  cout << "Please enter a base number and an exponent" << endl << "? ";

  // Input Code to check and clear cin when bad input is entered
  while(!(cin >> b >> e)) {
    cout << "Please enter a valid base number and exponent" << endl << "? ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  // Responds using the pow() function located in <cmath>
  cout << b << " to the power of " << e << " is " << pow(b, e) << "." << endl;

  return 0;
}
