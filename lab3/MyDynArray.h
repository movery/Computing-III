/*****************************************************************************/
/* MyDynArray.h                                                              */
/* 10/7/2014                                                                 */
/* Programmer: Michael Overy                                                 */
/*****************************************************************************/

#ifndef _MYDYNARRAY_H
#define _MYDYNARRAY_H

typedef int T;

class MyDynArray {

 private:
  size_t size;   // Number of elements in the array
  T *array_ptr;  // Array Pointer

 public:
  MyDynArray(size_t size_ = 100); // Constructor
  size_t getSize() const;         // Returns the size of the array
  bool set(T element, size_t index); // Assigns an element to an index
  T get(size_t index) const;         // Gets an element from the index
  MyDynArray(const MyDynArray& arg); // Copy Constructor
  MyDynArray& operator=(const MyDynArray& arg); // Assignment Operator
  ~MyDynArray(); // Destructor
};

#endif
