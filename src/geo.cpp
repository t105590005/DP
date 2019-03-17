#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "read_input.h"
#include "shape.h"
#include "sort.h"

int main(int args, char **argv) {
    if (args != 5) {
        std::cout << "Invalid number of args" << std::endl;
        return 0;
    }

    std::vector<Shape *> shapes = read_input(argv[1]);


    std::string const type = argv[3];
    std::string const sequence = argv[4];
    std::string const inc = "inc", dec = "dec";
    if (type == "area") {
        if (sequence == inc) {
            ShapeCompAreaInc comp;
            std::sort(shapes.begin(), shapes.end(), comp);
        }
        else if (sequence == dec) {
            ShapeCompAreaDec comp;
            std::sort(shapes.begin(), shapes.end(), comp);
        }
        else {
            std::cout << "Invalid sequence order" << std::endl;
            return 0;
        }
    }
    else if (type == "perimeter") {
        if (sequence == inc) {
            ShapeCompPerimeterInc comp;
            std::sort(shapes.begin(), shapes.end(), comp);
        }
        else if (sequence == dec) {
            ShapeCompPerimeterDec comp;
            std::sort(shapes.begin(), shapes.end(), comp);
        }
        else {
            std::cout << "Invalid sequence order" << std::endl;
            return 0;
        }
    }
    else {
        std::cout << "Invalid type" << std::endl;
        return 0;
    }

    write_output(argv[2], shapes);
    return 0;
}
