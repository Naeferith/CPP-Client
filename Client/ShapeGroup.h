#pragma once

#include <memory>
#include <vector>
#include "Drawable.h"

using namespace std;

/**
	@brief Représente un ensemble de Shape.

	Un ShapeGroup est une collection de Drawable.
*/
class ShapeGroup : public Drawable {
private:
	/** @brief La liste des formes. */
	vector<shared_ptr<Drawable>> shapes;

public:
	/** @brief Le constructeur par défaut. */
	ShapeGroup();

	/** @brief Le constructeur par valeurs. */
	ShapeGroup(const vector<shared_ptr<Drawable>>& formes, shared_ptr<const Color>& couleur);

	/** @brief Le destructeur. */
	~ShapeGroup();

	/** @brief Accesseur por shapes. */
	const vector<shared_ptr<Drawable>> getShapes() const;

	/**	@see Drawable.setColor() */
	void setColor(const shared_ptr<const Color>& couleur);

	/** @brief Mutateur pour shapes. */
	void setShapes(const vector<shared_ptr<Drawable>>& formes);

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
	ShapeGroup operator+(Drawable& drawable);

	/** @brief Surcharge de l'opérateur -. */
	ShapeGroup operator-(Drawable& drawable);

	/** @brief Surcharge de l'opérateur ==. */
	bool operator==(const ShapeGroup& shapeGroup) const;
	
	/** @brief Surcharge de l'opérateur =. */
	const ShapeGroup& operator=(const ShapeGroup& shapeGroup);

	/** @brief Surcharge de l'opérateur String.*/
	virtual operator string() const;
};