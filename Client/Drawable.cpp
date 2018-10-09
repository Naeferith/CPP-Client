#include "stdafx.h"
#include "Drawable.h"

using namespace std;

Drawable::Drawable() {
}

Drawable::Drawable(Color* C) {
	color = C;
}

Drawable::Drawable(const Drawable &) {
}

Drawable::~Drawable() {
	free(color);
}

const Color Drawable::getColor() const { return *color; }