#include "stdafx.h"
#include "DrawableGroup.h"

using namespace std;

const vector<shared_ptr<Drawable>>& DrawableGroup::getShapes() const{
	return shapes;
}

void DrawableGroup::Delete(int i) {
	if (shapes.size() >= i) throw Erreur(-8, "Size too small.");
	shapes.erase(shapes.begin()+i);
}

DrawableGroup& DrawableGroup::operator+(shared_ptr<Drawable> d) {

	shapes.push_back(shared_ptr<Drawable>(d));
	return *this;
}

DrawableGroup& DrawableGroup::operator-(shared_ptr<Drawable> d) {
	for (int k = 0; k < shapes.size(); ++k) {
		if (*shapes.at(k) == *d) {
			d.reset();
			shapes.Delete(k);
			return *this;
		}
	}
	return *this;
}

bool DrawableGroup::operator==(const shared_ptr<Drawable> sg) const {
	for (auto &shape : shapes) {
		if (*shape == *sg) return true;
	}
}