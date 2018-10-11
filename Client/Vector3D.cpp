#include "stdafx.h"
#include "Vector3D.h"

Vector3D::Vector3D() {
	x = y = z = 0;
}

Vector3D::Vector3D(const double X, const double Y, const double Z) {
	x = X;
	y = Y;
	z = Z;
}

Vector3D::Vector3D(const Vector3D& v) {
	x = v.getX();
	y = v.getY();
	z = v.getZ();
}

Vector3D::~Vector3D() {
}

const double Vector3D::getX() const{ return x; }

const double Vector3D::getY() const { return y; }

const double Vector3D::getZ() const { return z; }

void Vector3D::setX(const double X) { x = X; }

void Vector3D::setY(const double Y) { y = Y; }

void Vector3D::setZ(const double Z) { z = Z; }

bool Vector3D::operator==(const Vector3D& v) const {
	return (x == v.getX() && y == v.getY() && z == v.getZ());
}

const Vector3D Vector3D::operator=(const Vector3D& v) {
	if (this == &v) return *this;

	x = v.getX();
	y = v.getY();
	z = v.getZ();

	return *this;
}

std::ostream & operator<<(std::ostream& strm, const Vector3D& v) {
	return strm << "[X: " << v.getX() << ", Y: " << v.getY() << ", Z: " << v.getZ() << "]";
}
