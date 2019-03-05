#include <iostream>
#include <vector>
#include <algorithm>
#include "read_input.h"
#include "shape.h"
#include "sort.h"

using namespace std;

int main(int argc, char *argv[]) 
{
    if (!(argc == 5)) {
        cout << "參數輸入錯誤" << endl;
        return true;
    }
    vector<Shape *> shapes;
    shapes = read_input(argv[1]);
    if(string(argv[3]) == "area")
    {
        if(string(argv[4]) == "inc")
        {
            ShapeCompAreaInc compareainc;
            sort(shapes.begin(), shapes.end(), compareainc);
        }
        else if(string(argv[4]) == "dec")
        {
            ShapeCompAreaDec compareadec;
            sort(shapes.begin(), shapes.end(), compareadec);
        }
        else
        {
            cout << "輸入錯誤" << endl;
        }
    }
    else  if(string(argv[3]) == "perimeter")
    {
        if(string(argv[4]) == "inc")
        {
            ShapeCompPerimeterInc compperimeterinc;
            sort(shapes.begin(), shapes.end(), compperimeterinc);
        }
        else if(string(argv[4]) == "dec")
        {
            ShapeCompPerimeterDec compperimeterdec;
            sort(shapes.begin(), shapes.end(), compperimeterdec);
        }
        else
        {
            cout << "輸入錯誤" << endl;
        }
    }
    else
    {
        cout << "輸入錯誤" << endl;
    }

    write_output(argv[2] , shapes);
    return 0;
}
