#include "../inc/Shapes.h"

//Shape
std::ostream& operator<<(std::ostream& out, const Shape& shape) {
	for (Point point : shape.points) {
		out << point << " ";
	}

	return out;
}

bool operator==(const Shape& shape_1, const Shape& shape_2) {
	return shape_1.operator==(shape_2);
}

bool Congruence(const Shape& shape_1, const Shape& shape_2) {
	return shape_1.Congruence(shape_2);
}

bool Similarity(const Shape& shape_1, const Shape& shape_2) {
	return shape_1.Similarity(shape_2);
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

double Square::Area() const {
	double a = std::sqrt((points[0].x - points[1].x) * (points[0].x - points[1].x) + (points[0].y - points[1].y) * (points[0].y - points[1].y));

	return a * a;
}

double Square::Perimeter() const {
	double a = std::sqrt((points[0].x - points[1].x) * (points[0].x - points[1].x) + (points[0].y - points[1].y) * (points[0].y - points[1].y));

	return 4 * a;
}

bool Square::operator==(const Shape& shape) const {
	Square temp = dynamic_cast<const Square&>(shape);

	if (points.size() != temp.points.size()) {
		return false;
	}
	else {
		for (size_t i = 0; i < points.size(); ++i) {
			if (points[i] != temp.points[i]) {
				return false;
			}
		}

		return true;
	}
}

bool Square::Congruence(const Shape& shape) const {
	Square temp = dynamic_cast<const Square&>(shape);

	if (points.size() != temp.points.size()) {
		return false;
	}

	double a = std::sqrt((points[0].x - points[points.size() - 1].x) * (points[0].x - points[points.size() - 1].x) + (points[0].y - points[points.size() - 1].y) * (points[0].y - points[points.size() - 1].y));
	double b = std::sqrt((temp.points[0].x - temp.points[temp.points.size() - 1].x) * (temp.points[0].x - temp.points[temp.points.size() - 1].x) + (temp.points[0].y - temp.points[temp.points.size() - 1].y) * (temp.points[0].y - temp.points[temp.points.size() - 1].y));

	if ((a / b) != 1) {
		return false;
	}

	for (size_t i = 0; i < points.size() - 1; ++i) {
		a = std::sqrt((points[0].x - points[points.size() - 1].x) * (points[0].x - points[points.size() - 1].x) + (points[0].y - points[points.size() - 1].y) * (points[0].y - points[points.size() - 1].y));
		b = std::sqrt((temp.points[0].x - temp.points[temp.points.size() - 1].x) * (temp.points[0].x - temp.points[temp.points.size() - 1].x) + (temp.points[0].y - temp.points[temp.points.size() - 1].y) * (temp.points[0].y - temp.points[temp.points.size() - 1].y));

		if ((a / b) != 1) {
			return false;
		}
	}

	return true;
}

bool Square::Similarity(const Shape& shape) const {
	Square temp = dynamic_cast<const Square&>(shape);

	if (points.size() != temp.points.size()) {
		return false;
	}

	double a = std::sqrt((points[0].x - points[points.size() - 1].x) * (points[0].x - points[points.size() - 1].x) + (points[0].y - points[points.size() - 1].y) * (points[0].y - points[points.size() - 1].y));
	double b = std::sqrt((temp.points[0].x - temp.points[temp.points.size() - 1].x) * (temp.points[0].x - temp.points[temp.points.size() - 1].x) + (temp.points[0].y - temp.points[temp.points.size() - 1].y) * (temp.points[0].y - temp.points[temp.points.size() - 1].y));

	int k = (a > b) ? (a / b) : (b / a);

	for (size_t i = 0; i < points.size() - 1; ++i) {
		a = std::sqrt((points[0].x - points[points.size() - 1].x) * (points[0].x - points[points.size() - 1].x) + (points[0].y - points[points.size() - 1].y) * (points[0].y - points[points.size() - 1].y));
		b = std::sqrt((temp.points[0].x - temp.points[temp.points.size() - 1].x) * (temp.points[0].x - temp.points[temp.points.size() - 1].x) + (temp.points[0].y - temp.points[temp.points.size() - 1].y) * (temp.points[0].y - temp.points[temp.points.size() - 1].y));

		if (((a > b) ? (a / b) : (b / a)) != k) {
			return false;
		}
	}

	return true;
}

//Rectangle
Rectangle::Rectangle() : Square(Point(0.0, 0.0), Point(2.0, 0.0), Point(2.0, 1.0), Point(0.0, 1.0)) {}

Rectangle::Rectangle(Point point_1, Point point_2, Point point_3, Point point_4) : Square(point_1, point_2, point_3, point_4) {}

double Rectangle::Area() const {
	double a = std::sqrt((points[0].x - points[1].x) * (points[0].x - points[1].x) + (points[0].y - points[1].y) * (points[0].y - points[1].y));
	double b = std::sqrt((points[1].x - points[2].x) * (points[1].x - points[2].x) + (points[1].y - points[2].y) * (points[1].y - points[2].y));

	return a * b;
}

double Rectangle::Perimeter() const {
	double a = std::sqrt((points[0].x - points[1].x) * (points[0].x - points[1].x) + (points[0].y - points[1].y) * (points[0].y - points[1].y));
	double b = std::sqrt((points[1].x - points[2].x) * (points[1].x - points[2].x) + (points[1].y - points[2].y) * (points[1].y - points[2].y));

	return 2 * (a + b);
}

bool Rectangle::operator==(const Shape& shape) const {
	Rectangle temp = dynamic_cast<const Rectangle&>(shape);

	if (points.size() != temp.points.size()) {
		return false;
	}
	else {
		for (size_t i = 0; i < points.size(); ++i) {
			if (points[i] != temp.points[i]) {
				return false;
			}
		}

		return true;
	}
}

bool Rectangle::Congruence(const Shape& shape) const {
	Rectangle temp = dynamic_cast<const Rectangle&>(shape);

	if (points.size() != temp.points.size()) {
		return false;
	}

	double a = std::sqrt((points[0].x - points[points.size() - 1].x) * (points[0].x - points[points.size() - 1].x) + (points[0].y - points[points.size() - 1].y) * (points[0].y - points[points.size() - 1].y));
	double b = std::sqrt((temp.points[0].x - temp.points[temp.points.size() - 1].x) * (temp.points[0].x - temp.points[temp.points.size() - 1].x) + (temp.points[0].y - temp.points[temp.points.size() - 1].y) * (temp.points[0].y - temp.points[temp.points.size() - 1].y));

	if ((a / b) != 1) {
		return false;
	}

	for (size_t i = 0; i < points.size() - 1; ++i) {
		a = std::sqrt((points[0].x - points[points.size() - 1].x) * (points[0].x - points[points.size() - 1].x) + (points[0].y - points[points.size() - 1].y) * (points[0].y - points[points.size() - 1].y));
		b = std::sqrt((temp.points[0].x - temp.points[temp.points.size() - 1].x) * (temp.points[0].x - temp.points[temp.points.size() - 1].x) + (temp.points[0].y - temp.points[temp.points.size() - 1].y) * (temp.points[0].y - temp.points[temp.points.size() - 1].y));

		if ((a / b) != 1) {
			return false;
		}
	}

	return true;
}

bool Rectangle::Similarity(const Shape& shape) const {
	Rectangle temp = dynamic_cast<const Rectangle&>(shape);

	if (points.size() != temp.points.size()) {
		return false;
	}

	double a = std::sqrt((points[0].x - points[points.size() - 1].x) * (points[0].x - points[points.size() - 1].x) + (points[0].y - points[points.size() - 1].y) * (points[0].y - points[points.size() - 1].y));
	double b = std::sqrt((temp.points[0].x - temp.points[temp.points.size() - 1].x) * (temp.points[0].x - temp.points[temp.points.size() - 1].x) + (temp.points[0].y - temp.points[temp.points.size() - 1].y) * (temp.points[0].y - temp.points[temp.points.size() - 1].y));

	int k = (a > b) ? (a / b) : (b / a);

	for (size_t i = 0; i < points.size() - 1; ++i) {
		a = std::sqrt((points[0].x - points[points.size() - 1].x) * (points[0].x - points[points.size() - 1].x) + (points[0].y - points[points.size() - 1].y) * (points[0].y - points[points.size() - 1].y));
		b = std::sqrt((temp.points[0].x - temp.points[temp.points.size() - 1].x) * (temp.points[0].x - temp.points[temp.points.size() - 1].x) + (temp.points[0].y - temp.points[temp.points.size() - 1].y) * (temp.points[0].y - temp.points[temp.points.size() - 1].y));

		if (((a > b) ? (a / b) : (b / a)) != k) {
			return false;
		}
	}

	return true;
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

double Triangle::Area() const {
	double a = std::sqrt((points[0].x - points[1].x) * (points[0].x - points[1].x) + (points[0].y - points[1].y) * (points[0].y - points[1].y));
	double b = std::sqrt((points[1].x - points[2].x) * (points[1].x - points[2].x) + (points[1].y - points[2].y) * (points[1].y - points[2].y));
	double c = std::sqrt((points[0].x - points[2].x) * (points[0].x - points[2].x) + (points[0].y - points[2].y) * (points[0].y - points[2].y));
	double p = (a + b + c) / 2;

	return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::Perimeter() const {
	double a = std::sqrt((points[0].x - points[1].x) * (points[0].x - points[1].x) + (points[0].y - points[1].y) * (points[0].y - points[1].y));
	double b = std::sqrt((points[1].x - points[2].x) * (points[1].x - points[2].x) + (points[1].y - points[2].y) * (points[1].y - points[2].y));
	double c = std::sqrt((points[0].x - points[2].x) * (points[0].x - points[2].x) + (points[0].y - points[2].y) * (points[0].y - points[2].y));

	return a + b + c;
}

bool Triangle::operator==(const Shape& shape) const {
	Triangle temp = dynamic_cast<const Triangle&>(shape);

	if (points.size() != temp.points.size()) {
		return false;
	}
	else {
		for (size_t i = 0; i < points.size(); ++i) {
			if (points[i] != temp.points[i]) {
				return false;
			}
		}

		return true;
	}
}

bool Triangle::Congruence(const Shape& shape) const {
	Triangle temp = dynamic_cast<const Triangle&>(shape);

	if (points.size() != temp.points.size()) {
		return false;
	}

	double a = std::sqrt((points[0].x - points[points.size() - 1].x) * (points[0].x - points[points.size() - 1].x) + (points[0].y - points[points.size() - 1].y) * (points[0].y - points[points.size() - 1].y));
	double b = std::sqrt((temp.points[0].x - temp.points[temp.points.size() - 1].x) * (temp.points[0].x - temp.points[temp.points.size() - 1].x) + (temp.points[0].y - temp.points[temp.points.size() - 1].y) * (temp.points[0].y - temp.points[temp.points.size() - 1].y));

	if ((a / b) != 1) {
		return false;
	}

	for (size_t i = 0; i < points.size() - 1; ++i) {
		a = std::sqrt((points[0].x - points[points.size() - 1].x) * (points[0].x - points[points.size() - 1].x) + (points[0].y - points[points.size() - 1].y) * (points[0].y - points[points.size() - 1].y));
		b = std::sqrt((temp.points[0].x - temp.points[temp.points.size() - 1].x) * (temp.points[0].x - temp.points[temp.points.size() - 1].x) + (temp.points[0].y - temp.points[temp.points.size() - 1].y) * (temp.points[0].y - temp.points[temp.points.size() - 1].y));

		if ((a / b) != 1) {
			return false;
		}
	}

	return true;
}

bool Triangle::Similarity(const Shape& shape) const {
	Triangle temp = dynamic_cast<const Triangle&>(shape);

	if (points.size() != temp.points.size()) {
		return false;
	}

	double a = std::sqrt((points[0].x - points[points.size() - 1].x) * (points[0].x - points[points.size() - 1].x) + (points[0].y - points[points.size() - 1].y) * (points[0].y - points[points.size() - 1].y));
	double b = std::sqrt((temp.points[0].x - temp.points[temp.points.size() - 1].x) * (temp.points[0].x - temp.points[temp.points.size() - 1].x) + (temp.points[0].y - temp.points[temp.points.size() - 1].y) * (temp.points[0].y - temp.points[temp.points.size() - 1].y));

	int k = (a > b) ? (a / b) : (b / a);

	for (size_t i = 0; i < points.size() - 1; ++i) {
		a = std::sqrt((points[0].x - points[points.size() - 1].x) * (points[0].x - points[points.size() - 1].x) + (points[0].y - points[points.size() - 1].y) * (points[0].y - points[points.size() - 1].y));
		b = std::sqrt((temp.points[0].x - temp.points[temp.points.size() - 1].x) * (temp.points[0].x - temp.points[temp.points.size() - 1].x) + (temp.points[0].y - temp.points[temp.points.size() - 1].y) * (temp.points[0].y - temp.points[temp.points.size() - 1].y));

		if (((a > b) ? (a / b) : (b / a)) != k) {
			return false;
		}
	}

	return true;
}

//Polygon
Polygon::Polygon() : Triangle() {}

Polygon::Polygon(Point point_1, Point point_2, Point point_3) : Triangle(point_3, point_2, point_1) {}

double Polygon::Area() const {
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

double Polygon::Perimeter() const {
	double result = 0;

	for (size_t i = 0; i < points.size() - 1; ++i) {
		result += std::sqrt((points[i].x - points[i + 1].x) * (points[i].x - points[i + 1].x) + (points[i].y - points[i + 1].y) * (points[i].y - points[i + 1].y));
	}

	result += std::sqrt((points[0].x - points[points.size() - 1].x) * (points[0].x - points[points.size() - 1].x) + (points[0].y - points[points.size() - 1].y) * (points[0].y - points[points.size() - 1].y));

	return result;
}

bool Polygon::operator==(const Shape& shape) const {
	Polygon temp = dynamic_cast<const Polygon&>(shape);

	if (points.size() != temp.points.size()) {
		return false;
	}
	else {
		for (size_t i = 0; i < points.size(); ++i) {
			if (points[i] != temp.points[i]) {
				return false;
			}
		}

		return true;
	}
}

bool Polygon::Congruence(const Shape& shape) const {
	Polygon temp = dynamic_cast<const Polygon&>(shape);

	if (points.size() != temp.points.size()) {
		return false;
	}

	double a = std::sqrt((points[0].x - points[points.size() - 1].x) * (points[0].x - points[points.size() - 1].x) + (points[0].y - points[points.size() - 1].y) * (points[0].y - points[points.size() - 1].y));
	double b = std::sqrt((temp.points[0].x - temp.points[temp.points.size() - 1].x) * (temp.points[0].x - temp.points[temp.points.size() - 1].x) + (temp.points[0].y - temp.points[temp.points.size() - 1].y) * (temp.points[0].y - temp.points[temp.points.size() - 1].y));

	if ((a / b) != 1) {
		return false;
	}

	for (size_t i = 0; i < points.size() - 1; ++i) {
		a = std::sqrt((points[0].x - points[points.size() - 1].x) * (points[0].x - points[points.size() - 1].x) + (points[0].y - points[points.size() - 1].y) * (points[0].y - points[points.size() - 1].y));
		b = std::sqrt((temp.points[0].x - temp.points[temp.points.size() - 1].x) * (temp.points[0].x - temp.points[temp.points.size() - 1].x) + (temp.points[0].y - temp.points[temp.points.size() - 1].y) * (temp.points[0].y - temp.points[temp.points.size() - 1].y));

		if ((a / b) != 1) {
			return false;
		}
	}

	return true;
}

bool Polygon::Similarity(const Shape& shape) const {
	Polygon temp = dynamic_cast<const Polygon&>(shape);

	if (points.size() != temp.points.size()) {
		return false;
	}

	double a = std::sqrt((points[0].x - points[points.size() - 1].x) * (points[0].x - points[points.size() - 1].x) + (points[0].y - points[points.size() - 1].y) * (points[0].y - points[points.size() - 1].y));
	double b = std::sqrt((temp.points[0].x - temp.points[temp.points.size() - 1].x) * (temp.points[0].x - temp.points[temp.points.size() - 1].x) + (temp.points[0].y - temp.points[temp.points.size() - 1].y) * (temp.points[0].y - temp.points[temp.points.size() - 1].y));

	int k = (a > b) ? (a / b) : (b / a);

	for (size_t i = 0; i < points.size() - 1; ++i) {
		a = std::sqrt((points[0].x - points[points.size() - 1].x) * (points[0].x - points[points.size() - 1].x) + (points[0].y - points[points.size() - 1].y) * (points[0].y - points[points.size() - 1].y));
		b = std::sqrt((temp.points[0].x - temp.points[temp.points.size() - 1].x) * (temp.points[0].x - temp.points[temp.points.size() - 1].x) + (temp.points[0].y - temp.points[temp.points.size() - 1].y) * (temp.points[0].y - temp.points[temp.points.size() - 1].y));

		if (((a > b) ? (a / b) : (b / a)) != k) {
			return false;
		}
	}

	return true;
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

double Circle::Area() const {
	return PI * radius * radius;
}

double Circle::Perimeter() const {
	return 2 * PI * radius;
}

bool Circle::operator==(const Shape& shape) const {
	Circle temp = dynamic_cast<const Circle&>(shape);

	if (points[0] != temp.points[0]) {
		return false;
	}
	else if (radius != temp.radius) {
		return false;
	}

	return true;
}

bool Circle::Congruence(const Shape& shape) const {
	Circle temp = dynamic_cast<const Circle&>(shape);

	if (radius != temp.radius) {
		return false;
	}

	return true;
}

bool Circle::Similarity(const Shape& shape) const {
	Circle temp = dynamic_cast<const Circle&>(shape);

	return true;
}

std::ostream& operator<<(std::ostream& out, const Circle& circle) {
	out << "Point of center = " << circle.points[0] << ", radius = " << circle.radius;
	return out;
}

//Ellipse
Ellipse::Ellipse() : second_radius(2.0) {}

Ellipse::Ellipse(Point point, double radius, double second_radius) : Circle(point, radius), second_radius(second_radius) {}

double Ellipse::Area() const {
	return PI * radius * second_radius;
}

double Ellipse::Perimeter() const {
	return PI * (radius + second_radius);
}

bool Ellipse::operator==(const Shape& shape) const {
	Ellipse temp = dynamic_cast<const Ellipse&>(shape);

	if (points[0] != temp.points[0]) {
		return false;
	}
	else if (radius != temp.radius) {
		return false;
	}
	else if (second_radius != temp.second_radius) {
		return false;
	}

	return true;
}

bool Ellipse::Congruence(const Shape& shape) const {
	Ellipse temp = dynamic_cast<const Ellipse&>(shape);

	if (radius != temp.radius) {
		return false;
	}
	else if (second_radius != temp.second_radius) {
		return false;
	}

	return true;
}

bool Ellipse::Similarity(const Shape& shape) const {
	Ellipse temp = dynamic_cast<const Ellipse&>(shape);

	std::cout << "3 Similarity" << std::endl;

	int k1 = (radius > second_radius) ? (radius / second_radius) : (second_radius / radius);
	int k2 = (temp.radius > temp.second_radius) ? (temp.radius / temp.second_radius) : (temp.second_radius / temp.radius);

	if (k1 == k2) {
		return true;
	}
	else {
		return false;
	}
}

std::ostream& operator<<(std::ostream& out, const Ellipse& ellipse) {
	out << "Point of center = " << ellipse.points[0] << ", large axle = " << ellipse.radius << ", small axle = " << ellipse.second_radius;
	return out;
}