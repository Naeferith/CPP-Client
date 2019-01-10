#include "stdafx.h"
#include "Circle.h"

Circle::Circle() :Shape(), radius(0) { setCenter(Vector2D()); }

Circle::Circle(const Vector2D& v) : Circle() { setCenter(v); }

Circle::Circle(const Vector2D& v, const unsigned int r, const std::shared_ptr<const Color>& c) : Shape(v,c), radius(r) {}

Circle::Circle(const Circle& c) : Shape(c), radius(c.getRadius()){}

Circle::~Circle() {}

const int Circle::getRadius() const { return radius; }

void Circle::setRadius(const int i) { radius = i; }

void Circle::setCenter(const Vector2D& v) {
	if (vertices.empty()) vertices.push_back(v);
	else vertices[0] = v;
}

string* Circle::accept(Visitor * v) { return v->visit(this); }

string Circle::getName() const { return string("circle"); }

Circle::operator string() const {
	ostringstream oss;
	oss << Shape::operator std::string() << " radius :" << getRadius();
	return oss.str();
}

