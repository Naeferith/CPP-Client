#include "stdafx.h"
#include "Vector3D.h"

using namespace std;

Vector3D::Vector3D() : Vector2D(), z(0) {}

Vector3D::Vector3D(const double X, const double Y, const double Z) : Vector2D(X, Y), z(Z) {}

Vector3D::Vector3D(const Vector3D& v) : Vector2D(v.x, v.y), z(v.z) {}

Vector3D::~Vector3D() {}

void Vector3D::setZ(const double Z) { z = Z; }

bool Vector3D::operator==(const Vector3D& v) const {
	return Vector2D::operator==(v) && v.z == z;
}

const Vector3D Vector3D::operator=(const Vector3D& v) {
	Vector2D::operator=(v);
	z = v.z;
	return *this;
}

ostream & operator<<(ostream& strm, const Vector3D& v) {
	return strm << "[X: " << v.x << ", Y: " << v.y << ", Z: " << v.z << "]";
}
