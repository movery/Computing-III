#include <iostream>
#include "Shape.h"

using namespace std;

int main() {

  Shape *shape[5];

  Circle c1(10);
  Square s1(10);
  Triangle t1(10, 10, 10);
  Sphere sp1(10);
  Cube cu1(10);
  Tetrahedron te1(4, 5, 6, 7, 8, 9);

  shape[0] = &c1;
  shape[1] = &s1;
  shape[2] = &t1;
  shape[3] = &sp1;
  shape[4] = &cu1;
  shape[5] = &te1;

  for(int i = 0; i <= 5; i++) {
    if(shape[i]->getisThreeD()) {
      cout << "Shape Area is: " << shape[i]->getArea() << endl;
      cout << "Shape Volume is: " << shape[i]->getVolume() << endl;
    } else
      cout << "Shape Area is: " << shape[i]->getArea() << endl;
  }

  return 0;
}
