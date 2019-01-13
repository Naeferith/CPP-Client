#pragma once

#include <memory>
#include "Shape.h"
#include "Vector2D.h"

using namespace std;

/**	
	@brief Représente un cercle.

	Un Circle est une Shape particulière défini par un rayon.
*/
class Circle : public Shape {
private:
	
	/** @brief Le rayon du cercle. */
	unsigned int radius;

public:
	/** @brief Le constructeur par défaut. */
	Circle();

	/** @brief Le constructeur par valeurs. */
	Circle(const Vector2D& centre, const unsigned int rayon, const shared_ptr<const Color>& couleur);
	
	/** @brief Le constructeur par référence. */
	Circle(const Circle& cercle);
	
	/** @brief Le destructeur. */
	~Circle();

	/** @brief Accesseur de radius. */
	const int getRadius() const;

	/** @brief Retourne le nom de la classe. */
	string getName() const;

	/** @brief Implémentation de la methode accept du DP Visitor. */
	string* accept(Visitor* v);

	/** @brief Mutateur de radius. */
	void setRadius(const int rayon);
};