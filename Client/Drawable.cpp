#include "stdafx.h"
#include "Drawable.h"

Drawable::Drawable() : color(&Color::BLACK) {}

Drawable::Drawable(const Vector3D* C) : color(C) {}

Drawable::Drawable(const Drawable& d) : color(&d.getColor()) {}

Drawable::~Drawable() {
	//free((Color*) color); fait planter
}

const Vector3D Drawable::getColor() const { return *color; }

void Drawable::setColor(const Vector3D* c) { color = c; }

const Drawable& Drawable::operator=(const Drawable &d)
{
	if (this == &d) return *this;

	color = &d.getColor();

	return *this;
}
