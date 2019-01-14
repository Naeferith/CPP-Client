#include "stdafx.h"
#include "Circle.h"

Circle::Circle() : Shape(), radius(0) { vertices.emplace_back(0, 0); }

Circle::Circle(const Vector2D& v, const unsigned int r, const std::shared_ptr<const Color>& c) : Shape(), radius(r) {
	vertices.push_back(v);
	color = c;
}

Circle::Circle(const Circle& c) : Shape(c), radius(c.radius) {}

Circle::~Circle() {
}

const int Circle::getRadius() const { return radius; }

void Circle::setRadius(const int i) { radius = i; }

string Circle::getName() const { return string("circle"); }

void Circle::Scale(const Vector2D & point, const double ratio) {
	Shape::Scale(point, ratio);
	radius *= ratio;
}

string * Circle::accept(Visitor * v) { return v->visit(this); }

Circle::operator string() const {
	ostringstream oss;
	oss << Shape::operator std::string() << " radius :" << getRadius();
	return oss.str();
}