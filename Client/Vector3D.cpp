#include "stdafx.h"
#include "Vector3D.h"

using namespace std;

Vector3D::Vector3D(const double X, const double Y, const double Z) : x(X), y(Y), z(Z) {}

Vector3D::~Vector3D() {}

Vector3D::operator string() const {
	ostringstream oss;
	oss << "X:" << x << ", Y:" << y << ", Z:" << z;
	return oss.str();
}

ostream& operator<<(ostream& strm, const Vector3D& v) {
	return strm << "[" << (string)v << "]";
}