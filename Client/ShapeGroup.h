#pragma once

#include <vector>
#include "Drawable.h"

class ShapeGroup : public Drawable {
private:
	vector<Drawable> shapes;

public:
	ShapeGroup();
	ShapeGroup(vector<Drawable>);
	~ShapeGroup();
};