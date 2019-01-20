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
	string  strXML(const Shape* vs, const string& param) const;

	/** @brief Facilite la création d'une balise XML. 
		@param tagName le nom de la balise.
		@param value la valeur à inserer entre la balise.
		@return une string représentant la balise.
	*/
	template<class T>
	static string makeMarkup(const string& tagName, T value) {
		stringstream result;
		result << "<" << tagName << ">" << value << "</" << tagName << ">";
		return result.str(); 
	}

public:

	/** @brief Retourne une string qui représente une shape en XML. */
	string visit(const Shape* vs) const;

	string visit(const Circle* vs) const;

	string visit(const shape::Rectangle* vs) const;

	string visit(const ShapeGroup* vs) const;

	string visit(const ShapeManager* vs) const;
};