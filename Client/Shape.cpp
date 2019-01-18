#include "stdafx.h"
#include "Shape.h"
#include "SingletonWSA.h"
#include <math.h>

using namespace std;

Shape::Shape() : Drawable() {
	vertices = {};
}

Shape::Shape(const vector<Vector2D>& v, const shared_ptr<const Color>& c) : Drawable(c), vertices(v) {}

Shape::Shape(const Shape & s) : Drawable(s.color), vertices(s.vertices) {}

Shape::~Shape() {}

const vector<Vector2D> Shape::getVertices() const { return vertices; }

const double Shape::getRotationAngle() const { return rotationAngle; }

void Shape::setColor(const shared_ptr<const Color>& c) { color = shared_ptr<const Color>(c); }

void Shape::setVertices(const vector<Vector2D>& v) { vertices = v; }

void Shape::Translate(const Vector2D& V) {
	for (auto &vertice : vertices) vertice = vertice + V ;
}

double Shape::Area() const {
	//L'air d'un point ou d'un segment est null
	if (vertices.size() < 3) return 0;

	double area = 0;
	size_t size = vertices.size() - 1;
	Vector2D a = vertices.at(0), b, c;

	for (int k = 1; k < size; ++k) {
		b = vertices.at(k);
		c = vertices.at(k+1);
		area += 0.5*Det(a, b, c);
	}
	return area;
}

void Shape::Scale(const Vector2D& point, const double ratio) {
	for (auto &vertice : vertices) {
		vertice.setX(round((vertice.x - point.x) * ratio) + point.x);
		vertice.setY(round((vertice.y - point.y) * ratio) + point.y);

		vertice = (vertice - point) * ratio + point;
	}
}

void Shape::Rotate(const Vector2D& point, const double rad) {
	for (auto &vertice : vertices) {
		double newX = round((vertice.x - point.x) * cos(rad) - (vertice.y - point.y) * sin(rad));
		double newY = round((vertice.x - point.x) * sin(rad) + (vertice.y - point.y) * cos(rad));
		vertice.setX(newX + point.x);
		vertice.setY(newY + point.y);
	}
	rotationAngle = fmod(rotationAngle + rad, 2 * MY_PI);
}

string Shape::getName() const {	return string("shape"); }

string  Shape::accept(Visitor * v) { return v->visit(shared_ptr<Shape>(this)); }

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
