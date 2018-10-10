#pragma once

#include "Color.h"

using namespace std;

/*Représente une forme dessinable.
 *
 *
 */
class Drawable {
protected:
	const Vector3D* color;

public:
	Drawable();
	Drawable(const Vector3D*);
	Drawable(const Drawable&);
	~Drawable();

	const Vector3D getColor() const;

	void setColor(const Vector3D*);

	const Drawable& operator=(const Drawable&);
};



