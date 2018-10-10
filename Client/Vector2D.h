#pragma once

#include "Vector3D.h"

class Vector2D : public Vector3D {
private:
	Vector3D::y;

public:
	Vector2D();
	Vector2D(const double, const double);
	Vector2D(const Vector2D&);
	~Vector2D();

	friend std::ostream& operator<<(std::ostream&, const Vector2D&);
};