#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

using namespace std;

vector<Shape *> read_input (string filePath)
{
    fstream file;
    file.open(filePath,ios::in);
    if (!file)//判斷檔案有沒有開成功
    {
        throw "檔案無法開啟!";
    }
    vector<Shape *> shapes;
    string read;
    double r , w , l , a , b , c;
    while(getline(file, read))
    {
        stringstream ss;
        ss << read;
        string type;
        ss >> type;
        if(type == "circle")
        {
            ss  >> r;
            shapes.push_back(new Circle(r));
        }
        else if(type == "rectangle")
        {
            ss  >> w >> l;
            shapes.push_back(new Rectangle(w,l));
        }
        else if(type == "triangle")
        {
            ss  >> a >> b >> c;
            shapes.push_back(new Triangle(a,b,c));
        }
    }
    return shapes;
}
void write_output(string filePath , vector<Shape *>shapes)
{
    fstream file;
    file.open(filePath, ios::out);
    for(int i = 0; i < shapes.size(); i++)
    {
        Shape *shape = shapes[i];
        Circle *circle = dynamic_cast<Circle *>(shape);
        Rectangle *rectangle = dynamic_cast<Rectangle *>(shape);
        Triangle *triangle = dynamic_cast<Triangle *>(shape);
        if(circle != 0)
        {
            file << "circle " << circle->getr() << "\n";
            continue;
        }
        else if(rectangle != 0)
        {
            file << "rectangle " << rectangle->getw() << " " << rectangle->getl() << "\n";
            continue;
        }
        if(triangle != 0)
        {
            file << "triangle " << triangle->geta() <<  " " << triangle->getb() <<  " " << triangle->getc() << "\n";
            continue;
        }
    }
}