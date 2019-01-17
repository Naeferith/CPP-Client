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
	string  strXML(const shared_ptr<Shape> vs, const string& param) const;

	template<class T>
	static string makeMarkup(const string& tagName, T value) {
		stringstream result;
		result << "<" << tagName << ">" << value << "</" << tagName << ">";
		return result.str(); 
	}

public:
	string visit(const shared_ptr<Shape> vs) const;

	string visit(const shared_ptr<Circle> vs) const;

	string visit(const shared_ptr<shape::Rectangle> vs) const;

	string visit(const shared_ptr<ShapeGroup> vs) const;

	string visit(const shared_ptr<ShapeManager> vs) const;
};