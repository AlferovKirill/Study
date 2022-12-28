#include "../inc/Shapes.h"

//Shape
std::ostream& operator<<(std::ostream& out, const Shape& shape) {
	for (Point point : shape.points) {
		out << point << " ";
	}

	return out;
}

//Square
Square::Square() {
	points.push_back(Point(0.0, 0.0));
	points.push_back(Point(1.0, 0.0));
	points.push_back(Point(1.0, 1.0));
	points.push_back(Point(0.0, 1.0));
}

Square::Square(Point point_1, Point point_2, Point point_3, Point point_4) {
	points.push_back(point_1);
	points.push_back(point_2);
	points.push_back(point_3);
	points.push_back(point_4);
}

double Square::area() const {
	double a = std::sqrt((points[0].x - points[1].x) * (points[0].x - points[1].x) + (points[0].y - points[1].y) * (points[0].y - points[1].y));

	return a * a;
}

double Square::perimeter() const {
	double a = std::sqrt((points[0].x - points[1].x) * (points[0].x - points[1].x) + (points[0].y - points[1].y) * (points[0].y - points[1].y));

	return 4 * a;
}

//Rectangle
Rectangle::Rectangle() : Square(Point(0.0, 0.0), Point(2.0, 0.0), Point(2.0, 1.0), Point(0.0, 1.0)) {}

Rectangle::Rectangle(Point point_1, Point point_2, Point point_3, Point point_4) : Square(point_1, point_2, point_3, point_4) {}

double Rectangle::area() const {
	double a = std::sqrt((points[0].x - points[1].x) * (points[0].x - points[1].x) + (points[0].y - points[1].y) * (points[0].y - points[1].y));
	double b = std::sqrt((points[1].x - points[2].x) * (points[1].x - points[2].x) + (points[1].y - points[2].y) * (points[1].y - points[2].y));

	return a * b;
}

double Rectangle::perimeter() const {
	double a = std::sqrt((points[0].x - points[1].x) * (points[0].x - points[1].x) + (points[0].y - points[1].y) * (points[0].y - points[1].y));
	double b = std::sqrt((points[1].x - points[2].x) * (points[1].x - points[2].x) + (points[1].y - points[2].y) * (points[1].y - points[2].y));

	return 2 * (a + b);
}

//Triangle
Triangle::Triangle() {
	points.push_back(Point(0.0, 0.0));
	points.push_back(Point(2.0, 0.0));
	points.push_back(Point(1.0, 1.0));
}

Triangle::Triangle(Point point_1, Point point_2, Point point_3) {
	points.push_back(point_1);
	points.push_back(point_2);
	points.push_back(point_3);
}

double Triangle::area() const {
	double a = std::sqrt((points[0].x - points[1].x) * (points[0].x - points[1].x) + (points[0].y - points[1].y) * (points[0].y - points[1].y));
	double b = std::sqrt((points[1].x - points[2].x) * (points[1].x - points[2].x) + (points[1].y - points[2].y) * (points[1].y - points[2].y));
	double c = std::sqrt((points[0].x - points[2].x) * (points[0].x - points[2].x) + (points[0].y - points[2].y) * (points[0].y - points[2].y));
	double p = (a + b + c) / 2;

	return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::perimeter() const {
	double a = std::sqrt((points[0].x - points[1].x) * (points[0].x - points[1].x) + (points[0].y - points[1].y) * (points[0].y - points[1].y));
	double b = std::sqrt((points[1].x - points[2].x) * (points[1].x - points[2].x) + (points[1].y - points[2].y) * (points[1].y - points[2].y));
	double c = std::sqrt((points[0].x - points[2].x) * (points[0].x - points[2].x) + (points[0].y - points[2].y) * (points[0].y - points[2].y));
	
	return a + b + c;
}

//Polygon
Polygon::Polygon() : Triangle() {}

Polygon::Polygon(Point point_1, Point point_2, Point point_3) : Triangle(point_3, point_2, point_1) {}

double Polygon::area() const {
	double result = 0;

	for (size_t i = 0; i < points.size() - 1; ++i) {
		result += points[i].x * points[i + 1].y;
	}

	result += points[points.size() - 1].x * points[0].y;

	for (size_t i = 0; i < points.size() - 1; ++i) {
		result -= points[i + 1].x * points[i].y;
	}

	result -= points[0].x * points[points.size() - 1].y;

	result = std::abs(result);
	result /= 2;

	return result;
}

double Polygon::perimeter() const {
	double a, b, result = 0;

	for (size_t i = 0; i < points.size() - 1; ++i) {
		result += std::sqrt((points[i].x - points[i + 1].x) * (points[i].x - points[i + 1].x) + (points[i].y - points[i + 1].y) * (points[i].y - points[i + 1].y));
	}

	result += std::sqrt((points[0].x - points[points.size() - 1].x) * (points[0].x - points[points.size() - 1].x) + (points[0].y - points[points.size() - 1].y) * (points[0].y - points[points.size() - 1].y));

	return result;
}

Polygon::Polygon(Point point) {
	points.push_back(point);
}

Polygon::Polygon(Point point_1, Point point_2) {
	points.push_back(point_2);
	points.push_back(point_1);
}

//Circle
Circle::Circle() {
	radius = 1.0;
	points.push_back(Point(0.0, 0.0));
}

Circle::Circle(Point point, double radius) : radius(radius) {
	points.push_back(point);
}

double Circle::area() const {
	return PI * radius * radius;
}

double Circle::perimeter() const {
	return 2 * PI * radius;
}

std::ostream& operator<<(std::ostream& out, const Circle& circle) {
	out << "Point of center = " << circle.points[0] << ", radius = " << circle.radius;
	return out;
}

//Ellipse
Ellipse::Ellipse() : second_radius(2.0) {}

Ellipse::Ellipse(Point point, double radius, double second_radius) : Circle(point, radius), second_radius(second_radius) {}

double Ellipse::area() const {
	return PI * radius * second_radius;
}

double Ellipse::perimeter() const {
	return PI * (radius + second_radius);
}

std::ostream& operator<<(std::ostream& out, const Ellipse& ellipse) {
	out << "Point of center = " << ellipse.points[0] << ", large axle = " << ellipse.radius << ", small axle = " << ellipse.second_radius;
	return out;
}