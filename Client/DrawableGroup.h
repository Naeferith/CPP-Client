#pragma once
#include <memory>
#include <vector>
#include "Drawable.h"

using namespace std;

/**
	@brief Représente un ensemble de Drawable.
	
	Un DrawableGroup est une collection de Drawable. 
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

	/** @brief Supprime un élément selon un index
		@param i L'index variant de 0 à size-1. 
	*/
	virtual void Delete(int i);

	/** @brief Supprime l'élément de shapes. 
		@param d Le pionteur sur l'élément à supprimer.
	*/
	virtual void Delete(shared_ptr<Drawable> d);

	/** @brief Ajout d'un Drawable. 
		@param drawable Le Drawable é ajouter.
	*/
	void add(shared_ptr<Drawable> drawable);

	/** @brief Surcharge de l'opérateur ==. */
	bool operator==(const shared_ptr<Drawable> shapeGroup) const;

	/** @brief Surcharge de l'opérateur string. */
	operator string() const;
};
