#include "stdafx.h"
#include "Vector2D.h"

using namespace std;

Vector2D::Vector2D() : x(0), y(0) {}

Vector2D::Vector2D(const double X, const double Y) : x(X), y(Y) {}

Vector2D::Vector2D(const Vector2D& v) : x(v.x), y(v.y) {}

Vector2D::~Vector2D() {}

void Vector2D::setX(const double X) { x = X; }

void Vector2D::setY(const double Y) { y = Y; }

Vector2D Vector2D::operator+(const Vector2D& v) const {
	return Vector2D(x + v.x, y + v.y);
}

Vector2D Vector2D::operator*(const double v) const {
	return Vector2D(x * v, y * v);
}

Vector2D Vector2D::operator-(const Vector2D& v) const {
	return Vector2D(x - v.x, y - v.y);
}

Vector2D Vector2D::operator/(const double den) const {
	return Vector2D(x / den, y / den);
}

Vector2D Vector2D::operator*(const double mul) const {
	return operator*(*this, mul);
}

Vector2D operator*(const Vector2D& v,const double mul) {
	return Vector2D(v.x *mul, v.y * mul);
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