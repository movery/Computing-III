/*****************************************************************************/
/* Account.h                                                                 */
/*                                                                           */
/* Programmer: Michael Overy                                                 */
/*****************************************************************************/

#ifndef _ACCOUNT_H
#define _ACCOUNT_H

class Account {

 private:
  double balance;
 public:
  Account();
  Account(double);
  void credit(double);
  void debit(double);
  double getBalance();
  double addAccountBalance(Account);
};

#endif
