#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape {
public:
  Circle(double r) {
    _r = r;
  }
  double area() const {
    return _r * _r * 3.14;
  }
  double perimeter() const{
    return 2 * _r * 3.14;
  }
  double getr() const{
    return _r;
  }
private:
  double _r;
};

#endif
