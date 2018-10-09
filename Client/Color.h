#pragma once

#include "Vector3D.h"

class Color : public Vector3D {
private:
	static const Color BLACK;
	static const Color BLUE;
	static const Color CYAN;
	static const Color GREEN;
	static const Color RED;
	static const Color YELLOW;

	Color(const double r, const double g, const double b) : Vector3D(r,g,b) {}
};