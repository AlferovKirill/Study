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
	virtual double Area() const = 0;
	virtual double Perimeter() const = 0;

	virtual bool operator==(const Shape& shape) const = 0;
	virtual bool Congruence(const Shape& shape) const = 0;
	virtual bool Similarity(const Shape& shape) const = 0;

	friend std::ostream& operator<<(std::ostream& out, const Shape& shape);
	friend bool operator==(const Shape& shape_1, const Shape& shape_2);
	friend bool Congruence(const Shape& shape_1, const Shape& shape_2);
	friend bool Similarity(const Shape& shape_1, const Shape& shape_2);
protected:
	std::vector<Point> points;
};

class Square : public Shape {
public:
	Square();
	Square(Point point_1, Point point_2, Point point_3, Point point_4);

	double Area() const override;
	double Perimeter() const override;

	bool operator==(const Shape& shape) const override;
	bool Congruence(const Shape& shape) const override;
	bool Similarity(const Shape& shape) const override;
};

class Rectangle : public Square {
public:
	Rectangle();
	Rectangle(Point point_1, Point point_2, Point point_3, Point point_4);

	double Area() const override;
	double Perimeter() const override;

	bool operator==(const Shape& shape) const override;
	bool Congruence(const Shape& shape) const override;
	bool Similarity(const Shape& shape) const override;
};

class Triangle : public Shape {
public:
	Triangle();
	Triangle(Point point_1, Point point_2, Point point_3);

	double Area() const override;
	double Perimeter() const override;

	bool operator==(const Shape& shape) const override;
	bool Congruence(const Shape& shape) const override;
	bool Similarity(const Shape& shape) const override;
};

class Polygon : public Triangle {
public:
	Polygon();
	Polygon(Point point_1, Point point_2, Point point_3);

	template<typename Fisrt, typename... Tail>
	Polygon(Fisrt point, Tail... tail) : Polygon(tail...) {
		points.push_back(point);
	}

	double Area() const override;
	double Perimeter() const override;

	bool operator==(const Shape& shape) const override;
	bool Congruence(const Shape& shape) const override;
	bool Similarity(const Shape& shape) const override;
private:
	Polygon(Point point);
	Polygon(Point point_1, Point point_2);
};

class Circle : public Shape {
public:
	Circle();
	Circle(Point point, double radius = 1.0);

	double Area() const override;
	double Perimeter() const override;

	bool operator==(const Shape& shape) const override;
	bool Congruence(const Shape& shape) const override;
	bool Similarity(const Shape& shape) const override;

	friend std::ostream& operator<<(std::ostream& out, const Circle& Circle);
protected:
	double radius;
};

class Ellipse : public Circle {
public:
	Ellipse();
	Ellipse(Point point, double radius = 1.0, double second_radius = 2.0);

	double Area() const override;
	double Perimeter() const override;

	bool operator==(const Shape& shape) const override;
	bool Congruence(const Shape& shape) const override;
	bool Similarity(const Shape& shape) const override;

	friend std::ostream& operator<<(std::ostream& out, const Ellipse& ellipse);
protected:
	double second_radius;
};

#endif