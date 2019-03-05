#ifndef SORT_H
#define SORT_H

#include "shape.h"

class ShapeCompAreaInc {
public:
    bool operator() (Shape *a, Shape *b) {
        return a->area() < b->area();
    }
};

class ShapeCompPerimeterInc {
public:
    bool operator() (Shape *a, Shape *b) {
        return a->perimeter() < b->perimeter();
    }
};

class ShapeCompAreaDec {
public:
    bool operator() (Shape *a, Shape *b) {
        return a->area() > b->area();
    }
};

class ShapeCompPerimeterDec {
public:
    bool operator() (Shape *a, Shape *b) {
        return a->perimeter() > b->perimeter();
    }
};

#endif
