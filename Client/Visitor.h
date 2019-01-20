#pragma once

#include "Drawable.h"
#include "Circle.h"
#include "Rectangle.h"
#include "ShapeManager.h"
#include "ShapeGroup.h"

/**
	@brief Classe abstraite du DP Visiteur.
*/
class Visitor {
protected:

public:
	/** @brief Retourne une string qui représente une shape en XML. */
	virtual string visit(const Shape* vs) const = 0;

	virtual string visit(const Circle* vs) const = 0;

	virtual string visit(const shape::Rectangle* vs) const = 0;

	virtual string visit(const ShapeGroup* vs) const = 0;

	virtual string visit(const ShapeManager* vs) const = 0;
};