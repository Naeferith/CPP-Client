#include "stdafx.h"
#include "Circle.h"

Circle::Circle() : Shape(), radius(1) { vertices.emplace_back(0, 0); }

Circle::Circle(const Vector2D& center, const double radius, const shared_ptr<const Color>& c) : Shape() {
	setRadius(radius);
	vertices.push_back(center);
	color = c;
}

Circle::Circle(const Circle& c) : Shape(c), radius(c.radius) {}

Circle::~Circle() {
}

double Circle::Area() const {
	return MY_PI * radius * radius;
}

const double Circle::getRadius() const { return radius; }

void Circle::setRadius(const double i) { if (radius < 0) throw Erreur(-11, "Radian negatif"); radius = i; }

string Circle::getName() const { return string("circle"); }

Circle& Circle::Scale(const Vector2D & point, const double ratio) {
	Shape::Scale(point, ratio);
	radius *= ratio;
	return *this;
}

string  Circle::accept(Visitor * v) { return v->visit(this); }

Circle::operator string() const {
	ostringstream oss;
	oss << Shape::operator std::string() << " radius :" << getRadius();
	return oss.str();
}