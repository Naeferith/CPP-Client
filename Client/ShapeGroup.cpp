#include "stdafx.h"
#include "ShapeGroup.h"
#include <algorithm>

ShapeGroup::ShapeGroup() : Drawable(), shapes() {
}

ShapeGroup::ShapeGroup(const vector<Drawable>& v, const Color* c) : Drawable(c) {
	shapes = v;
}

ShapeGroup::~ShapeGroup() {
}

const vector<Drawable> ShapeGroup::getShapes() const { return shapes; }

void ShapeGroup::setShapes(const vector<Drawable>& v) {	shapes = v; }

ShapeGroup ShapeGroup::operator+(Drawable& d) {
	//Si d est deja présent dans shapes, ne fait rien, sinon l'ajoute
	if (!(std::find(shapes.begin(), shapes.end(), d) != shapes.end())) shapes.push_back(d); //manque de surchage operateur probablement
	return *this;
}

ShapeGroup ShapeGroup::operator-(Drawable& d) {
	shapes.erase(std::remove(shapes.begin(), shapes.end(), d), shapes.end()); //manque de surchage operateur probablement
	return *this;
}

bool ShapeGroup::operator==(const ShapeGroup& s) const {
	return Drawable::operator==(s) && (shapes == s.shapes);
}

const ShapeGroup& ShapeGroup::operator=(const ShapeGroup& s) {
	if (this == &s) return *this;
	return *this;
}
