#pragma once

#include <vector>
#include "Vector2D.h"
#include "Vector3D.h"

using namespace std;

class Drawable {
private:
	vector<Vector2D> vertices;
	Vector3D color;

public:
	Drawable();
	Drawable(vector<Vector2D>, Vector3D);
	Drawable(const Drawable&);

	const Vector3D getColor() const;
	
	void Translate(const Vector2D);
	void Scale(const Vector2D, const double);
	void Rotate(const Vector2D, const double);
};



