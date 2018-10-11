#pragma once

#include <vector>
#include "Drawable.h"

class ShapeGroup : public Drawable {
private:
	vector<Drawable> shapes;

public:
	ShapeGroup();
	ShapeGroup(const vector<Drawable>&, const Color*);
	~ShapeGroup();

	const vector<Drawable> getShapes() const;

	void setShapes(const vector<Drawable>&);

	ShapeGroup operator+(Drawable&);
	ShapeGroup operator-(Drawable&);
	bool operator==(const ShapeGroup&) const;
	const ShapeGroup& operator=(const ShapeGroup&);
};