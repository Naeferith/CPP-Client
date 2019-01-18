#include "stdafx.h"
#include "Drawable.h"
#include "ShapeGroup.h"

using namespace std;

int Drawable::indexId = 0;

void Drawable::setId(const int Id) { id = Id; }

Drawable::Drawable() : id(++Drawable::indexId) {
	color = make_shared<const Color>(Color::retrieveDefaultColor(0,0,0));
}

Drawable::Drawable(const shared_ptr<const Color>& c) : color(c), id(++Drawable::indexId) {}

Drawable::Drawable(const Drawable& d) : color(d.color), id(d.id) {}

Drawable::~Drawable() {}

ShapeGroup* Drawable::getGroup() {
	return group;
}

void Drawable::setGroup(ShapeGroup* grp) {
	group = grp;
}

double Drawable::Det(const Vector2D& a, const Vector2D& b, const Vector2D& c) {
	Vector2D ab = b - a,
		ac = c - a;
	return (ab.x * ac.y) - (ab.y * ac.x); // TODO
}

const shared_ptr<const Color>& Drawable::getColor() const { return color; }

const int Drawable::getId() const { return id; }

bool Drawable::operator==(const Drawable& d) const {
	return id == d.id;
}

const Drawable& Drawable::operator=(const Drawable &d)
{
	if (this != &d) {
		color = d.color;
	}
	return *this;
}

Drawable::operator string() const {
	ostringstream oss;
	oss << getName() << ": " << *getColor();
	return oss.str();
}

ostream & operator<<(ostream& strm, const Drawable& v)
{
	return strm << "[ " << (string)v << " ]";
}