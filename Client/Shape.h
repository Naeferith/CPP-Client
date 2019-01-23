#pragma once

#include <vector>
#include <memory>
#include "Drawable.h"


/**
	@brief Représente une forme dessinable.

	Une Shape est définie par une collection de sommets.
*/
class Shape : public Drawable {
protected:
	/** @brief La liste des sommets. */
	vector<Vector2D> vertices;

public:
	/** @brief Le constructeur par défaut. */
	Shape();

	/** @brief Le constructeur par valeurs. */
	Shape(const vector<Vector2D>& sommets, const shared_ptr<const Color>& couleur);

	/** @brief Le constructeur par copie. */
	Shape(const Shape& s);
	
	/** @brief Le destructeur. */
	virtual ~Shape();

	/** @brief Accesseur pour vertices. */
	const vector<Vector2D> getVertices() const;

	/** @brief Retourne l'aire du Drawable. **/
	virtual double Area() const;

	/** @brief Mutateur pour vertices. */
	void setVertices(const vector<Vector2D>& sommets);

	/**	@see Drawable.Translate() */
	virtual void Translate(const Vector2D& vecteur);

	/**	@see Drawable.Scale() */
	virtual void Scale(const Vector2D& point, const double ratio);

	/**	@see Drawable.Rotate() */
	virtual void Rotate(const Vector2D& point, const double angle);

	/** @brief Retourne le nom de la classe. */
	virtual string getName() const;

	/** @brief Implémentation de la methode accept du DP Visitor. */
	virtual string  accept(Visitor* v);

	/** @see Drawable.Clone(). */
	virtual shared_ptr<Drawable> Clone() const { return make_shared<Shape>(*this); }

	/** @brief Surcharge de l'opérateur +. */
	Shape operator+(const Vector2D& vecteur);

	/** @brief Surcharge de l'opérateur --. 
		Enlève le dernier Vector2D ajouté.
	*/
	Shape operator--();

	/** @biref Surcharge de l'opérateur String. */
	virtual operator string() const;
};