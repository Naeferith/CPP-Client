#include "stdafx.h"
#include "Shape.h"

Shape::Shape() : Drawable() {
	vertices = {};
}

Shape::Shape(vector<Vector2D, allocator<Vector2D>>& v, const Vector3D* c) : Drawable(c) {
	vertices = v;
}

Shape::~Shape() {
}

const vector<Vector2D> Shape::getVertices() const { return vertices; }

void Shape::setVertices(const vector<Vector2D>& v) { vertices = v; }

void Shape::Translate(const Vector2D V) {
	for (auto &vertice : vertices) {
		vertice.setX(vertice.getX() + V.getX());
		vertice.setY(vertice.getY() + V.getY());
	}
}

void Shape::Scale(const Vector2D point, const double ratio) {
	for (auto &vertice : vertices) {
		vertice.setX((vertice.getX() - point.getX()) * ratio);
		vertice.setY((vertice.getY() - point.getY()) * ratio);
	}
}

void Shape::Rotate(const Vector2D point, const double rad) {
	for (auto &vertice : vertices) {
		vertice.setX((vertice.getX() - point.getX()) * cos(rad) - (vertice.getY() - point.getY()) * sin(rad));
		vertice.setY((vertice.getX() - point.getX()) * sin(rad) + (vertice.getY() - point.getY()) * cos(rad));
	}
}
