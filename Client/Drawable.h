#pragma once

#include "Color.h"

using namespace std;

/*Représente une forme dessinable.
 *
 *
 */
class Drawable {
protected:
	Color* color;

public:
	Drawable();
	Drawable(Color*);
	Drawable(const Drawable&);
	~Drawable();

	const Color getColor() const;
};



