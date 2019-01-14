#include "stdafx.h"
#include "Color.h"

const Color Color::BLACK(0, 0, 0);
const Color Color::BLUE(0, 0, 1);
const Color Color::CYAN(0, 1, 1);
const Color Color::GREEN(0, 1, 0);
const Color Color::RED(1, 0, 0);
const Color Color::YELLOW(1, 1, 0);

Color::operator string() const {
	ostringstream oss;
	oss << "R:" << x << ", G:" << y << ", B:" << z;
	return oss.str();
}
