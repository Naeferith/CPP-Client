#include "stdafx.h"
#include "Rectangles.h"
#include "Visitor.h"

Rectangles::Rectangles() : Shape(), rotation(0) { 
	vertices.emplace_back(0, 0);
	vertices.emplace_back(100, 100);
	rotationCenter = getCenter();
}

Rectangles::Rectangles(const vector<Vector2D>& v, const shared_ptr<const Color>& c) : Shape(v, c), rotation(0) {
	if (getSize() != 2) throw Erreur(-1, "Rectangles need 2 vectices.");
	rotationCenter = getCenter();
}

Rectangles::Rectangles(const Rectangles& obj) :Shape(obj),
	rotation(obj.getRotation()), rotationCenter(obj.getRotationCenter()) {}

Rectangles::~Rectangles() {}

const Vector2D& Rectangles::getUpLeft() const { return vertices.at(0); }

const Vector2D& Rectangles::getDownRight() const { return vertices.at(1); }

const double Rectangles::getRotation() const { return rotation; }

const Vector2D& Rectangles::getRotationCenter() const { return rotationCenter; }

Vector2D Rectangles::getCenter() const { return (getUpLeft() + getDownRight()) / 2; }

string* Rectangles::accept(Visitor* v) { return v->visit(this); }

string Rectangles::getName() const { return "rectangle"; }

void Rectangles::setUpLeft(const Vector2D& v) { vertices.at(0) = v; }

void Rectangles::setDownRight(const Vector2D& v) { vertices.at(1) = v; }

void Rectangles::setRotation(const double rot) { rotation = (int)rot % 360; }

void Rectangles::setRotationCenter(const Vector2D& v) { rotationCenter = v; }

const vector<Vector2D> Rectangles::getVertices() const {
	vector<Vector2D> vertice{
			Vector2D(getUpLeft()),
			Vector2D(getUpLeft().x,getDownRight().y),
			Vector2D(getDownRight()),
			Vector2D(getDownRight().x,getUpLeft().y)
	};
	if (getRotation() != 0) vertice = RotateVector(vertice, getRotationCenter(), getRotation());
	return vertice;
}

void Rectangles::setVertices(const vector<Vector2D>& sommets) { 
	if (sommets.size() != 2) throw Erreur(-1, "Rectangles need 2 vectices.");
	Shape::setVertices(sommets);
}

void Rectangles::Rotate(const Vector2D& point, const double angle) {
	setRotationCenter(point);
	setRotation(angle);
}