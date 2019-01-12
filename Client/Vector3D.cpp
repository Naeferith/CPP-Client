#include "stdafx.h"
#include "Vector3D.h"

using namespace std;

Vector3D::Vector3D() : x(0), y(0), z(0) {}

Vector3D::Vector3D(const double X, const double Y, const double Z) : x(X), y(Y), z(Z) {}

Vector3D::Vector3D(const Vector3D& v) : x(v.x), y(v.y), z(v.z) {}

Vector3D::~Vector3D() {}

void Vector3D::setX(const double X) { x = X; }

void Vector3D::setY(const double Y) { y = Y; }

void Vector3D::setZ(const double Z) { z = Z; }

bool Vector3D::operator==(const Vector3D& v) const {
	return (x == v.x && y == v.y && z == v.z);
}

const Vector3D Vector3D::operator=(const Vector3D& v) {
	if (this == &v) return *this;

	x = v.x;
	y = v.y;
	z = v.z;

	return *this;
}

ostream & operator<<(ostream& strm, const Vector3D& v) {
	return strm << "[X: " << v.x << ", Y: " << v.y << ", Z: " << v.z << "]";
}
