#include "stdafx.h"
#include "Vector2D.h"

using namespace std;

Vector2D Vector2D::Rotate(const Vector2D& point, const Vector2D& vertice, const double rad) {
	double cos_rad = cos(rad), sin_rad = sin(rad);
	Vector2D p = vertice,
		value;
	p -= point;
	value.x = p.x * cos_rad - p.y * sin_rad;
	value.y = p.x * sin_rad + p.y * cos_rad;
	return value + point;

}

Vector2D::operator string() const {
	ostringstream oss;
	oss << "X:" << x << ", Y:" << y;
	return oss.str();
}

Vector2D Vector2D::operator/(const double den) const {
	if (!den) throw Erreur(MAT_ERROR, "Divise by 0.");
	return *this*(1 / den); 
}

ostream & operator<<(ostream& strm, const Vector2D& v)
{
	return strm << "[" << (string)v << "]";
}