#ifndef Shapes_h
#define Shapes_h

#include <iostream>
#include <vector>
#include <cmath>
#include "../inc/Point.h"

const double PI = 3.141593;

class Shape {
public:
	virtual ~Shape() = default;
	virtual double area() const = 0;
	virtual double perimeter() const = 0;

	friend std::ostream& operator<<(std::ostream& out, const Shape& shape);
protected:
	std::vector<Point> points;
};

class Square : public Shape {
public:
	Square();
	Square(Point point_1, Point point_2, Point point_3, Point point_4);

	double area() const override;
	double perimeter() const override;
};

class Rectangle : public Square {
public:
	Rectangle();
	Rectangle(Point point_1, Point point_2, Point point_3, Point point_4);

	double area() const override;
	double perimeter() const override;
};

class Triangle : public Shape {
public:
	Triangle();
	Triangle(Point point_1, Point point_2, Point point_3);

	double area() const override;
	double perimeter() const override;
};

class Polygon : public Triangle {
public:
	Polygon();
	Polygon(Point point_1, Point point_2, Point point_3);

	double area() const override;
	double perimeter() const override;

	template<typename Fisrt, typename... Tail>
	Polygon(Fisrt point, Tail... tail) : Polygon(tail...) {
		points.push_back(point);
	}
private:
	Polygon(Point point);
	Polygon(Point point_1, Point point_2);
};

class Circle : public Shape {
public:
	Circle();
	Circle(Point point, double radius = 1.0);

	double area() const override;
	double perimeter() const override;

	friend std::ostream& operator<<(std::ostream& out, const Circle& Circle);
protected:
	double radius;
};

class Ellipse : public Circle {
public:
	Ellipse();
	Ellipse(Point point, double radius = 1.0, double second_radius = 2.0);

	double area() const override;
	double perimeter() const override;

	friend std::ostream& operator<<(std::ostream& out, const Ellipse& ellipse);
protected:
	double second_radius;
};

#endif