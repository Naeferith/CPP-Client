#include "stdafx.h"
#include "Shape.h"

Shape::Shape()
{
}

Shape::Shape(vector<Vector2D> v, Color* c) : Drawable(c) {
}

Shape::~Shape() {
}

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
