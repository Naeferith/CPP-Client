#include "stdafx.h"
#include "Shape.h"

using namespace std;

Shape::Shape() : Drawable() { vertices.reserve(1); }

Shape::Shape(const vector<Vector2D>& v, const shared_ptr<const Color>& c) :
	Drawable(c) { setVertices(v); }

Shape::Shape(const Shape& s): Drawable(s), vertices(vector<Vector2D>(s.vertices)) {}

Shape::~Shape() {}

const vector<Vector2D> Shape::getVertices() const { return vertices; }

void Shape::setColor(const shared_ptr<const Color>& c) { color = c; }

void Shape::setVertices(const vector<Vector2D>& v) { vertices = v; }

bool Shape::operator==(const Shape& s) const {
	return Drawable::operator==(s) && (vertices == s.vertices);
}

void Shape::Translate(const Vector2D& V) {
	for (auto &vertice : vertices) {
		vertice.setX(round( vertice.x + V.x ));
		vertice.setY(round( vertice.y + V.y ));
	}
}

void Shape::Scale(const Vector2D& point, const double ratio) {
	for (auto &vertice : vertices) {
		vertice.setX(round( (vertice.x - point.x) * ratio ));
		vertice.setY(round( (vertice.y - point.y) * ratio ));
	}
}

void Shape::Rotate(const Vector2D& point, const double rad) {
	vertices = RotateVector(vertices, point, rad);
}

vector<Vector2D> Shape::RotateVector(vector<Vector2D>& v, const Vector2D& point, const double rad) const{
	vector<Vector2D> aux(v);
	for (auto &vertice : aux) {
		double newX = round((vertice.x - point.x) * cos(rad) - (vertice.y - point.y) * sin(rad)) + point.x;
		double newY = round((vertice.x - point.x) * sin(rad) + (vertice.y - point.y) * cos(rad)) + point.y;
		vertice.setX(newX);
		vertice.setY(newY);
	}
	return aux;
}

string Shape::getName() const {
	return string("shape");
}

const int Shape::getSize()const {
	return vertices.size();
}

string* Shape::accept(Visitor * v) { return v->visit(this); }

Shape Shape::operator+(const Vector2D & vecteur) {
	vertices.push_back(vecteur);
	return *this;
}

Shape Shape::operator--() {
	vertices.pop_back();
	return *this;
}

Shape::operator string() const {
	ostringstream oss;
	oss << getName() << ": " << getColor() << " [>> ";
	for (auto &vertice : getVertices()) oss << vertice << " ";
	oss << "<<]";
	return oss.str();
}