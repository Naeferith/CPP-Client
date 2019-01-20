#include "stdafx.h"
#include "Circle.h"

Circle::Circle() : Shape(), radius(0) { vertices.emplace_back(0, 0); }

Circle::Circle(const Vector2D& v, const double r, const std::shared_ptr<const Color>& c) : Shape(), radius(r) {
	vertices.push_back(v);
	color = c;
}

Circle::Circle(const Circle& c) : Shape(c), radius(c.radius) {}

Circle::~Circle() {
}

double Circle::Area() const {
	return MY_PI * radius * radius;
}

const double Circle::getRadius() const { return radius; }

void Circle::setRadius(const double i) { radius = i; }

string Circle::getName() const { return string("circle"); }

void Circle::Scale(const Vector2D & point, const double ratio) {
	Shape::Scale(point, ratio);
	radius *= ratio;
}

string  Circle::accept(Visitor * v) { return v->visit(shared_ptr<Circle>(this)); }

Circle::operator string() const {
	ostringstream oss;
	oss << Shape::operator std::string() << " radius :" << getRadius();
	return oss.str();
}