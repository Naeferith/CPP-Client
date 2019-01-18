#include "stdafx.h"
#include "Vector2D.h"

using namespace std;

Vector2D Vector2D::operator+(const Vector2D& v) const {
	return Vector2D(x + v.x, y + v.y);
}

Vector2D Vector2D::operator*(const double v) const {
	return Vector2D(x * v, y * v);
}

Vector2D Vector2D::operator-(const Vector2D& v) const {
	return Vector2D(x - v.x, y - v.y);
}

Vector2D::operator string() const {
	ostringstream oss;
	oss << "X:" << x << ", Y:" << y;
	return oss.str();
}

ostream & operator<<(ostream& strm, const Vector2D& v)
{
	return strm << "[" << (string)v << "]";
}