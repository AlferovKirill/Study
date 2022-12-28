#include "../inc/Point.h"

Point::Point(double x, double y) : x(x), y(y) {}

std::ostream& operator<<(std::ostream& out, const Point& point) {
	out << "(" << point.x << ", " << point.y << ")";

	return out;
}