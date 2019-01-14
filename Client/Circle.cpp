#include "stdafx.h"
#include "Circle.h"

<<<<<<< HEAD
Circle::Circle() : Shape(), radius(0) { vertices.emplace_back(0, 0);}
=======
Circle::Circle() : Shape(), radius(0) { vertices.emplace_back(0, 0); }
>>>>>>> bafa4096d91de08c21b782d05e28f0a16617a716

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

string * Circle::accept(Visitor * v) { return v->visit(this); }

Circle::operator string() const {
	ostringstream oss;
	oss << Shape::operator std::string() << " radius :" << getRadius();
	return oss.str();
<<<<<<< HEAD
}
=======
}
>>>>>>> bafa4096d91de08c21b782d05e28f0a16617a716
