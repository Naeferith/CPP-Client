#pragma once

#include <iostream>
#include "Vector3D.h"

	class Color : public Vector3D {
	private:
		Color(const double r, const double g, const double b) : Vector3D(r, g, b) {}

	public:
		static const Color BLACK;
		static const Color BLUE;
		static const Color CYAN;
		static const Color GREEN;
		static const Color RED;
		static const Color YELLOW;

		friend std::ostream& operator<<(std::ostream&, const Color&);
	};