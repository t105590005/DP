#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>
#include "shape.h"

class Circle : public Shape {
public:
  Circle(double r) {
    _r = r;
  }

  double area() const {
    return _r * _r * M_PI;
  }

  double perimeter() const {
      return 2 * _r * M_PI;
  }

  double getRadius() const {
      return _r;
  }
private:
  double _r;
};

#endif
