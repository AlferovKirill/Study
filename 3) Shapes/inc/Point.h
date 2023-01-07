#ifndef Point_h
#define Point_h

#include <iostream>
#include <cmath>

struct Point {
	double x, y;

	Point(double x, double y);
};

bool operator==(const Point& point_1, const Point& point_2);
bool operator!=(const Point& point_1, const Point& point_2);

std::ostream& operator<<(std::ostream& out, const Point& point);

#endif