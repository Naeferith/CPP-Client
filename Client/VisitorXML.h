#pragma once

#include "Visitor.h"

/**
	@brief Fonctionnalit� du DP Visieur.

	Cr�e une string en XML d�crivant un Shape.
*/
class VisitorXML : public Visitor {
private:
	/** @brief Retourne un Vector2D au format XML. */
	string strVector(const Vector2D&) const;

	/** @brief Retourne une Color au format XML. */
	string strColor(const Color&) const;

	/** @brief Retourne sous forme XML en ajoutant les param�tres. */
	string* strXML(const Shape* vs, const string& param) const;

	static string makeMarkup(const string& tagName, const double value);

public:
	string* visit(const Shape* vs) const;

	string* visit(const Circle* vs) const;

	string* visit(const shape::Rectangle* vs) const;
};