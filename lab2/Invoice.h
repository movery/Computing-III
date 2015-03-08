#ifndef _INVOICE_H
#define _INVOICE_H

#include <string>
using namespace std;

class Invoice {

 private:
  string part_number;
  string part_description;
  int amount_purchased;
  double price;
 public:
  Invoice();
  Invoice(string, string, int, double);
  void setPartNumber(string);
  string getPartNumber();
  void setPartDescription(string);
  string getPartDescription();
  void setAmountPurchased(int);
  int getAmountPurchased();
  void setPrice(double);
  double getPrice();
  double getInvoiceAmount();
};

#endif
