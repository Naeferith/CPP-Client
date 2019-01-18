#pragma once

using namespace std;

/**
	@brief Représente un vecteur a 2 dimensions.
	Un Vector2D est un Vector3D dont la composante Z est nulle.
*/
struct Vector2D {
public:
	/** @brief La composante X. */
	double x;

	/** @brief La composante Y. */
	double y;

	/** @brief Le constructeur par valeurs. */
	Vector2D(const double X=100, const double Y=100) : x(X), y(Y) {}

	/** @brief Surcharge de l'opérateur +. */
	virtual Vector2D operator+(const Vector2D&) const;

	/** @brief Surcharge de l'opérateur -. */
	virtual Vector2D operator-(const Vector2D&) const;

	/** @brief Surcharge de l'opérateur *. */
	Vector2D operator*(const double v) const;

	/** @brief Surcharge de l'opérateur * inversé. */
	friend Vector2D operator*(const double mul, const Vector2D& v) { return v * mul;  }

	/** @brief Surcharge de l'opérateur /. */
	Vector2D operator/(const double den) const { return *this * (1.0 / den); }

	// @brief Surchage de l'opérateur String. */
	virtual operator string() const;

	/** @brief Surcharge de l'opérateur <<. */
	friend ostream& operator<<(std::ostream&, const Vector2D&);
};