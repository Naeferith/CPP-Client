#include "stdafx.h"
#include "Drawable.h"

Drawable::Drawable() : color(&Color::BLACK) {}

Drawable::Drawable(const Color* C) : color(C) {}

Drawable::Drawable(const Drawable& d) : color(&d.getColor()) {}

Drawable::~Drawable() {
	//free((Vector3D*) color); fait planter
}

const Color Drawable::getColor() const { return *color; }

void Drawable::setColor(const Color* c) { color = c; }

const Drawable& Drawable::operator=(const Drawable &d)
{
	if (this == &d) return *this;

	color = &d.getColor();

	return *this;
}
