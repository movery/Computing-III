/*****************************************************************************/
/* Account.cpp                                                               */
/*                                                                           */
/* Programmer: Michael Overy                                                 */
/*****************************************************************************/

#include <iostream>
#include "Account.h"

using namespace std;

// Default Constructor
Account::Account() {

  balance = 0;
}

// Input Constructor
Account::Account(double deposit) {
  
  if(deposit < 0) {
    cout << "Initial Balance is invalid. Set to 0 instead." << endl;
    balance = 0;
  }
  else
    balance = deposit;
}

// Deposit Function
// Checks if input is negative
void Account::credit(double deposit) {
 
  if(deposit < 0) 
    cout << "Input is a negative number. No change has been made." << endl;
  else
    balance += deposit;
}

// Withdrawal Function
// Checks if input is negative or exceeds balance
void Account::debit(double withdrawal) {

  if(withdrawal < 0)
    cout << "Input is a negative number. No change has been made." << endl;
  else if(withdrawal > balance) 
    cout << "Debit amount exceeded account balance. No change has been made." << endl;
  else
    balance -= withdrawal;
}

// Balance Checker Function
double Account::getBalance() {

  return balance;
}

// Reports the combined balance of 2 accounts
double Account::addAccountBalance(Account secondAccount) {
  
  return balance + secondAccount.getBalance();
}
