#ifndef RECTANGLE_h
#define RECTANGLE_h

#include "shape.h"

class Rectangle : public Shape {
public:
  Rectangle(double width, double length) {
    _w = width;
    _l = length;
  }
  double area() const {
    return _w * _l;
  }
  double perimeter() const{
    return (_w + _l) * 2;
  }
  double getw() const{
    return _w;
  }
  double getl() const{
    return _l;
  }
private:
  double _w;
  double _l;
};

#endif