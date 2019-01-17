#include "stdafx.h"
#include "DrawableGroup.h"

using namespace std;

DrawableGroup::~DrawableGroup() { }

const vector<shared_ptr<Drawable>>& DrawableGroup::getShapes() const{ return shapes;}

void DrawableGroup::Delete(int i) {
	if (shapes.size() >= i) throw Erreur(-8, "Size too small.");
	shapes.erase(shapes.begin()+i);
}

DrawableGroup& DrawableGroup::operator+(shared_ptr<Drawable> d) {

	shapes.push_back(d);
	return *this;
}

DrawableGroup& DrawableGroup::operator-(shared_ptr<Drawable> d) {
	for (int k = 0; k < shapes.size(); ++k) {
		if (*shapes.at(k) == *d) {
			d.reset();
			Delete(k);
			return *this;
		}
	}
	throw Erreur(-9, "Drawable not found.");
}

bool DrawableGroup::operator==(const shared_ptr<Drawable> sg) const {
	for (auto &shape : shapes) {
		if (*shape == *sg) return true;
	}
	return false;
}