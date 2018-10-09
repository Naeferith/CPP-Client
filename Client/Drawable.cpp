#include "stdafx.h"
#include "Drawable.h"

using namespace std;

Drawable::Drawable()
{
}

Drawable::Drawable(vector<Vector2D> V, Vector3D C)
{
	vertices = V;
	color = C;
}

Drawable::Drawable(const Drawable &)
{
}

const Vector3D Drawable::getColor() const { return color; }

void Drawable::Translate(const Vector2D V) {
	for (auto &vertice : vertices) {
		vertice.setX(vertice.getX() + V.getX());
		vertice.setY(vertice.getY() + V.getY());
	}
}

void Drawable::Scale(const Vector2D point, const double ratio) {
	for (auto &vertice : vertices) {
		vertice.setX(( vertice.getX() - point.getX() ) * ratio);
		vertice.setY(( vertice.getY() - point.getY() ) * ratio);
	}
}

void Drawable::Rotate(const Vector2D point, const double rad) {
	for (auto &vertice : vertices) {
		vertice.setX(( vertice.getX() - point.getX()) * cos(rad) - ( vertice.getY() - point.getY()) * sin(rad));
		vertice.setY(( vertice.getX() - point.getX()) * sin(rad) + ( vertice.getY() - point.getY()) * cos(rad));
	}
}