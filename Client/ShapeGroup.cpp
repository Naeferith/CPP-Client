#include "stdafx.h"
#include "ShapeGroup.h"
#include <algorithm>

using namespace std;

ShapeGroup::ShapeGroup() : Drawable() {}

ShapeGroup::ShapeGroup(shared_ptr<const Color>& c) :
	Drawable(c) {}

ShapeGroup::~ShapeGroup() {
	for (auto &shape : shapes) {
		shape->setGroup(nullptr);
		shape.reset();
	}
}

const vector<shared_ptr<Drawable>>& ShapeGroup::getShapes() const { return shapes; }

double ShapeGroup::Area() const {
	double sum = 0;
	for (auto &shape : shapes) sum += shape->Area();
	return sum;
}

void ShapeGroup::setColor(const shared_ptr<const Color>& couleur) {
	this->Drawable::setColor(couleur);
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

string  ShapeGroup::accept(Visitor * v) { return v->visit(this); }

void ShapeGroup::add(shared_ptr<Drawable> d) {
	if (d->getGroup()) throw Erreur(-6, "Drawable already in a group !");

	d->setGroup(this);
	d->setColor(getColor());
	DrawableGroup::add(d);
}

void ShapeGroup::Delete(int i) {
	shapes.at(i)->setGroup(nullptr);
	DrawableGroup::Delete(i);
}

void ShapeGroup::Delete(shared_ptr<Drawable> d) {
	d->setGroup(nullptr);
	DrawableGroup::Delete(d);
}

bool ShapeGroup::operator==(const shared_ptr<Drawable> s) const {
	if (getId() == s->getId()) return true;
	return DrawableGroup::operator==(s);
}

ShapeGroup::operator string()const {
	ostringstream oss;
	oss << Drawable::operator std::string() << DrawableGroup::operator std::string();
	return oss.str();
}