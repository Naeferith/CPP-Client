#include "stdafx.h"
#include "DrawableGroup.h"

using namespace std;

DrawableGroup::~DrawableGroup() { }

DrawableGroup::DrawableGroup(const DrawableGroup& gp) {
	shapes = gp.cpyShapes();
}

vector<shared_ptr<Drawable>> DrawableGroup::cpyShapes() const {
	vector<shared_ptr<Drawable>> shp;
	for (auto &shape : shapes) shp.push_back(shared_ptr<Drawable>(shape->Clone()));
	return shp;
}

const vector<shared_ptr<Drawable>>& DrawableGroup::getShapes() const{ return shapes;}

void DrawableGroup::Delete(int i) {
	if (shapes.size() <= i) throw Erreur(GEOMETRIC_ERROR, "Size too small.");
	shapes.erase(shapes.begin()+i);
}

void DrawableGroup::Delete(shared_ptr<Drawable> d) {
	int k = -1;
	size_t s= shapes.size();
	while (++k < s) {
		if (*shapes.at(k) == *d) {
			d.reset();
			Delete(k);
			break;
		}
	}
}

void DrawableGroup::add(shared_ptr<Drawable> drawable) {
	shapes.push_back(drawable);
}

bool DrawableGroup::operator==(const shared_ptr<Drawable> sg) const {
	for (auto &shape : shapes) {
		if (*shape == *sg) return true;
	}
	return false;
}

DrawableGroup::operator string() const {
	ostringstream oss;
	oss << " [>> ";
	for (auto &shape : shapes)
		oss << *shape;
	oss << " <<]";
	return oss.str();
}