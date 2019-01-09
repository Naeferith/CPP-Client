#include "stdafx.h"
#include "Circle.h"

Circle::Circle() : Shape(), radius(0) {}

Circle::Circle(const Vector2D& v) : Shape(v) {}

Circle::Circle(const Vector2D& v, const unsigned int r, const std::shared_ptr<const Color>& c) : Shape(v), radius(r){
	color = c;
}

Circle::Circle(const Circle& c) {
	vertices = c.getVertices();
	color = c.color;
	radius = c.getRadius();
}

Circle::~Circle() {
}

const int Circle::getRadius() const { return radius; }

void Circle::setRadius(const int i) { radius = i; }

string* Circle::accept(Visitor * v) { return v->visit(this); }

string Circle::getName() const { return string("circle"); }

Circle::operator string() const {
	ostringstream oss;
	oss << Shape::operator std::string() << " radius :" << getRadius();
	return oss.str();
}