#ifndef CANVAS_H
#define CANVAS_H
#include <vector>
#include "shape.h"

class Picture: public Shape {
public:
    void addShape(Shape *s) {
        shapes.push_back(s);
    }

    double area() const {
        double area = 0.0;
        for(int i = 0 ; i < shapes.size() ; i++)
        {
            area = area + shapes[i]->area();
        }
        return area;
    }

    double perimeter() const {
        double perimeter = 0.0;
        for(int i = 0 ; i < shapes.size() ; i++)
        {
            perimeter = perimeter + shapes[i]->perimeter();
        }
        return perimeter;
    }

private:
    std::vector<Shape *> shapes;
};

#endif
