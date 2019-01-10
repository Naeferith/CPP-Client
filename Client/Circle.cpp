#include "stdafx.h"
#include "Circle.h"

Circle::Circle() :Shape(), radius(0) { vertices.push_back(Vector2D()); }

Circle::Circle(const Vector2D& v) : Circle() { vertices.push_back(v); }

Circle::Circle(const Vector2D& v, const unsigned int r, const std::shared_ptr<const Color>& c) : Shape(v,c), radius(r) {}

Circle::Circle(const Circle& c) : Shape(c), radius(c.getRadius()){}

Circle::~Circle() {}

const int Circle::getRadius() const { return radius; }

void Circle::setRadius(const int i) { radius = i; }

void Circle::setCenter(const Vector2D& v) {
	vertices[0] = v;
}

void Circle::setVertices(const vector<Vector2D>& sommets) {
	if (sommets.size() != 1) throw Erreur(-1, "Circle only need 1 Center.");
	Shape::setVertices(sommets);
}

string* Circle::accept(Visitor * v) { return v->visit(this); }

string Circle::getName() const { return string("circle"); }

Circle::operator string() const {
	ostringstream oss;
	oss << Shape::operator std::string() << " radius :" << getRadius();
	return oss.str();
}

