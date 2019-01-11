#pragma once
#include "Shape.h"

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

	/** @brief Implémentation de la methode accept du DP Visitor. */
	string* accept(Visitor* v);

	/** @brief Retourne le nom de la classe. */
	string getName() const;

	/** @brief Mutateur de radius. */
	void setRadius(const int rayon);

	/** @brief Change le centre. */
	void setCenter(const Vector2D&);

	operator string() const;

	/** @brief Suppression du remplacement de tableau de sommets. */
	void setVertices(const vector<Vector2D>& sommets) = delete;

	/** @brief Suppression de l'opérateur +. */
	Shape operator+(const Vector2D & vecteur) = delete;

	/** @brief Suppression de l'opérateur --. */
	Shape operator--() = delete;
};