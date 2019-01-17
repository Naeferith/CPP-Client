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
private:
	/** @brief La liste des formes. */
	vector<shared_ptr<Drawable>> shapes;

public:
	/** @brief Le constructeur par défaut. */
	ShapeGroup();

	/** @brief Le constructeur par valeurs. */
	ShapeGroup(shared_ptr<const Color>& couleur);

	/** @brief Le destructeur. On copie simplement les pointeurs,
	On ne doit donc pas libérer chaque Drawable* ici, mais dans la zone
	de Création. */
	virtual ~ShapeGroup();

	/** @brief Accesseur por shapes. */
	const vector<shared_ptr<Drawable>>& getShapes() const;

	/** @brief Retourne l'aire du Drawable. **/
	virtual double Area() const;

	/**	@see Drawable.setColor() */
	void setColor(const shared_ptr<const Color>& couleur);

	/**	@see Drawable.Translate() */
	void Translate(const Vector2D& vecteur);

	/**	@see Drawable.Scale() */
	void Scale(const Vector2D& point, const double ratio);

	/**	@see Drawable.Rotate() */
	void Rotate(const Vector2D& point, const double angle);

	/** @brief Retourne le nom de la classe. */
	string getName() const;

	string* accept(Visitor* v);

	/** @brief Surcharge de l'opérateur +. */
	ShapeGroup& operator+(shared_ptr<Drawable> drawable);

	/** @brief Surcharge de l'opérateur -. */
	ShapeGroup& operator-(shared_ptr<Drawable> drawable);

	/** @brief Surcharge de l'opérateur ==. */
	bool operator==(const shared_ptr<Drawable> shapeGroup) const;

	/** @brief Surcharge de l'opérateur String.*/
	virtual operator string() const;
};