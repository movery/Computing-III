/*****************************************************************************/
/* Polynomial.h                                                              */
/* 11/6/2014                                                                 */
/* Programmer: Michael Overy                                                 */
/*****************************************************************************/

// This implementation assumes the degree value of a coefficient is index - 1
// Therfore if a polynomial is defined using an array {1, 2, 3, 4} the
// resulting polynomial will be:  4x^3 3x^2 2x^1 1x^0

#ifndef _Polynomial_h
#define _Polynomial_h

class Polynomial {
 private:
  double *coefficients;
  int degree;
 public:
  Polynomial();                             // Default Constructor
  Polynomial(int);                          // Constructor
  Polynomial(double[], int);                // Constructor
  ~Polynomial();                            // Destructor
  void setCoefficient(double, int);         // Set Coefficient Function
  double getCoefficient(int) const;         // Get Coefficient Function
  int getDegree() const;                    // Get Degree Function
  void displayPolynomial();                 // Displays the Polynomial
  Polynomial(const Polynomial& arg);        // Copy Constructor
  Polynomial& operator=(const Polynomial&); // Assignment Operator
  
  // Overloaded Operators
  friend Polynomial operator+(const Polynomial&, const Polynomial&);
  friend Polynomial operator-(const Polynomial&, const Polynomial&);
  friend Polynomial operator*(const Polynomial&, const Polynomial&);
  Polynomial& operator+=(const Polynomial&);
  Polynomial& operator-=(const Polynomial&);
  Polynomial& operator*=(const Polynomial&);
};

#endif
