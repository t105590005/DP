#ifndef READ_INPUT_H
#define READ_INPUT_H

#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

std::vector<Shape *> read_input(std::string filePath) {
    std::vector<Shape *> vShape;
    std::ifstream inputFile;

    inputFile.open(filePath);
    if (!inputFile.is_open()) {
        throw std::string("file not found");
    }
    std::string line;

    while(std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string shapeName;
        ss >> shapeName;
        Shape *shape;
        if (shapeName == "circle") {
            double r;
            ss >> r;
            shape = new Circle(r);
        }
        else if (shapeName == "rectangle") {
            double l, w;
            ss >> l >> w;
            shape = new Rectangle(w, l);
        }
        else if (shapeName == "triangle") {
            double a, b, c;
            ss >> a >> b >> c;
            shape = new Triangle(a, b, c);
        }
        else {
            throw std::string("Unsupported shape");
        }
        vShape.push_back(shape);
    }
    inputFile.close();
    return vShape;
}

void write_output(std::string filePath, std::vector<Shape *> shapes) {
    std::ofstream outputFile;
    outputFile.open(filePath);
    int size = shapes.size();
    for (int i = 0; i < size; ++i) {
        Shape *shape = shapes[i];
        std::string shapeType;
        Circle *circle = dynamic_cast<Circle *>(shape);
        if (circle != 0) {
            shapeType = "circle";
            double r = circle->getRadius();
            outputFile << shapeType << " " << r << std::endl;
        }
        Rectangle *rectangle = dynamic_cast<Rectangle *>(shape);
        if (rectangle != 0) {
            shapeType = "rectangle";
            double l = rectangle->getLength();
            double w = rectangle->getWidth();
            outputFile << shapeType << " " << l << " " << w << std::endl;
        }
        Triangle *triangle = dynamic_cast<Triangle *>(shape);
        if (triangle != 0) {
            shapeType = "triangle";
            const double *sides = triangle->getSides();
            outputFile << shapeType << " " << sides[0] << " " << sides[1] << " " << sides[2] << std::endl;
        }
    }

    outputFile.close();
}
#endif
