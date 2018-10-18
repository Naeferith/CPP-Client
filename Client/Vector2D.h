#pragma once

#include "Vector3D.h"


/**
	@brief Représente un vecteur a 2 dimensions.

	Un Vector2D est un Vector3D dont la composante Z est nulle.
*/
struct Vector2D : public Vector3D {
private:
	/** @brief Encapsulation de la composante Y. */
	Vector3D::y;

public:
	/** @brief Le constructeur par défaut. */
	Vector2D();

	/** @brief Le constructeur par valeurs. */
	Vector2D(const double X, const double Y);

	/** @brief Le constructeur par référence. */
	Vector2D(const Vector2D& vecteur);

	/** @brief Le destructeur. */
	~Vector2D();

	/** @brief Surcharge de l'opérateur ==. */
	bool operator==(const Vector2D&) const;

	/** @brief Surcharge de l'opérateur <<. */
	friend std::ostream& operator<<(std::ostream&, const Vector2D&);
};