#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
  double coef1[3] = {1, 2, 3};
  Polynomial poly1(coef1, 2);
  cout << "Poly1: ";
  poly1.displayPolynomial();

  double coef2[6] = {5, 3, 2, 6, 4, 3};
  Polynomial poly2(coef2, 5);
  cout << "Poly2: ";
  poly2.displayPolynomial();

  Polynomial poly3 = poly1 + poly2;
  cout << "Poly1 + Poly2 (Copy Constructor): ";
  poly3.displayPolynomial();

  poly3 = poly1 - poly2;
  cout << "Poly1 - Poly2: ";
  poly3.displayPolynomial();

  poly3 = poly1 * poly2;
  cout << "Poly1 * Poly2: ";
  poly3.displayPolynomial();

  poly1 += poly2;
  cout << "Poly1 += Poly2: ";
  poly1.displayPolynomial();

  poly1 -= poly1;
  cout << "Poly1 -= Poly1: ";
  poly1.displayPolynomial();

  poly2 *= poly1;
  cout << "Poly2 *= Poly1: ";
  poly1.displayPolynomial();

  return 0;
}
