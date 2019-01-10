#pragma once

#include "Drawable.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangles.h"


/**
	@brief Classe abstraite du DP Visiteur.
*/
class Visitor {
public:
	/** @brief Retourne une string qui repr�sente une shape en XML. */
	virtual string* visit(const Shape* vs) const = 0;

	/** @brief Retourne une string qui repr�sente un circle en XML. */
	virtual string* visit(const Circle* vs) const = 0;

	/** @brief Retourne une string qui repr�sente un rectangles en XML. */
	virtual string* visit(const Rectangles* vs) const = 0;
};