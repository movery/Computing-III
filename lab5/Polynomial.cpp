/*****************************************************************************/
/* Polynomial.cpp                                                            */
/* 11/6/2014                                                                 */
/* Programmer: Michael Overy                                                 */
/*****************************************************************************/

#include <iostream>
#include "Polynomial.h"

using namespace std;

// Default Constructor
Polynomial::Polynomial() {
  degree = 0;
  coefficients = new double[degree + 1];
  coefficients[0] = 0;
}

Polynomial::Polynomial(int _degree) {
  degree = _degree;
  coefficients = new double[degree + 1];
  for(int i = 0; i <= degree; i++)
    coefficients[i] = 0;
}

Polynomial::Polynomial(double *_coefficients, int _degree) {
  degree = _degree;
  coefficients = new double[degree + 1];
  for(int i = 0; i <= degree; i++) 
    coefficients[i] = _coefficients[i];
}

Polynomial::~Polynomial() {
  delete[] coefficients;
}

void Polynomial::setCoefficient(double _coeff, int _degree) {
  if(degree < _degree || _degree < 0) {
    cout << "Degree Value out of Range" << endl;
    return;
  }

  coefficients[_degree] = _coeff;
}

double Polynomial::getCoefficient(int _degree) const {
  if(degree < _degree || _degree < 0) {
    return 0;
  }

  return coefficients[_degree];
}

int Polynomial::getDegree() const {
  return degree;
}

void Polynomial::displayPolynomial(void) {
  for(int i = degree; i >= 0; i--)
    cout << coefficients[i] << "x^" << i << " ";
  cout << endl;
}

Polynomial::Polynomial(const Polynomial& arg) {

  degree = arg.getDegree();
  coefficients = new double[degree + 1];
  for(int i = 0; i <= degree; i++)
    coefficients[i] = arg.getCoefficient(i);
}

Polynomial& Polynomial::operator=(const Polynomial& arg) {

  if(this == &arg)
    return *this;

  degree = arg.getDegree();
  coefficients = new double[degree + 1];
  for(int i = 0; i <= degree; i++) 
    coefficients[i] = arg.getCoefficient(i);

  return *this;
}

Polynomial operator+(const Polynomial& arg1, const Polynomial& arg2) {
  
  int deg = arg1.getDegree() > arg2.getDegree() ? arg1.getDegree() : arg2.getDegree();

  Polynomial Sum(deg);

    for(int i = 0; i <= deg; i++) 
      Sum.setCoefficient(arg1.getCoefficient(i) + arg2.getCoefficient(i), i);
    

  return Sum;
}

Polynomial operator-(const Polynomial& arg1, const Polynomial& arg2) {
  int deg = arg1.getDegree() > arg2.getDegree() ? arg1.getDegree() : arg2.getDegree();

  Polynomial Difference(deg);
  
  for(int i = 0; i <= deg; i++) 
    Difference.setCoefficient(arg1.getCoefficient(i) - arg2.getCoefficient(i), i);
  

  return Difference;
}

Polynomial operator*(const Polynomial& arg1, const Polynomial& arg2) {
  int degree1 = arg1.getDegree();
  int degree2 = arg2.getDegree();
 
  double coef1;
  double coef2;

  Polynomial Product(degree1 + degree2);

  for(int i = 0; i <= degree1; i++) 
    for(int j = 0; j <= degree2; j++) {
      coef1 = arg1.getCoefficient(i);
      coef2 = arg2.getCoefficient(j);
      Product.setCoefficient(coef1*coef2+Product.getCoefficient(i+j), i+j);
    }
  
  return Product;
}

Polynomial& Polynomial::operator+=(const Polynomial& arg) {
  int deg = degree > arg.getDegree() ? degree : arg.getDegree();
  
  Polynomial Sum(deg);

  for(int i = 0; i <= deg; i++) 
    if(i <= degree)
      Sum.setCoefficient(coefficients[i] + arg.getCoefficient(i), i);
    else 
      Sum.setCoefficient(arg.getCoefficient(i), i);

  *this = Sum;

  return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& arg) {
  int deg = degree > arg.getDegree() ? degree : arg.getDegree();

  Polynomial Difference(deg);

  for(int i = 0; i <= deg; i++)
    if(i <= degree)
      Difference.setCoefficient(coefficients[i] - arg.getCoefficient(i), i);
    else
      Difference.setCoefficient(0 - arg.getCoefficient(i), i);

  *this = Difference;

  return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& arg) {
  int degree1 = degree;
  int degree2 = arg.getDegree();

  double coef1;
  double coef2;

  Polynomial Product(degree1 + degree2);

  for(int i = 0; i <= degree1; i++) 
    for(int j = 0; j <= degree2; j++) {
      coef1 = coefficients[i];
      coef2 = arg.getCoefficient(j);
      Product.setCoefficient(coef1*coef2+Product.getCoefficient(i+j), i+j);
    }

  *this = Product;
  
  return *this;
}
      
      
