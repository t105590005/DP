#include <gtest/gtest.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <cmath>

#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/sort.h"
#include "../src/read_input.h"
#include "../src/picture.h"

double const epsilon = 0.01;

int main(int argc, char ** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST (ShapeTest, Circle) {
  Circle c(1.0);
  ASSERT_NEAR(M_PI, c.area(), epsilon);
  ASSERT_NEAR(M_PI * 2, c.perimeter(), epsilon);
}

TEST (ShapeTest, Rectangle) {
  Rectangle r(3, 4);
  ASSERT_NEAR(12, r.area(), epsilon);
  ASSERT_NEAR(14, r.perimeter(), epsilon);
}

TEST (ShapeTest, Triangle) {
    Shape *t = new Triangle(7.5, 10.9, 15.3);
    ASSERT_NEAR(38.118, t->area(), epsilon);
    ASSERT_NEAR(33.7, t->perimeter(), epsilon);
}

TEST (ShapeTest, TriangleException) {
    ASSERT_ANY_THROW(new Triangle(1, 1, 5));
}

TEST(ShapeTest, SortByAreaInc) {
  Shape* test_array[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5, 6), new Triangle(3, 4, 5)};
  std::vector<Shape *> test_vector(test_array, test_array + 4);
  ShapeCompAreaInc compAreaInc;
  std::sort(test_vector.begin(), test_vector.end(), compAreaInc);
  ASSERT_NEAR(0.25*M_PI, test_vector[0]->area(), epsilon);
  ASSERT_NEAR(M_PI, test_vector[1]->area(), epsilon);
  ASSERT_NEAR(6.0, test_vector[2]->area(), epsilon);
  ASSERT_NEAR(30, test_vector[3]->area(), epsilon);
}

TEST(ShapeTest, SortByAreaDec) {
  Shape* test_array[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5, 6), new Triangle(3, 4, 5)};

  ShapeCompAreaDec compAreaDec;
  std::sort(test_array, test_array+4, compAreaDec);
  ASSERT_NEAR(30, test_array[0]->area(), epsilon);
  ASSERT_NEAR(6.0, test_array[1]->area(), epsilon);
  ASSERT_NEAR(M_PI, test_array[2]->area(), epsilon);
  ASSERT_NEAR(0.25*M_PI, test_array[3]->area(), epsilon);
}

TEST(ShapeTest, SortByPerimeterInc) {
  Shape* test_array[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5, 6), new Triangle(3, 4, 5)};

  ShapeCompPerimeterInc compPerimeterInc;
  std::sort(test_array, test_array+4, compPerimeterInc);
  ASSERT_NEAR(0.5 * 2 * M_PI, test_array[0]->perimeter(), epsilon);
  ASSERT_NEAR(1 * 2 * M_PI, test_array[1]->perimeter(), epsilon);
  ASSERT_NEAR(12, test_array[2]->perimeter(), epsilon);
  ASSERT_NEAR(22, test_array[3]->perimeter(), epsilon);
}

TEST(ShapeTest, SortByPerimeterDec) {
  Shape* test_array[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5, 6), new Triangle(3, 4, 5)};

  ShapeCompPerimeterDec compPerimeterDec;
  std::sort(test_array, test_array+4, compPerimeterDec);
  ASSERT_NEAR(22, test_array[0]->perimeter(), epsilon);
  ASSERT_NEAR(12, test_array[1]->perimeter(), epsilon);
  ASSERT_NEAR(1 * 2 * M_PI, test_array[2]->perimeter(), epsilon);
  ASSERT_NEAR(0.5 * 2 * M_PI, test_array[3]->perimeter(), epsilon);

}

TEST (ShapeTest, read_input) {
  std::vector<Shape *> shapes = read_input("test_files/input.txt");
  ASSERT_NEAR(M_PI, shapes[0]->area(), epsilon);
  sort(shapes.begin(), shapes.end(), [](Shape * a, Shape *b) {
    return a->area() < b->area();
  });
  ASSERT_NEAR(0.75, shapes[0]->area(), epsilon);
  ASSERT_NEAR(0.25*M_PI, shapes[1]->area(), epsilon);
  ASSERT_NEAR(sqrt(3)/4 * 2 * 2, shapes[2]->area(), epsilon);
  ASSERT_NEAR(M_PI, shapes[3]->area(), epsilon);
  ASSERT_NEAR(30, shapes[4]->area(), epsilon);

  write_output("test_files/output.txt", shapes);

  std::ifstream sample, result;
  sample.open("test_files/sample_output.txt");
  result.open("test_files/output.txt");

  std::string sampleLine, resultLine;
  while (std::getline(sample, sampleLine) && std::getline(result, resultLine)) {
      ASSERT_EQ(sampleLine, resultLine);
  }
  if (sampleLine != "") {
      FAIL() << "Length of output file less than expected\n";
  }
  if (std::getline(result, resultLine)) {
      FAIL() << "Length of output file more than expected\n";
  }
  sample.close();
  result.close();
}

TEST (ShapeTest, read_input_file_notfound) {
  ASSERT_ANY_THROW(read_input("InvalidddddFilllleeee.txt"));
}

TEST(ShapeTest,PictureArea)
{
  Picture picture;
  picture.addShape(new Circle(1));
  picture.addShape(new Rectangle(2, 4));

  ASSERT_NEAR(11.14, picture.area(), 0.1);
}

TEST(ShapeTest,PicturePerimeter)
{
  Picture picture;
  picture.addShape(new Circle(1));
  picture.addShape(new Rectangle(2, 4));

  ASSERT_NEAR(18.28, picture.perimeter(), 0.1);
}

TEST(ShapeTest, addShapeException) {
  Triangle triangle(3,4,5);
  ASSERT_ANY_THROW(triangle.addShape(new Circle(1)));
}