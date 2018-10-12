#pragma once

#include "Shape.h"
#include "Vector2D.h"

/**	
	@brief Représente un cercle.

	Un Circle est une Shape particulière défini par un rayon.
*/
class Circle : public Shape {
private:
	/** @brief Encapsulation de la variable protected verticies. */
	Shape::vertices;
	
	/** @brief Le rayon du cercle. */
	unsigned int radius;

public:
	/** @brief Le constructeur par défaut. */
	Circle();

	/** @brief Le constructeur par valeurs. */
	Circle(const Vector2D& centre, const unsigned int rayon, const Color* couleur);
	
	/** @brief Le constructeur par référence. */
	Circle(const Circle& cercle);
	
	/** @brief Le destructeur. */
	~Circle();

	/** @brief Accesseur de radius. */
	const int getRadius() const;

	/** @brief Mutateur de radius. */
	void setRadius(const int rayon);
};