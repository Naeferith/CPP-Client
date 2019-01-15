#pragma once

#include <iostream>
#include <map>
#include "Vector3D.h"


using namespace std;

/**
	@brief Représente une couleur RGB.

	Une Color a ses composantes comprises entre 0 et 1
*/
class Color : public Vector3D {
private:
	/** @brief Le constructeur par valeurs. */
	Color(const double r, const double g, const double b) : Vector3D(r, g, b) {}

public:
	/** @brief Collection des couleurs par défaut. */
	static const map<string, const Color> colors;

	/** 
		@brief Recherche une couleur par défaut. 
		@param r La composante R.
		@param g La composante G.
		@param b La composante B.
		@return La couleur si trouvée, BLACK(0,0,0) sinon.
	*/
	static const Color retrieveDefaultColor(const double r, const double g, const double b);

	/** @brief Surcharge de l'opérateur String. */
	virtual operator string() const;
};