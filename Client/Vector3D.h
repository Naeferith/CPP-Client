#pragma once

#include <iostream>

/**
	@brief Représente un vecteur à 3 dimensions.

	C'est une structure composés de 3 double .
	Cette structure permet de stocker diverses information comme des coordonnées dans l'espace ou une couleur.
*/

using namespace std;

struct Vector3D {
public:

	/** @brief La composante X. */
	double x;

	/** @brief La composante Y. */
	double y;

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

	/** @brief Mutateur de la composante X. */
	void setX(const double X);

	/** @brief Mutateur de la composante Y. */
	void setY(const double Y);

	/** @brief Mutateur de la composante Z. */
	void setZ(const double Z);

	/** @brief Surcharge de l'opérateur ==. */
	bool operator==(const Vector3D& vecteur) const;

	/** @brief Surcharge de l'opérateur =. */
	const Vector3D operator=(const Vector3D& vecteur);

	/** @brief Surcharge de l'opérateur <<. */
	friend ostream& operator<<(ostream& stream, const Vector3D& vecteur);
};