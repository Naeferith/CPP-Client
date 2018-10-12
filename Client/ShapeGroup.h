#pragma once

#include <vector>
#include "Drawable.h"

/**
	@brief Représente un ensemble de Shape.

	Un ShapeGroup est une collection de Drawable.
*/
class ShapeGroup : public Drawable {
private:
	/** @brief La liste des formes. */
	vector<Drawable> shapes;

public:
	/** @brief Le constructeur par défaut. */
	ShapeGroup();

	/** @brief Le constructeur par valeurs. */
	ShapeGroup(const vector<Drawable>& formes, const Color* couleur);

	/** @brief Le destructeur. */
	~ShapeGroup();

	/** @brief Accesseur por shapes. */
	const vector<Drawable> getShapes() const;

	/** @brief Mutateur pour shapes. */
	void setShapes(const vector<Drawable>& formes);

	/** @brief Surcharge de l'opérateur +. */
	ShapeGroup operator+(Drawable& drawable);

	/** @brief Surcharge de l'opérateur -. */
	ShapeGroup operator-(Drawable& drawable);

	/** @brief Surcharge de l'opérateur ==. */
	bool operator==(const ShapeGroup& shapeGroup) const;

	/** @brief Surcharge de l'opérateur =. */
	const ShapeGroup& operator=(const ShapeGroup& shapeGroup);
};