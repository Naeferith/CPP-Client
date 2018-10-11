#include "stdafx.h"
#include "Vector2D.h"

Vector2D::Vector2D() : Vector3D() {
}

Vector2D::Vector2D(const double X, const double Y) : Vector3D(X, Y, 0) {
}

Vector2D::Vector2D(const Vector2D& v) : Vector3D(v.getX(), v.getY(), v.getZ()){
}

Vector2D::~Vector2D() {
}

bool Vector2D::operator==(const Vector2D& v) const {
	return Vector3D::operator==(v);
}

std::ostream & operator<<(std::ostream& strm, const Vector2D& v)
{
	return strm << "[X: " << v.getX() << ", Y: " << v.getY() << "]";
}
