#pragma once

#include <memory>
#include <vector>
#include "DrawableGroup.h"

using namespace std;

/**
	@brief Représente un ensemble de Shape.

	Un ShapeGroup est une collection de Drawable.
*/
class ShapeGroup : public Drawable, public DrawableGroup {
public:
	/** @brief Le constructeur par défaut. */
	ShapeGroup();

	/** @brief Le constructeur par valeurs. */
	ShapeGroup(shared_ptr<const Color>& couleur);

	/** @brief le constructeur par copie. */
	ShapeGroup(const ShapeGroup& sg) : Drawable(sg), DrawableGroup(sg) {}

	/** @brief Le destructeur. On copie simplement les pointeurs,
	On ne doit donc pas libérer chaque Drawable* ici, mais dans la zone
	de Création. */
	virtual ~ShapeGroup();

	/** @brief Accesseur por shapes. */
	const vector<shared_ptr<Drawable>>& getShapes() const;

	/** @brief Retourne l'aire du Drawable. **/
	virtual double Area() const;

	/** @brief Supprime l'élément i variant de 0 à size-1. */
	virtual void Delete(int i);

	/** @brief Supprime l'élément de shapes. */
	virtual void Delete(shared_ptr<Drawable>);

	/** @brief Ajout d'un Drawable. */
	void add(shared_ptr<Drawable> drawable);

	/**	@see Drawable.setColor() */
	void setColor(const shared_ptr<const Color>& couleur);

	/**	@see Drawable.Translate() */
	ShapeGroup& Translate(const Vector2D& vecteur);

	/**	@see Drawable.Scale() */
	ShapeGroup& Scale(const Vector2D& point, const double ratio);

	/**	@see Drawable.Rotate() */
	ShapeGroup& Rotate(const Vector2D& point, const double angle);

	/** @brief Retourne le nom de la classe. */
	string getName() const;

	/** @brief Implémentation de la methode accept du DP Visitor. */
	string  accept(Visitor* v);

	/** @see Drawable.Clone(). */
	virtual ShapeGroup* Clone() const { return new ShapeGroup(*this); }

	/** @brief Surcharge de l'opérateur ==. */
	bool operator==(const shared_ptr<Drawable> shapeGroup) const;

	/** @brief Surcharge de l'opérateur String.*/
	virtual operator string() const;
};