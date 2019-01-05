#pragma once

#include "Drawable.h"
#include "Shape.h"
#include "Circle.h"

/**
	@brief Classe abstraite du DP Visiteur.
*/
class Visitor {
public:
	/** @brief Retourne une string qui représente une shape en XML. */
	virtual string* visit(const Shape* vs) const = 0;

	virtual string* visit(const Circle* vs) const = 0;
};