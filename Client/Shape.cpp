#include "stdafx.h"
#include "Shape.h"
#include "SingletonWSA.h"
#include <math.h>

using namespace std;

Shape::Shape() : Drawable() {}

Shape::Shape(const vector<Vector2D>& v, const shared_ptr<const Color>& c) : Drawable(c), vertices(v) {}

Shape::Shape(const Shape & s) : Drawable(s.color), vertices(s.vertices) {}

Shape::~Shape() {}

const vector<Vector2D> Shape::getVertices() const { return vertices; }

void Shape::setVertices(const vector<Vector2D>& v) { vertices = v; }

Shape& Shape::Translate(const Vector2D& V) {
	for (auto &vertice : vertices) vertice += V ;
	return *this;
}

double Shape::Area() const {
	//L'air d'un point ou d'un segment est nulle
	if (vertices.size() < 3) return 0;

	double area = 0;
	size_t size = vertices.size() - 1;
	Vector2D a = vertices.at(0), b, c, ab, ac;

	for (int k = 1; k < size; ++k) {
		b = vertices.at(k);
		c = vertices.at(k+1);
		ab = b - a;
		ac = c - a;
		area += 0.5*Vector2D::Det(ab, ac);
	}
	return area;
}

Shape& Shape::Scale(const Vector2D& point, const double ratio) {
	for (auto &vertice : vertices) 
		vertice = (vertice - point) * ratio + point;
	return *this;
}

Shape& Shape::Rotate(const Vector2D& point, const double rad) {
	for (auto &vertice : vertices) vertice = Vector2D::Rotate(point, vertice, rad);
	return *this;
}

string Shape::getName() const {	return string("shape"); }

string  Shape::accept(Visitor * v) { return v->visit(this); }

Shape Shape::operator+(const Vector2D & vecteur) {
	vertices.emplace_back(vecteur.x, vecteur.y);
	return *this;
}

Shape Shape::operator--() {
	vertices.pop_back();
	return *this;
}

Shape::operator string() const {
	ostringstream oss;
	oss << Drawable::operator std::string() << " [>> ";
	for (auto &vertice : getVertices()) oss << vertice << " ";
	oss << "<<]";
	return oss.str();
}