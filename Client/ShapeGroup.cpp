#include "stdafx.h"
#include "ShapeGroup.h"
#include <algorithm>

using namespace std;

ShapeGroup::ShapeGroup() : Drawable(), shapes() {
}

ShapeGroup::ShapeGroup(const vector<shared_ptr<Drawable>>& v, shared_ptr<const Color>& c) :
	Drawable(c), shapes(v) {}

ShapeGroup::~ShapeGroup() {}

const vector<shared_ptr<Drawable>> ShapeGroup::getShapes() const { return shapes; }

void ShapeGroup::setColor(const shared_ptr<const Color>& couleur) {
	for (auto &shape : shapes) { shape->setColor(couleur); }
}

void ShapeGroup::setShapes(const vector<shared_ptr<Drawable>>& v) { shapes = v; }

void ShapeGroup::Translate(const Vector2D& vecteur) {
	for (auto &shape : shapes) { shape->Translate(vecteur); }
}

void ShapeGroup::Scale(const Vector2D & point, const double ratio) {
	for (auto &shape : shapes) { shape->Scale(point, ratio); }
}

void ShapeGroup::Rotate(const Vector2D & point, const double angle) {
	for (auto &shape : shapes) { shape->Rotate(point, angle); }
}

ShapeGroup ShapeGroup::operator+(Drawable& d) {
	//Si d est deja présent dans shapes, ne fait rien, sinon l'ajoute
	shared_ptr<Drawable> ptr(&d);
	//if (!(std::find(shapes.begin(), shapes.end(), d) != shapes.end())) shapes.push_back(ptr); //manque de surchage operateur probablement
	return *this;
}

ShapeGroup ShapeGroup::operator-(Drawable& d) {
	//shapes.erase(std::remove(shapes.begin(), shapes.end(), d), shapes.end()); //manque de surchage operateur probablement
	return *this;
}

bool ShapeGroup::operator==(const ShapeGroup& s) const {
	return Drawable::operator==(s) && (shapes == s.shapes);
}

const ShapeGroup& ShapeGroup::operator=(const ShapeGroup& s) {
	if (this == &s) return *this;
	return *this;
}