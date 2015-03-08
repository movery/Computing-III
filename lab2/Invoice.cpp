#include <iostream>
#include <string>
#include "Invoice.h"

using namespace std;

Invoice::Invoice() {

  setPartNumber("");
  setPartDescription("");
  setAmountPurchased(0);
  setPrice(0);
}

Invoice::Invoice(string number, string description, int purchased, double price) {

  setPartNumber(number);
  setPartDescription(description);
  setAmountPurchased(purchased);
  setPrice(price);
}

void Invoice::setPartNumber(string number) {
  
  part_number = number;
}

string Invoice::getPartNumber() {

  return part_number;
}

void Invoice::setPartDescription(string description) {

  part_description = description;
}

string Invoice::getPartDescription() {

  return part_description;
}

void Invoice::setAmountPurchased(int purchased) {

  if(purchased < 0) {
    cout << "Negative Integers are not accepted. ";
    cout << "Amount Purchased set to 0 instead." << endl;
    amount_purchased = 0;
  } else 
    amount_purchased = purchased;
}

int Invoice::getAmountPurchased() {
  
  return amount_purchased;
}

void Invoice::setPrice(double x) {

  if(x < 0) {
    cout << "Negative Doubles are not accepted. ";
    cout << "Price set to 0 instead." << endl;
    price = 0;
  } else
    price = x;
}

double Invoice::getPrice() {

  return price;
}

double Invoice::getInvoiceAmount() {

  return price * (double)amount_purchased;
}
