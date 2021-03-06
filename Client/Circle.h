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
	double radius;

public:
	/** @brief Le constructeur par défaut. */
	Circle();

	/** @brief Le constructeur par valeurs. */
	Circle(const Vector2D& center, const double radius, const shared_ptr<const Color>& c);
	
	/** @brief Le constructeur par référence. */
	Circle(const Circle& cercle);
	
	/** @brief Le destructeur. */
	virtual ~Circle();

	/** @brief Accesseur de radius. */
	const double getRadius() const;

	/** @brief Retourne l'aire du Drawable. **/
	virtual double Area() const;

	/** @brief Retourne le nom de la classe. */
	string getName() const;

	/**	@see Drawable.Scale() */
	Circle& Scale(const Vector2D& point, const double ratio);

	/** @brief Implémentation de la methode accept du DP Visitor.
		@param v la Classe Visitor à visiter.
		@return la string obtenue par la visit de la classe. */
	string  accept(Visitor* v);

	/** @brief Mutateur de radius. */
	void setRadius(const double rayon);

	/** @brief Surcharge de l'opérateur String. */
	operator string() const;

	/** @brief Suppression du remplacement de tableau de sommets. */
	void setVertices(const vector<Vector2D>& sommets) = delete;

	/** @see Drawable.Clone(). */
	virtual Circle* Clone() const { return new Circle(*this); }

	/** @brief Suppression de l'opérateur +. */
	Shape operator+(const Vector2D & vecteur) = delete;

	/** @brief Suppression de l'opérateur --. */
	Shape operator--() = delete;
};