#pragma once

#include <iostream>
#include "Vector2D.h"

using namespace std;

/**
	@brief Représente un vecteur à 3 dimensions.

	C'est une structure composés de 3 double.
	Cette structure permet de stocker diverses information comme des coordonnées dans l'espace ou une couleur.
*/
struct Vector3D {
public:
	/** @brief La composante X. */
	double x;

	/** @brief La composante Y. */
	double y;

	/** @brief La composante Z. */
	double z;

	/** @brief Le constructeur par valeurs. */
	Vector3D(const double X=0, const double Y=0, const double Z=0);

	/** @brief Le destructeur. */
	virtual ~Vector3D();

	/** @brief Surcharge de l'opérateur String. */
	operator string() const;

	/** @brief Surcharge de l'opérateur <<. */
	friend ostream& operator<<(ostream&, const Vector3D&);
};