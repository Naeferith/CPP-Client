#pragma once

#include "Visitor.h"
#include "ShapeManager.h"

/**
	@brief Fonctionnalité du DP Visieur.

	Crée une string en XML décrivant un Shape.
*/
class VisitorXML : public Visitor {
private:
	/** @brief Retourne un Vector2D au format XML. */
	string strVector(const Vector2D&) const;

	/** @brief Retourne une Color au format XML. */
	string strColor(const shared_ptr<const Color>&) const;

	/** @brief Retourne sous forme XML en ajoutant les paramètres. */
	string* strXML(const Shape* vs, const string& param) const;

	static string makeMarkup(const string& tagName, const double value);

public:
	string* visit(const Shape* vs) const;

	string* visit(const Circle* vs) const;

	string* visit(const shape::Rectangle* vs) const;

	string* visit(const ShapeGroup* vs) const;

	string* visit(const ShapeManager* vs) const;
};