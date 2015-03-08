/*****************************************************************************/
/* account_client.cpp                                                        */
/*                                                                           */
/* Programmer: Michael Overy                                                 */
/*****************************************************************************/

#include <iostream>
#include <limits>
#include "Account.h"

// Helper Function to take input and verify it is a double
void getDouble(double *);

using namespace std;

int main() {

  double x;

  Account account1;
  Account account2(100);

  // Initial Balance Check
  cout << "account1 has $" << account1.getBalance() << "." << endl;
  cout << "account2 has $" << account2.getBalance() << "." << endl;

  // Testing of member function debit
  cout << "How much would you like to withdraw from account1" << endl << "? ";
  getDouble(&x);
  account1.debit(x);
  
  cout << "How much would you like to withdraw from account2\n? ";
  getDouble(&x);
  account2.debit(x);

  // Secong Balance Check
  cout << "account1 has $" << account1.getBalance() << "." << endl;
  cout << "account2 has $" << account2.getBalance() << "." << endl;

  // Testing of member function credit
  cout << "How much would you like to deposit into account1\n? ";
  getDouble(&x);
  account1.credit(x);

  cout << "How much would you like to deposit into account2\n? ";
  getDouble(&x);
  account2.credit(x);

  // Third Balance Check
  cout << "account1 has $" << account1.getBalance() << "." << endl;
  cout << "account2 has $" << account2.getBalance() << "." << endl;

  // Testing of member function addAccountBalance
  cout << "account1 and account2 have a combined balance of $" << account1.addAccountBalance(account2) << "." << endl;
  
  return 0;
}

// Helper Function to take input and verify it is a double
void getDouble(double *x) {

  while(!(cin >> *x)) {
    cout << "Please enter a valid double." << endl << "? ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  cin.clear();
}
