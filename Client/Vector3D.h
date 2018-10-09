#pragma once

class Vector3D {
private:
	double z;

protected:
	double x;
	double y;

public:
	Vector3D();
	Vector3D(const double, const double, const double);
	Vector3D(const Vector3D&);
	~Vector3D();

	const double getX() const;
	const double getY() const;
	const double getZ() const;

	void setX(const double);
	void setY(const double);
	void setZ(const double);
};
