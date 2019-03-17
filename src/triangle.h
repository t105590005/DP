#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <math.h>
#include "shape.h"

class Triangle: public Shape {
public:
    Triangle(double a, double b, double c) {
        if ((a + b) < c || (a + c) < b || (b + c) < a) {
            throw std::string("Invalid triangle!");
        }
        _side[0] = a;
        _side[1] = b;
        _side[2] = c;
    }

    const double *getSides() const {return _side;}

    double area() const {
        double s = perimeter()/2;
        return sqrt(s * (s-_side[0]) * (s-_side[1]) * (s-_side[2]));
    }

    double perimeter() const {
        return _side[0] + _side[1] + _side[2];
    }
private:
    double _side[3];
};

#endif
