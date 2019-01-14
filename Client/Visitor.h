#pragma once

#include "Drawable.h"
#include "Circle.h"
#include "Rectangle.h"
<<<<<<< HEAD
=======
#include "ShapeManager.h"
#include "ShapeGroup.h"
>>>>>>> bafa4096d91de08c21b782d05e28f0a16617a716

/**
	@brief Classe abstraite du DP Visiteur.
*/
class Visitor {
protected:

public:
	/** @brief Retourne une string qui représente une shape en XML. */
	virtual string* visit(const Shape* vs) const = 0;

	virtual string* visit(const Circle* vs) const = 0;

	virtual string* visit(const shape::Rectangle* vs) const = 0;
<<<<<<< HEAD
=======

	virtual string* visit(const ShapeGroup* vs) const = 0;

	virtual string* visit(const ShapeManager* vs) const = 0;
>>>>>>> bafa4096d91de08c21b782d05e28f0a16617a716
};