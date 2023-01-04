#include <iostream>
#include "../inc/Shapes.h"

void test(const Shape& shape_1, const Shape& shape_2) {
	std::cout << shape_1 << std::endl << "Shape area #1 = " << shape_1.Area() << ", Perimeter #1 = " << shape_1.Perimeter() << std::endl;
	std::cout << shape_2 << std::endl << "Shape area #2 = " << shape_2.Area() << ", Perimeter #2 = " << shape_2.Perimeter() << std::endl << std::endl;

	std::cout << "(shape_1 == shape_2) = " << shape_1.operator==(shape_2) << std::endl;
	std::cout << "Congruence(shape_1, shape_2) = " << Congruence(shape_1, shape_2) << std::endl;
	std::cout << "Similarity(shape_1, shape_2) = " << Similarity(shape_1, shape_2) << std::endl;

	std::cout << std::endl << "-----------------------" << std::endl << std::endl;
}

int main() {
	Square square_1(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2));
	Square square_2(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2));
	Square square_3(Point(2, 2), Point(4, 2), Point(4, 4), Point(2, 4));
	Square square_4(Point(2, 2), Point(8, 2), Point(8, 8), Point(2, 8));

	std::cout << "\t~~~ Square ~~~" << std::endl;

	test(square_1, square_2);
	test(square_1, square_3);
	test(square_1, square_4);

	Rectangle rectangle_1(Point(0, 0), Point(2, 0), Point(2, 1), Point(0, 1));
	Rectangle rectangle_2(Point(0, 0), Point(2, 0), Point(2, 1), Point(0, 1));
	Rectangle rectangle_3(Point(2, 2), Point(4, 2), Point(4, 3), Point(2, 3));
	Rectangle rectangle_4(Point(2, 2), Point(6, 2), Point(6, 4), Point(2, 4));

	std::cout << "\t~~~ Rectangle ~~~" << std::endl;

	test(rectangle_1, rectangle_2);
	test(rectangle_1, rectangle_3);
	test(rectangle_1, rectangle_4);

	Polygon polygon_1(Point(0, 0), Point(2, 0), Point(2, 1), Point(1, 2), Point(0, 1));
	Polygon polygon_2(Point(0, 0), Point(2, 0), Point(2, 1), Point(1, 2), Point(0, 1));
	Polygon polygon_3(Point(2, 2), Point(4, 2), Point(4, 3), Point(3, 4), Point(2, 3));
	Polygon polygon_4(Point(2, 2), Point(6, 2), Point(6, 4), Point(4, 6), Point(2, 4));

	std::cout << "\t~~~ Polygon ~~~" << std::endl;

	test(polygon_1, polygon_2);
	test(polygon_1, polygon_3);
	test(polygon_1, polygon_4);

	Triangle triangle_1(Point(2, 1), Point(1, 2), Point(0, 1));
	Triangle triangle_2(Point(2, 1), Point(1, 2), Point(0, 1));
	Triangle triangle_3(Point(4, 3), Point(3, 4), Point(2, 3));
	Triangle triangle_4(Point(6, 4), Point(4, 6), Point(2, 4));

	std::cout << "\t~~~ Triangle ~~~" << std::endl;

	test(triangle_1, triangle_2);
	test(triangle_1, triangle_3);
	test(triangle_1, triangle_4);

	Circle circle_1(Point(1, 1), 2);
	Circle circle_2(Point(1, 1), 2);
	Circle circle_3(Point(1, 3), 2);
	Circle circle_4(Point(1, 0), 5);

	std::cout << "\t~~~ Circle ~~~" << std::endl;

	test(circle_1, circle_2);
	test(circle_1, circle_3);
	test(circle_1, circle_4);

	Ellipse ellipse_1(Point(1, 1), 2, 4);
	Ellipse ellipse_2(Point(1, 1), 2, 4);
	Ellipse ellipse_3(Point(1, 3), 2, 4);
	Ellipse ellipse_4(Point(1, 0), 6, 12);

	std::cout << "\t~~~ Ellipse ~~~" << std::endl;

	test(ellipse_1, ellipse_2);
	test(ellipse_1, ellipse_3);
	test(ellipse_1, ellipse_4);

	return 0;
}