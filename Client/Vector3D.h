#pragma once

#include <iostream>
#include "Vector2D.h"

/**
	@brief Représente un vecteur à 3 dimensions.

	C'est une structure composés de 3 double .
	Cette structure permet de stocker diverses information comme des coordonnées dans l'espace ou une couleur.
*/

using namespace std;

struct Vector3D : public Vector2D {
public:

	/** @brief La composante Z. */
	double z;

	/** @brief Le constructeur par défaut. */
	Vector3D();

	/** @brief Le constructeur par valeurs. */
	Vector3D(const double X, const double Y, const double Z);

	/** @brief Le constructeur par référence. */
	Vector3D(const Vector3D& vecteur);

	/** @brief Le destructeur. */
	~Vector3D();

	/** @brief Mutateur de la composante Z. */
	void setZ(const double Z);

	/** @brief Surcharge de l'opérateur String. */
	operator string() const;

	/** @brief Surcharge de l'opérateur ==. */
	bool operator==(const Vector3D& vecteur) const;

	/** @brief Surcharge de l'opérateur =. */
	const Vector3D operator=(const Vector3D& vecteur);
};