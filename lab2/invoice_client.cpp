#include <iostream>
#include <string>
#include <limits>
#include "Invoice.h"

// Helper Functions to verify input is of the correct type.
// Use these with the x and y for input
void getDouble(double *);
void getInteger(int *);

int main() {
  
  // Variables used for input
  string s;
  int x;   
  double y;

  // Construct classes, 1 default, 1 not default
  Invoice item1("12345678", "Amazing", 20, 12.99);
  Invoice item2;
  
  cout << endl;

  // Display all of the information in item1
  cout << "item1 Information" << endl;
  cout << "Part Number: " << item1.getPartNumber() << endl;
  cout << "Part Description: " << item1.getPartDescription() << endl;
  cout << "Amount Purchased: "<< item1.getAmountPurchased() << endl;
  cout << "Price: $"<< item1.getPrice() << endl;
  cout << "Invoice Amount: $" << item1.getInvoiceAmount() << endl;

  cout << endl;

  // Begin entering information for item2
  cout << "Please enter a Part Number for item2" << endl << "? ";
  getline(cin, s); 
  item2.setPartNumber(s);
  
  cout << "Please enter a Part Description for item2" << endl << "? ";
  getline(cin, s); // Used to allow spaces in the description
  item2.setPartDescription(s);

  cout << "Please enter an Amount Purchased for item2" << endl << "? ";
  getInteger(&x);
  item2.setAmountPurchased(x);

  cout << "Please enter a Price for item2" << endl << "? ";
  getDouble(&y);
  item2.setPrice(y);

  cout << endl;

  // Display and verify all of the item2 information
  cout << "item2 Information" << endl;
  cout << "Part Number: " << item2.getPartNumber() << endl;
  cout << "Part Description: " << item2.getPartDescription() << endl;
  cout << "Amount Purchased: " << item2.getAmountPurchased() << endl;
  cout << "Price: $" << item2.getPrice() << endl;
  cout << "Invoice Amount: $" << item2.getInvoiceAmount() << endl;

  cout << endl;

  return 0;
}

void getDouble(double *y) {
  
  while(!(cin >> *y)) {
    cout << "Please enter a valid double." << endl << "? ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  cin.clear();
}

void getInteger(int *x) {
  
  while(!(cin >> *x)) {
    cout << "Please enter a valid integer." << endl << "? ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  cin.clear();
}
