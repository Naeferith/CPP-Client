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

	/** @brief Le constructeur par défaut. */
	Vector2D();

	/** @brief Le constructeur par valeurs. */
	Vector2D(const double X, const double Y);

	/** @brief Le constructeur par référence. */
	Vector2D(const Vector2D& vecteur);

	/** @brief Le destructeur. */
	virtual ~Vector2D();

	/** @brief Mutateur de la composante X. */
	void setX(const double X);

	/** @brief Mutateur de la composante Y. */
	void setY(const double Y);

	/** @brief Surcharge de l'opérateur +. */
	virtual Vector2D operator+(const Vector2D&) const;

	/** @brief Surcharge de l'opérateur -. */
	virtual Vector2D operator-(const Vector2D&) const;

	/** @brief Surcharge de l'opérateur *. */
	friend Vector2D operator*(const double) const;

	/** @brief Surcharge de l'opérateur /. */
	Vector2D operator/(const double den) const;

	// @brief Surchage de l'opérateur String. */
	virtual operator string() const;

	/** @brief Surcharge de l'opérateur <<. */
	friend ostream& operator<<(std::ostream&, const Vector2D&);
};

/** @brief Surcharge de l'opérateur * inversé. */
Vector2D operator*(const Vector2D&, const double);