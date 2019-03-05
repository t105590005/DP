#include <gtest/gtest.h>
#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/sort.h"
#include "../src/read_input.h"
#include <algorithm>

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST (ShapeTest, CircleArea)
{
  Circle circle(1);
  ASSERT_NEAR(3.14, circle.area(), 0.01);
}

TEST (ShapeTest, Circleperimeter)
{
  Circle circle(1);
  ASSERT_NEAR(6.28, circle.perimeter(), 0.01);
}

TEST (ShapeTest, RectangleArea)
{
  Rectangle rectangle(2, 4);
  ASSERT_NEAR(8, rectangle.area(), 0.01);
}

TEST (ShapeTest, Rectangleperimeter)
{
  Rectangle rectangle(2, 4);
  ASSERT_NEAR(12, rectangle.perimeter(), 0.01);
}

TEST (ShapeTest, TriangleArea)
{
  Triangle triangle (3, 4, 5);
  ASSERT_NEAR(6, triangle.area(), 0.01);
}

TEST (ShapeTest, Triangleperimeter)
{
  Triangle triangle (3, 4, 5);
  ASSERT_NEAR(12, triangle.perimeter(), 0.01);
}

TEST (ShapeTest, TriangleException)
{
  ASSERT_ANY_THROW(Triangle triangle (1,1,2););
}

TEST (ShapeTest, SortingPolymorphicShapesArea)
{
  ShapeCompAreaInc compinc;
  ShapeCompAreaDec compdec;
  Shape * a[] = {new Rectangle(2,4), new Circle(1), new Triangle(3,4,5)};

  std::sort(a,a+3, compinc);
  ASSERT_NEAR(3.14, a[0]->area(),0.01);
  ASSERT_NEAR(6, a[1]->area(),0.01);
  ASSERT_NEAR(8, a[2]->area(),0.01);
  
  std::sort(a,a+3, compdec);
  ASSERT_NEAR(3.14, a[2]->area(),0.01);
  ASSERT_NEAR(6, a[1]->area(),0.01);
  ASSERT_NEAR(8, a[0]->area(),0.01);
}

TEST (ShapeTest, SortingPolymorphicShapesPerimeter)
{
  ShapeCompPerimeterInc compinc;
  ShapeCompPerimeterDec compdec;
  Shape * a[] = {new Rectangle(2,4), new Circle(1), new Triangle(3,4,5)};

  std::sort(a,a+3, compinc);
  ASSERT_NEAR(6.28, a[0]->perimeter(),0.01);
  ASSERT_NEAR(12, a[1]->perimeter(),0.01);
  ASSERT_NEAR(12, a[2]->perimeter(),0.01);

  std::sort(a,a+3, compdec);
  ASSERT_NEAR(12, a[0]->perimeter(),0.01);
  ASSERT_NEAR(12, a[1]->perimeter(),0.01);
  ASSERT_NEAR(6.28, a[2]->perimeter(),0.01);
}

TEST(ShapeTest, read_input_notfind)
{
  ASSERT_ANY_THROW(read_input("nofile.txt"););
}

TEST(ShapeTest, read_input) 
{
    vector<Shape *> shapes = read_input("input.txt");

    Circle *circle;
    Rectangle *rectangle;
    Triangle *triangle;

    circle = dynamic_cast<Circle *>(shapes[0]);
    ASSERT_TRUE(circle);
    ASSERT_EQ(1.0, circle->getr());

    circle = dynamic_cast<Circle *>(shapes[1]);
    ASSERT_TRUE(circle);
    ASSERT_EQ(0.5, circle->getr());

    rectangle = dynamic_cast<Rectangle *>(shapes[2]);
    ASSERT_TRUE(rectangle);
    ASSERT_EQ(5, rectangle->getw());
    ASSERT_EQ(6, rectangle->getl());

    rectangle = dynamic_cast<Rectangle *>(shapes[3]);
    ASSERT_TRUE(rectangle);
    ASSERT_EQ(0.5, rectangle->getw());
    ASSERT_EQ(1.5, rectangle->getl());

    triangle = dynamic_cast<Triangle *>(shapes[4]);
    ASSERT_TRUE(triangle);
    ASSERT_EQ(3, triangle->geta());
    ASSERT_EQ(4, triangle->getb());
    ASSERT_EQ(5, triangle->getc());
}

TEST(ShapeTest,write_output)
{
    ShapeCompAreaInc comp;
    fstream file;
    string output;
    vector<Shape *> shapes = read_input("input.txt");
    std::sort(shapes.begin(), shapes.end(), comp);

    write_output("output.txt", shapes);

    file.open("output.txt", ios::in);

    getline(file, output);
    ASSERT_EQ("rectangle 0.5 1.5", output);

    getline(file, output);
    ASSERT_EQ("circle 0.5", output);

    getline(file, output);
    ASSERT_EQ("circle 1", output);

    getline(file, output);
    ASSERT_EQ("triangle 3 4 5", output);

    getline(file, output);
    ASSERT_EQ("rectangle 5 6", output);
}