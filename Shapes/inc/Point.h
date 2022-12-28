#ifndef Point_h
#define Point_h

#include <iostream>

struct Point {
	double x, y;

	Point(double x, double y);
};

std::ostream& operator<<(std::ostream& out, const Point& point);

#endif