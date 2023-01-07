#include "../inc/Point.h"

Point::Point(double x, double y) : x(x), y(y) {}

bool operator==(const Point& point_1, const Point& point_2) {
	return ((point_1.x == point_2.x) && (point_1.y == point_2.y));
}

bool operator!=(const Point& point_1, const Point& point_2) {
	return !(point_1 == point_2);
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
	out << "(" << point.x << ", " << point.y << ")";

	return out;
}