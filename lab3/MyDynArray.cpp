/*****************************************************************************/
/* MyDynArray.cpp                                                            */
/* 10/7/2014                                                                 */
/* Programmer: Michael Overy                                                 */
/*****************************************************************************/

#include <iostream>
#include "MyDynArray.h"

using namespace std;

MyDynArray::MyDynArray(size_t size_) {

  cout << "Consructor Called with size " << size_ << endl;

  size = size_;

  // Attempt to allocate memory for 'size' integers
  // Set size to 0 if not enough space can be allocated
  try { 
    array_ptr = new T[size];
  } catch(bad_alloc&) {
    cout << "Exception bad_alloc caught" << endl;
    size = 0;
    array_ptr = new T[size];
  }
}

size_t MyDynArray::getSize() const {

  return size;
}

bool MyDynArray::set(T element, size_t index) {

  cout << "Function set() called with element " << element << " and index " << index << endl;

  T* new_ptr;
  
  // If index is out of range, attempt to allocate space for an array of 
  // 'index' elements.
  if(index > size) {
    try {
      new_ptr = new T[index];
    } catch(bad_alloc&) {
      cout << "Exception bad_alloc caught" << endl;
      return false;
    }
    
    // Copy the values from the old array to the re-sized one
    for(int i = 0; i < size; i++) 
      new_ptr[i] = array_ptr[i];
    
    // Move array_ptr over to the new array
    delete[] array_ptr;
    size = index;
    array_ptr = new_ptr;
  }

  array_ptr[index] = element;

  return true;
}

T MyDynArray::get(size_t index) const {

  return array_ptr[index];
}

MyDynArray::MyDynArray(const MyDynArray& arg) {

  cout << "Copy Constructor Called" << endl;

  // Allocate space for the new array
  size = arg.getSize();
  array_ptr = new T[size];

  // Copy each element into the new array
  for(int i = 0; i < size; i++) 
    array_ptr[i] = arg.get(i);
}

MyDynArray& MyDynArray::operator=(const MyDynArray& arg) {

  cout << "Assignment operator called" << endl;

  // Check for self-assignment
  if(this == &arg)
    return *this;

  // Delete the old array that array_ptr was point to and assign it new space
  delete[] array_ptr;
  size = arg.getSize();
  array_ptr = new T[size];

  // Copy each element into the new array
  for(int i = 0; i < size; i++) 
    array_ptr[i] = arg.get(i);

  return *this;
}

MyDynArray::~MyDynArray() {
  
  cout << "Destructor Called" << endl;
  
  delete[] array_ptr;
}
