#ifndef trangle_h
#define trangle_h

#include "shape.h"
#include <math.h>

class Triangle : public Shape {
public:
  Triangle(double a, double b ,double c) {
    if((a + b) > c && (a + c) > b && (b + c) > a)
    {
      _a = a;
      _b = b;
      _c = c;
    }
    else
    {
      throw "can not create a trangle!\n";
    }
  }
  double area() const {
    double s = (_a + _b + _c) / 2;
    double ans = s * (s - _a) * (s - _b) * (s - _c);   
    return sqrt(ans);
  }
  double perimeter() const{
    return _a + _b + _c;
  }
  double geta() const{
    return _a;
  }
  double getb() const{
    return _b;
  }
  double getc() const{
    return _c;
  }
private:
  double _a;
  double _b;
  double _c;
};

#endif