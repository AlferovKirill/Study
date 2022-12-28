#include <iostream>
#include "../inc/Shapes.h"

int main() {
	Square square_1, square_2(Point(0, 0), Point(3, 0), Point(3, 3), Point(0, 3));
	std::cout << square_1 << std::endl << "Square area #1 = " << square_1.area() << ", Perimeter #1 = " << square_1.perimeter() << std::endl;
	std::cout << square_2 << std::endl << "Square #2 area = " << square_2.area() << ", Perimeter #2 = " << square_2.perimeter() << std::endl << std::endl;

	Rectangle rectangle_1, rectangle_2(Point(0, 0), Point(6, 0), Point(6, 3), Point(0, 3));
	std::cout << rectangle_1 << std::endl << "Rectangle area = " << rectangle_1.area() << ", Perimeter #1 = " << rectangle_1.perimeter() << std::endl;
	std::cout << rectangle_2 << std::endl << "Rectangle #2 area = " << rectangle_2.area() << ", Perimeter #2 = " << rectangle_2.perimeter() << std::endl << std::endl;

	Triangle triangle_1, triangle_2(Point(0, 0), Point(6, 0), Point(3, 3));
	std::cout << triangle_1 << std::endl << "Triangle area = " << triangle_1.area() << ", Perimeter #1 = " << triangle_1.perimeter() << std::endl;
	std::cout << triangle_2 << std::endl << "Triangle #2 area = " << triangle_2.area() << ", Perimeter #2 = " << triangle_2.perimeter() << std::endl << std::endl;

	Polygon polygon_1, polygon_2(Point(3, 3), Point(4, 3), Point(5, 4), Point(5, 5), Point(4, 6), Point(3, 6), Point(2, 5), Point(2, 4));
	std::cout << polygon_1 << std::endl << "Polygon area = " << polygon_1.area() << ", Perimeter #1 = " << polygon_1.perimeter() << std::endl;
	std::cout << polygon_2 << std::endl << "Polygon #2 area = " << polygon_2.area() << ", Perimeter #2 = " << polygon_2.perimeter() << std::endl << std::endl;

	Circle circle_1, circle_2(Point(2, 2), 2);
	std::cout << circle_1 << std::endl << "Circle #1 area = " << circle_1.area() << ", Perimeter #1 = " << circle_1.perimeter() << std::endl;
	std::cout << circle_2 << std::endl << "Circle #2 area = " << circle_2.area() << ", Perimeter #2 = " << circle_2.perimeter() << std::endl << std::endl;

	Ellipse ellipse_1, ellipse_2(Point(2, 1), 3, 4);
	std::cout << ellipse_1 << std::endl << "Ellipse #1 area = " << ellipse_1.area() << ", Perimeter #1 = " << ellipse_1.perimeter() << std::endl;
	std::cout << ellipse_2 << std::endl << "Ellipse #2 area = " << ellipse_2.area() << ", Perimeter #2 = " << ellipse_2.perimeter() << std::endl << std::endl;
}