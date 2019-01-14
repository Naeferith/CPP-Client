#include "stdafx.h"
#include "Vector2D.h"

using namespace std;

Vector2D::Vector2D() : x(0), y(0) {}

Vector2D::Vector2D(const double X, const double Y) : x(X), y(Y) {}

Vector2D::Vector2D(const Vector2D& v) : x(v.x), y(v.y) {}

Vector2D::~Vector2D() {}

void Vector2D::setX(const double X) { x = X; }

void Vector2D::setY(const double Y) { y = Y; }

bool Vector2D::operator==(const Vector2D& v) const {
	return v.x == x && v.y == y;
}

const Vector2D Vector2D::operator=(const Vector2D& v) {
	x = v.x;
	y = v.y;
	return *this;
}

Vector2D Vector2D::operator+(const Vector2D& v) const {
	return Vector2D(x + v.x, y + v.y);
}

Vector2D Vector2D::operator-(const Vector2D& v) const {
	return Vector2D(x - v.x, y - v.y);
}

Vector2D Vector2D::operator/(const short int den) const {
	return Vector2D(x / den, y / den);
}

Vector2D::operator string() const {
	ostringstream oss;
	oss << "X:" << x << ", Y:" << y;
	return oss.str();
}

ostream & operator<<(ostream& strm, const Vector2D& v)
{
	return strm << "[" << (string)v << "]";
<<<<<<< HEAD
}
=======
}
>>>>>>> bafa4096d91de08c21b782d05e28f0a16617a716
