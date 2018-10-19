#pragma once

#include <iostream>
#include "Vector3D.h"

/**
	@brief Représente une couleur RGB.

	Une Color a ses composantes comprises entre 0 et 1
*/
class Color : public Vector3D {
private:
	/** @brief Le constructeur par valeurs. */
	Color(const double r, const double g, const double b) : Vector3D(r, g, b) {}

public:
	/** @brief Couleur noire (0,0,0). */
	static const Color BLACK;

	/** @brief Couleur bleue (0,0,255). */
	static const Color BLUE;

	/** @brief Couleur cyan (0,255,255). */
	static const Color CYAN;

	/** @brief Couleur verte (0,255,0). */
	static const Color GREEN;

	/** @brief Couleur rouge (255,0,0). */
	static const Color RED;

	/** @brief Couleur jaune (255,255,0). */
	static const Color YELLOW;

	/** @brief Surcharge de l'opérateur <<. */
	friend std::ostream& operator<<(std::ostream& stream, const Color& couleur);
};