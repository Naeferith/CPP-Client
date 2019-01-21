#pragma once

#include "Erreur.h"

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
	Vector2D(const double X=0, const double Y=0) : x(X), y(Y) {}

	/** @brief Retourne le determinant. */
	static double Det(const Vector2D& ab, const Vector2D& ac) { return (ab.x * ac.y) - (ab.y * ac.x); }

	/** @brief Surcharge de l'opérateur +. */
	virtual Vector2D operator+(const Vector2D& v) const { return Vector2D(v.x + x , v.y + y); }

	/** @brief Surcharge de l'opérateur +. */
	Vector2D operator+(const double a) { return Vector2D(x+a, y+a); }

	/** @brief Surcharge de l'opérateur + inversé. */
	friend Vector2D operator+(const double a, const Vector2D& v) { return v + a; }

	/** @brief Surcharge de l'opérateur -. */
	virtual Vector2D operator-(const Vector2D& v) const { return Vector2D(v.x - x, v.y - y); }

	/** @brief Surcharge de l'opérateur -. */
	Vector2D operator-(const double a) { return Vector2D(x - a, y-a); }

	/** @brief Surcharge de l'opérateur - inversé. */
	friend Vector2D operator-(const double a, const Vector2D v) { return v - a; }

	/** @brief Surcharge de l'opérateur *. */
	Vector2D operator*(const double a) const { return Vector2D(x * a, y * a); }

	/** @brief Surcharge de l'opérateur * inversé. */
	friend Vector2D operator*(const double a, const Vector2D& v) { return v * a; }

	/** @brief Surcharge de l'opérateur /. */
	Vector2D operator/(const double den) const { if (!den) throw Erreur(-10, "Divise by 0."); return *this*(1 / den); }

	/** @brief Surcharge de l'opérateur +=. */
	Vector2D& operator+=(const double a) { return *this = *this + a; }

	/** @brief Surcharge de l'opérateur -=. */
	Vector2D& operator-=(const double a) { return *this = *this - a; }

	/** @brief Surcharge de l'opérateur /=. */
	Vector2D& operator/=(const double a) { return *this = *this / a; }

	/** @brief Surcharge de l'opérateur *=. */
	Vector2D& operator*=(const double a) { return *this = *this * a; }

	// @brief Surchage de l'opérateur String. */
	virtual operator string() const;

	/** @brief Surcharge de l'opérateur <<. */
	friend ostream& operator<<(std::ostream&, const Vector2D&);
};

