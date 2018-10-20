#include "stdafx.h"
#include "Shape.h"

Shape::Shape() : Drawable() {
	vertices = {};
}

Shape::Shape(const vector<Vector2D, allocator<Vector2D>>& v, const std::shared_ptr<const Color>& c) : Drawable(c) {
	vertices = v;
}

Shape::~Shape() {
}

const vector<Vector2D> Shape::getVertices() const { return vertices; }

void Shape::setColor(const std::shared_ptr<const Color>& c) { color = c; }

void Shape::setVertices(const vector<Vector2D>& v) { vertices = v; }

bool Shape::operator==(const Shape& s) const {
	return Drawable::operator==(s) && (vertices == s.vertices);
}

void Shape::Translate(const Vector2D& V) {
	for (auto &vertice : vertices) {
		vertice.setX(std::round( vertice.x + V.x ));
		vertice.setY(std::round( vertice.y + V.y ));
	}
}

void Shape::Scale(const Vector2D& point, const double ratio) {
	for (auto &vertice : vertices) {
		vertice.setX(std::round( (vertice.x - point.x) * ratio ));
		vertice.setY(std::round( (vertice.y - point.y) * ratio ));
	}
}

void Shape::Rotate(const Vector2D& point, const double rad) {
	for (auto &vertice : vertices) {
		double newX = std::round((vertice.x - point.x) * cos(rad) - (vertice.y - point.y) * sin(rad));
		double newY = std::round((vertice.x - point.x) * sin(rad) + (vertice.y - point.y) * cos(rad));
		vertice.setX(newX);
		vertice.setY(newY);
	}
}

string Shape::Draw() {
	std::stringstream result;
	result <<
		"<shape id=\"" << this << "\">" <<
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
			"<vertices>"
	;

	for (auto &vertice : vertices) {
		result <<
			"<vertice>" <<
				"<x>" <<
					vertice.x <<
				"</x>" <<
				"<y>" <<
					vertice.y <<
				"</y>" <<
			"</vertice>"
		;
	}

	result << "</vertices></shape>";
	return result.str();
}

void Shape::accept(Visitor * v) { v->visit(this); }

Shape Shape::operator+(const Vector2D & vecteur) {
	vertices.emplace_back(vecteur.x, vecteur.y);
	return *this;
}

Shape Shape::operator--() {
	vertices.pop_back();
	return *this;
}
