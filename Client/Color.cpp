#include "stdafx.h"
#include "Color.h"

const Color Color::BLACK(0, 0, 0);
const Color Color::BLUE(0, 0, 255);
const Color Color::CYAN(0, 255, 255);
const Color Color::GREEN(0, 255, 0);
const Color Color::RED(255, 0, 0);
const Color Color::YELLOW(255, 255, 0);

Color::operator string() const {
	ostringstream oss;
	oss << "R:" << x << ", G:" << y << ", B:" << z;
	return oss.str();
}
