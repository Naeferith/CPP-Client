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

bool Drawable::operator==(const Drawable& d) const {
	return color==d.color;
}

const Drawable& Drawable::operator=(const Drawable &d)
{
	if (this == &d) return *this;

	color = &d.getColor();

	return *this;
}

void Drawable::accept(Visitor * v) { v->visit(this); }
