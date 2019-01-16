#include "stdafx.h"
#include "ShapeGroup.h"
#include <algorithm>

using namespace std;

ShapeGroup::ShapeGroup() : Drawable() {}

ShapeGroup::ShapeGroup(shared_ptr<const Color>& c) :
	Drawable(c) {}

ShapeGroup::~ShapeGroup() {}

const vector<shared_ptr<Drawable>> ShapeGroup::getShapes() const { return shapes; }

void ShapeGroup::setColor(const shared_ptr<const Color>& couleur) {
	for (auto &shape : shapes) { shape->setColor(couleur); }
}

void ShapeGroup::Translate(const Vector2D& vecteur) {
	for (auto &shape : shapes) { shape->Translate(vecteur); }
}

void ShapeGroup::Scale(const Vector2D & point, const double ratio) {
	for (auto &shape : shapes) { shape->Scale(point, ratio); }
}

void ShapeGroup::Rotate(const Vector2D & point, const double angle) {
	for (auto &shape : shapes) { shape->Rotate(point, angle); }
}

string ShapeGroup::getName() const {
	return string("shapegroup");
}

string * ShapeGroup::accept(Visitor * v) { return v->visit(this); }

ShapeGroup& ShapeGroup::operator+(Drawable* d) {
	//Regarde dans chaque ShapeGroupe crées, y compris donc celui-ci, si le Drawable
	//Est déjà présent
	if (d->getGroup) throw Erreur(-6, "Drawable already in a group !");
	
	d->setGroup(this);
	shapes.push_back(d);

	return *this;
}

ShapeGroup& ShapeGroup::operator-(Drawable& d) {
	for (vector<Drawable*>::const_iterator it = shapes.begin(); it != shapes.end(); it++) {
		if (**it == d) {
			shapes.erase(it);
			d.setGroup(NULL);
			return *this;
		}
	}
	return *this;
}

bool ShapeGroup::operator==(const Drawable& s) const {
	if (getId() == s.getId()) return true;
	
	//On test si s est présent dans les shapes
	for (auto &shape : getShapes()) { 
		if (*shape == s) return true;
	}
	return false;
}

ShapeGroup::operator string()const {
	ostringstream oss;
	oss << getName() << ": ";
	for (auto &shape : shapes)
		oss << shape;
	return oss.str();
}