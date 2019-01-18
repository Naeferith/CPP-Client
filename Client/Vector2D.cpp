#include "stdafx.h"
#include "Vector2D.h"

using namespace std;

double Vector2D::Det(const Vector2D& a, const Vector2D& b, const Vector2D& c) {
	Vector2D ab = b - a,
		ac = c - a;
	return (ab.x * ac.y) - (ab.y * ac.x);
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
