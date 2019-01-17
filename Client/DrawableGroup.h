#pragma once
#include <memory>
#include <vector>
#include "Drawable.h"

using namespace std;

/**
	@brief Représente un ensemble de Drawable.
	
	Un Drawable est une collection de Drawable. 
*/
class DrawableGroup {
protected:
	/** @brief La liste des formes. */
	vector<shared_ptr<Drawable>> shapes;

public:
	/** @brief Destructeur de DrawableGroup. */
	virtual ~DrawableGroup();

	/** @brief Accesseur pour shapes. */
	const vector<shared_ptr<Drawable>>& getShapes() const;

	/** @brief Supprime l'élément à l'indice. */
	virtual void Delete(int i);

	/** @brief Surcharge de l'opérateur +. */
	DrawableGroup& operator+(shared_ptr<Drawable> drawable);

	/** @brief Surcharge de l'opérateur -. */
	DrawableGroup& operator-(shared_ptr<Drawable> drawable);

	/** @brief Surcharge de l'opérateur ==. */
	bool operator==(const shared_ptr<Drawable> shapeGroup) const;
};