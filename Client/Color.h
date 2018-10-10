#pragma once

#include <iostream>
#include "Vector3D.h"

	class Color : public Vector3D {
	private:
		Color(const double r, const double g, const double b) : Vector3D(r, g, b) {}

	public:
		static const Vector3D BLACK;
		static const Vector3D BLUE;
		static const Vector3D CYAN;
		static const Vector3D GREEN;
		static const Vector3D RED;
		static const Vector3D YELLOW;
	};