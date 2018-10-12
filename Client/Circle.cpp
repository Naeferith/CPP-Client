#include "stdafx.h"
#include "Circle.h"

Circle::Circle() : Shape() {
	radius = 0;
}

Circle::Circle(const Vector2D& v, const unsigned int r, const Color* c) : Shape() {
	vertices.push_back(v);
	color = c;
	radius = r;
}

Circle::Circle(const Circle& c) {
	vertices = c.getVertices();
	color = &c.getColor();
	radius = c.getRadius();
}

Circle::~Circle() {
}

const int Circle::getRadius() const { return radius; }

void Circle::setRadius(const int i) { radius = i; }

string Circle::Draw() {
	std::stringstream result;
	result <<
		"<circle>" <<
			"<center>" <<
				"<x>" <<
					this->vertices.front().getX() <<
				"</x>" <<
				"<y>" <<
					this->vertices.front().getY() <<
				"</y>" <<
			"</center>" <<
			"<radius>" <<
				this->radius <<
			"</radius>" <<
			"<color>" <<
				"<r>" <<
					this->color->getX() <<
				"</r>" <<
				"<g>" <<
					this->color->getY() <<
				"</g>" <<
				"<b>" <<
					this->color->getZ() <<
				"</b>" <<
			"</color>" <<
		"</circle>"
	;
	return result.str();
}

void Circle::accept(Visitor * v) { v->visit(this); }
