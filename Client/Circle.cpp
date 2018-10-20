#include "stdafx.h"
#include "Circle.h"

Circle::Circle() : Shape() {
	radius = 0;
}

Circle::Circle(const Vector2D& v, const unsigned int r, const std::shared_ptr<const Color>& c) : Shape() {
	vertices.push_back(v);
	color = c;
	radius = r;
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

string Circle::Draw() {
	std::stringstream result;
	result <<
		"<circle id=\"" << this << "\">" <<
			"<center>" <<
				"<x>" <<
					this->vertices.front().x <<
				"</x>" <<
				"<y>" <<
					this->vertices.front().y <<
				"</y>" <<
			"</center>" <<
			"<radius>" <<
				this->radius <<
			"</radius>" <<
			"<color>" <<
				"<r>" <<
					this->color->x <<
				"</r>" <<
				"<g>" <<
					this->color->y <<
				"</g>" <<
				"<b>" <<
					this->color->z <<
				"</b>" <<
			"</color>" <<
		"</circle>"
	;
	return result.str();
}

void Circle::accept(Visitor * v) { v->visit(this); }