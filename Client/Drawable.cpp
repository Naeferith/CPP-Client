#include "stdafx.h"
#include "Drawable.h"

using namespace std;

Drawable::Drawable() {
	color = make_shared<const Color>(Color::BLACK);
}

Drawable::Drawable(const shared_ptr<const Color>& c) : color(c) {}

Drawable::Drawable(const Drawable& d) : color(d.color) {}

Drawable::~Drawable() {
}

const Color Drawable::getColor() const { return *color; }

bool Drawable::operator==(const Drawable& d) const {
	return color==d.color;
}

const Drawable& Drawable::operator=(const Drawable &d)
{
	if (this != &d) color = d.color;

	return *this;
}
