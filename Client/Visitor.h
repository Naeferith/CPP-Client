#pragma once

#include "Drawable.h"
#include "Shape.h"
#include "Circle.h"

/**
	@brief Classe abstraite du DP Visiteur.
*/
class Visitor {
public:
	virtual void visit(Shape* vs) = 0;
};